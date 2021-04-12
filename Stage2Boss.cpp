#include "DXUT.h"
#include "Stage2Boss.h"
#include "NormalBullet.h"
#include "StopBullet.h"
#include "Stage1Explosion.h"
#include "Stage2BossExplosion.h"
#include "ScoreBoard.h"
#include "ExplosionBullet.h"

void Stage2Boss::Init()
{
	image = IMAGE->FindImage("Stage2Boss");

	timer = new CDXUTTimer;
	fireTimer = new CDXUTTimer;
	fireTimer2 = new CDXUTTimer;
	fireTimer->Start();
	WORLD->enemyNum++;
}

void Stage2Boss::Update()
{
	if (isDead)
	{
		CAMERA->SetCam(vPos);
		CAMERA->CameraShake(2000);

		if (timer->GetTime() >= 5)
		{
			if (alpha > 0)
			{
				alpha -= 5;
			}
			else
			{
				OBJECT->player->maxHp++;
				OBJECT->player->maxMove++;
				OBJECT->AddObject("ScoreBoard", new ScoreBoard, { WINSIZEX / 2, WINSIZEY / 2 }, UI);
				isDestroy = true;
			}
		}
		else
		{
			OBJECT->AddObject("Stage1Explosion", new Stage1Explosion, Vector2(rand() % WINSIZEX, rand() % WINSIZEY), EFFECT);
			OBJECT->AddObject("Stage1BossExplosion", new Stage2BossExplosion, Vector2(vPos.x + rand() % (200 + 1 + 200) - 200, vPos.y + rand() % (200 + 1 + 200) - 200), EFFECT);
			OBJECT->AddObject("Stage1BossExplosion", new Stage2BossExplosion, Vector2(vPos.x + rand() % (200 + 1 + 200) - 200, vPos.y + rand() % (200 + 1 + 200) - 200), EFFECT);
		}
	}
	else
	{
		OBJECT->bossPos = vPos;
		Pattern();
	}
}

void Stage2Boss::Render()
{
	image->CenterRender(vPos, rot);
}

void Stage2Boss::Release()
{
	SAFE_DELETE(fireTimer);
	WORLD->enemyNum--;
}

void Stage2Boss::Move()
{
	if (vPos.x + speed * dir.x < 0 || vPos.x + speed * dir.x > WINSIZEX
		|| WORLD->map[(int)vPos.y][int(vPos.x + speed * dir.x)] == 1 || WORLD->map[(int)vPos.y][int(vPos.x + speed * dir.x)] == 3
		|| WORLD->map[(int)vPos.y][int(vPos.x + speed * dir.x)] == 4)
	{
		dir.x *= -1;
	}
	if (vPos.y + speed * dir.y < 0 || vPos.y + speed * dir.y >= WINSIZEY
		|| WORLD->map[int(vPos.y + speed * dir.y)][int(vPos.x)] == 1 || WORLD->map[int(vPos.y + speed * dir.y)][int(vPos.x)] == 3
		|| WORLD->map[int(vPos.y + speed * dir.y)][int(vPos.x)] == 4)
	{
		dir.y *= -1;
	}
	float distance;
	distance = sqrt(pow(OBJECT->player->vPos.x - vPos.x, 2) + pow(OBJECT->player->vPos.y - vPos.y, 2));

	if (distance < 50 && OBJECT->player->isOut && !OBJECT->player->invincible)
	{
		SCENE->st->PlayerHit();
	}

	vPos.x += speed * dir.x;
	vPos.y += speed * dir.y;
}

void Stage2Boss::Pattern()
{
	if (round(SCENE->st->filledPercent) < 30)
	{
		rot += 0.05f;

		if (fireTimer->GetTime() >= 3)
		{
			if (fireTimer2->IsStopped()) fireTimer2->Start();

			if (fireTimer2->GetTime() >= 1)
			{
				for (rad = 0; rad < 360; rad += 5)
				{
					OBJECT->AddObject("Bullet", new StopBullet(Vector2(cos(rad), sin(rad))), vPos, EBULLET);
				}
				count++;
				fireTimer2->Reset();
			}

			if (count == 3)
			{
				count = 0;
				fireTimer2->Stop();
				fireTimer->Reset();
			}
		}
		if (count == 0) Move(); 
	}
	else if (round(SCENE->st->filledPercent) < 60)
	{
		rot += 0.05f;

		if (fireTimer->GetTime() >= 2)
		{
			rot += 0.2f;

			rad++;
			OBJECT->AddObject("Bullet", new NormalBullet(Vector2(cos(rad), sin(rad))), vPos, EBULLET);
			OBJECT->AddObject("Bullet", new NormalBullet(Vector2(cos(rad + 90), sin(rad + 90))), vPos, EBULLET);
			OBJECT->AddObject("Bullet", new NormalBullet(Vector2(cos(rad + 180), sin(rad + 180))), vPos, EBULLET);
			OBJECT->AddObject("Bullet", new NormalBullet(Vector2(cos(rad + 270), sin(rad + 270))), vPos, EBULLET);

			if (fireTimer->GetTime() >= 5)
				fireTimer->Reset();
		}
		else
			Move();
	
	}
	else if (round(SCENE->st->filledPercent) < 80)
	{
		if (speed == 8) speed = 14;

		rot += 0.6;

		if (fireTimer->GetTime() >= 5)
		{
			if (fireTimer->GetTime() < 7.5f)
			{
				rot += 1;
				OBJECT->AddObject("Bullet", new ExplosionBullet(Vector2(cos(rand() % 360), sin(rand() % 360))), vPos, EBULLET);
			}
			else
			{
				fireTimer->Reset();
			}
		}
		else
		{
			Move();
		}

	}
	else
	{
		isDead = true;
		timer->Start();
		fireTimer->Stop();
		fireTimer2->Stop();
	}
}
