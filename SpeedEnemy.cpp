#include "DXUT.h"
#include "SpeedEnemy.h"
#include "NormalBullet.h"
#include "EnemyAfterImage.h"
#include "EnemyDeadEffect.h"

void SpeedEnemy::Init()
{
	image = IMAGE->FindImage("SpeedEnemy");

	WORLD->enemyNum++;
}

void SpeedEnemy::Update()
{
	if (isDead)
	{
		if (alpha > 0)
		{
			alpha -= 3;
		}
		else
		{
			OBJECT->player->maxHp++;
			OBJECT->player->maxMove++;
			isDestroy = true;
		}
	}
	else
	{
		if (WORLD->map[int(vPos.y)][int(vPos.x)] == 1 || WORLD->map[int(vPos.y)][int(vPos.x)] == 3 || round(SCENE->st->filledPercent) >= 80)
		{
			isDead = true;
			OBJECT->AddObject("EnemyDeadEffect", new EnemyDeadEffect, vPos, EFFECT);
		}

		Move();
	}
}

void SpeedEnemy::Render()
{
	rot = atan2(dir.x, dir.y);
	image->CenterRender(vPos, rot);
}

void SpeedEnemy::Release()
{
	WORLD->enemyNum--;
}

void SpeedEnemy::Move()
{
	if (vPos.x + speed * dir.x < 0 || vPos.x + speed * dir.x > WINSIZEX
		|| WORLD->map[(int)vPos.y][int(vPos.x + speed * dir.x)] == 1 || WORLD->map[(int)vPos.y][int(vPos.x + speed * dir.x)] == 3
		|| WORLD->map[(int)vPos.y][int(vPos.x + speed * dir.x)] == 4)
	{
		dir.x *= -1;
		if (speed < 15) speed += dir.x;
	}
	if (vPos.y + speed * dir.y < 0 || vPos.y + speed * dir.y >= WINSIZEY
		|| WORLD->map[int(vPos.y + speed * dir.y)][int(vPos.x)] == 1 || WORLD->map[int(vPos.y + speed * dir.y)][int(vPos.x)] == 3
		|| WORLD->map[int(vPos.y + speed * dir.y)][int(vPos.x)] == 4)
	{
		dir.y *= -1;
		if (speed < 15) speed += dir.y;
	}

	float distance;
	distance = sqrt(pow(OBJECT->player->vPos.x - vPos.x, 2) + pow(OBJECT->player->vPos.y - vPos.y, 2));

	if (distance < 50 && OBJECT->player->isOut && !OBJECT->player->invincible)
	{
		SCENE->st->PlayerHit();
	}

	if (speed >= 12)
	{
		OBJECT->AddObject("EnemyAfterImage", new EnemyAfterImage, vPos, EFFECT);

		if (speed >= 15)
		{
			for (int i = 0; i < 15; i++)
			{
				rad = rand() % 360;
				OBJECT->AddObject("NormalBullet", new NormalBullet(Vector2(cos(D3DXToRadian(rad)), sin(D3DXToRadian(rad))), rand() % (1400 + 1 - 600) + 600), vPos, EBULLET);
			}
			speed = 10 * dir.x;
		}
	}
	
	vPos.x += speed * dir.x;
	vPos.y += speed * dir.y;
}