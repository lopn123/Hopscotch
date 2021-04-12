#include "DXUT.h"
#include "TpEnemy.h"
#include "NormalBullet.h"
#include "EnemyDeadEffect.h"
#include "TpEffect.h"

void TpEnemy::Init()
{
	image = IMAGE->FindImage("TpEnemy");

	timer = new CDXUTTimer;
	timer->Start();
	WORLD->enemyNum++;
}

void TpEnemy::Update()
{
	if (!chk)
	{
		chk = true;
		startPos = vPos;
	}

	if (isDead)
	{
		if (alpha > 0)
		{
			alpha-= 3;
			color = D3DCOLOR_RGBA(255, 255, 255, alpha);
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

		float distance;
		distance = sqrt(pow(OBJECT->player->vPos.x - vPos.x, 2) + pow(OBJECT->player->vPos.y - vPos.y, 2));

		if (distance < 50 && OBJECT->player->isOut && !OBJECT->player->invincible)
		{
			SCENE->st->PlayerHit();
		}

		if (timer->GetTime() >= 1)
		{
			count++;
			timer->Reset();
		}

		switch (count)
		{
		case 0:
			color = D3DCOLOR_XRGB(255, 255, 255);
			vPos = startPos;
			break;
		case 1:
			color = D3DCOLOR_XRGB(255, 255, 0);
			break;
		case 2:
			color = D3DCOLOR_XRGB(255, 128, 0);
			break;
		case 3:
			color = D3DCOLOR_XRGB(255, 0, 0);
			OBJECT->AddObject("TpEffect", new TpEffect, vPos, EFFECT);
			break;
		case 4:
			if (OBJECT->player->isOut)
			{
				vPos = OBJECT->player->vPos;
			}
			break;
		case 5:
			count = 0;
			break;
		}
	}
}

void TpEnemy::Render()
{
	image->CenterRender(vPos, 0, { 1,1 }, color);
}

void TpEnemy::Release()
{
	SAFE_DELETE(timer);
	WORLD->enemyNum--;
}