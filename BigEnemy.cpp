#include "DXUT.h"
#include "BigEnemy.h"
#include "NormalBullet.h"
#include "EnemyDeadEffect.h"

void BigEnemy::Init()
{
	image = IMAGE->FindImage("BigEnemy");

	WORLD->enemyNum++;
}

void BigEnemy::Update()
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

void BigEnemy::Render()
{
	rot = atan2(dir.x, dir.y);
	image->CenterRender(vPos, rot, { 1,1 }, D3DCOLOR_RGBA(255, 255, 255, alpha));
}

void BigEnemy::Release()
{
	WORLD->enemyNum--;
}

void BigEnemy::Move()
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