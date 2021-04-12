#include "DXUT.h"
#include "Stage1Boss.h"
#include "NormalBullet.h"
#include "ReturnBullet.h"
#include "Stage1Explosion.h"
#include "Stage1BossExplosion.h"
#include "ScoreBoard.h"

void Stage1Boss::Init()
{
	image = IMAGE->FindImage("Stage1Boss");

	fireTimer = new CDXUTTimer;
	timer = new CDXUTTimer;
	fireTimer->Start();

	WORLD->enemyNum++;

}

void Stage1Boss::Update()
{
	if (isDead)
	{
		CAMERA->SetCam(vPos);
		CAMERA->CameraShake(1000);

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
			OBJECT->AddObject("Stage1BossExplosion", new Stage1BossExplosion, Vector2(vPos.x + rand() % (200 + 1 + 200) - 200 , vPos.y + rand() % (200 + 1 + 200) - 200), EFFECT);
			OBJECT->AddObject("Stage1BossExplosion", new Stage1BossExplosion, Vector2(vPos.x + rand() % (200 + 1 + 200) - 200 , vPos.y + rand() % (200 + 1 + 200) - 200), EFFECT);
		}
	}
	else
	{
		OBJECT->bossPos = vPos;
		Pattern();
	}
}

void Stage1Boss::Render()
{
	if(!isDead) rot = atan2(OBJECT->player->vPos.y - vPos.y, OBJECT->player->vPos.x - vPos.x);
	image->CenterRender(vPos, rot + 1.6f);
}

void Stage1Boss::Release()
{
	SAFE_DELETE(fireTimer);
	SAFE_DELETE(timer);
	WORLD->enemyNum--;
}

void Stage1Boss::Move()
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

void Stage1Boss::Pattern()
{
	if (round(SCENE->st->filledPercent) < 30)
	{
		if (fireTimer->GetTime() > 2)
		{
			rad = atan2(OBJECT->player->vPos.y - vPos.y, OBJECT->player->vPos.x - vPos.x);

			for (int i = 0; i < 90; i += 30)
			{
				OBJECT->AddObject("Bullet", new ReturnBullet(Vector2(cos(rad), sin(rad) + D3DXToRadian(i)), 900), vPos, EBULLET);
				OBJECT->AddObject("Bullet", new ReturnBullet(Vector2(cos(rad), sin(rad) - D3DXToRadian(i)), 900), vPos, EBULLET);
			}

			fireTimer->Reset();
		}

	}
	else if (round(SCENE->st->filledPercent) < 50)
	{
		Move();

		if (fireTimer->GetTime() > 0.3f)
		{
			rad += 90;

			for (int i = 0; i < 90; i += 30)
			{
				OBJECT->AddObject("Bullet", new ReturnBullet(Vector2(cos(rad), sin(rad) + D3DXToRadian(i)), 900), vPos, EBULLET);
				OBJECT->AddObject("Bullet", new ReturnBullet(Vector2(cos(rad), sin(rad) - D3DXToRadian(i)), 900), vPos, EBULLET);
			}

			fireTimer->Reset();
		}
	}
	else if (round(SCENE->st->filledPercent) < 80)
	{
		if (speed == 12) speed = 16;

		if (fireTimer->GetTime() > 3)
		{
			rad = atan2(OBJECT->player->vPos.y - vPos.y, OBJECT->player->vPos.x - vPos.x);
			OBJECT->AddObject("Bullet", new NormalBullet(Vector2(cos(rad), sin(rad))), vPos, EBULLET);
			OBJECT->AddObject("Bullet", new NormalBullet(Vector2(cos(rad) + D3DXToRadian(rand() % 40) , sin(rad) + D3DXToRadian(rand() % 40))), vPos, EBULLET);
			OBJECT->AddObject("Bullet", new NormalBullet(Vector2(cos(rad) - D3DXToRadian(rand() % 40), sin(rad) - D3DXToRadian(rand() % 40))), vPos, EBULLET);

			if (fireTimer->GetTime() > 5)
				fireTimer->Reset();
		}
		else
			Move();
	}
	else
	{
		isDead = true;
		fireTimer->Stop();
		timer->Start();
	}
}
