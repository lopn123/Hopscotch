#include "DXUT.h"
#include "FlashEnemy.h"
#include "NormalBullet.h"
#include "EnemyDeadEffect.h"
#include "FlashEffect.h"

void FlashEnemy::Init()
{
	image = IMAGE->FindImage("FlashEnemy");
	WORLD->enemyNum++;

}

void FlashEnemy::Update()
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

void FlashEnemy::Render()
{
	image->CenterRender(vPos);
}

void FlashEnemy::Release()
{
	WORLD->enemyNum--;
}

void FlashEnemy::Move()
{
	if (vPos.x + speed * dir.x < 0 || vPos.x + speed * dir.x > WINSIZEX
		|| WORLD->map[(int)vPos.y][int(vPos.x + speed * dir.x)] == 1 || WORLD->map[(int)vPos.y][int(vPos.x + speed * dir.x)] == 3
		|| WORLD->map[(int)vPos.y][int(vPos.x + speed * dir.x)] == 4)
	{
		dir.x *= -1;
		vPos.x += speed * 60 * dir.x;
		OBJECT->AddObject("FlashEffect", new FlashEffect, vPos, EFFECT);
	}
	if (vPos.y + speed * dir.y < 0 || vPos.y + speed * dir.y >= WINSIZEY
		|| WORLD->map[int(vPos.y + speed * dir.y)][int(vPos.x)] == 1 || WORLD->map[int(vPos.y + speed * dir.y)][int(vPos.x)] == 3
		|| WORLD->map[int(vPos.y + speed * dir.y)][int(vPos.x)] == 4)
	{
		dir.y *= -1;
		vPos.y += speed * 60 * dir.y;
		OBJECT->AddObject("FlashEffect", new FlashEffect, vPos, EFFECT);
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