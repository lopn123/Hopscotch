#include "DXUT.h"
#include "Stage.h"
#include "Player.h"
#include "SpeedEnemy.h"
#include "FlashEnemy.h"
#include "BigEnemy.h"
#include "TpEnemy.h"
#include "Stage1Boss.h"
#include "Stage2Boss.h"
#include "HpItem.h"
#include "InvincibleItem.h"
#include "SpeedItem.h"
#include "Hp.h"
#include "PlayerHitEffect.h"
#include "ClearUi.h"

void Stage::Init()
{
	SCENE->st = this;
	WORLD->score = 0;
	st = 1;

	stage = IMAGE->FindImage("stage");
	stage2 = IMAGE->FindImage("stage2");
	black = IMAGE->FindImage("black");
	bigBlack = IMAGE->FindImage("bigBlack");

	MapStartSetting();
	
	int random = rand() % 2;
	int x;
	if (random == 0)
		x = 0;
	else
		x = WINSIZEX - 1;

	OBJECT->AddObject("Player", new Player, Vector2(x, rand() % WINSIZEY) , PLAYER);

	OBJECT->AddObject("HpBar", new Hp, Vector2(50, 100), UI);

	OBJECT->AddObject("Stage1Boss", new Stage1Boss, { WINSIZEX / 2, WINSIZEY / 2 }, ENEMY);
	OBJECT->AddObject("Enemy", new BigEnemy, Vector2(rand() % WINSIZEX + 1, rand() % WINSIZEY + 1), ENEMY);
	OBJECT->AddObject("Enemy", new TpEnemy, Vector2( rand()% WINSIZEX + 1, rand()% WINSIZEY + 1 ), ENEMY);
	OBJECT->AddObject("Enemy", new TpEnemy, Vector2( rand()% WINSIZEX + 1, rand()% WINSIZEY + 1 ), ENEMY);
	OBJECT->AddObject("Enemy", new TpEnemy, Vector2( rand()% WINSIZEX + 1, rand()% WINSIZEY + 1 ), ENEMY);
	OBJECT->AddObject("Enemy", new SpeedEnemy, Vector2(rand() % WINSIZEX + 1, rand() % WINSIZEY + 1), ENEMY);
	OBJECT->AddObject("Enemy", new SpeedEnemy, Vector2(rand() % WINSIZEX + 1, rand() % WINSIZEY + 1), ENEMY);
}

void Stage::Update()
{
}

void Stage::Render()
{
	bigBlack->CenterRender({ WINSIZEX / 2,WINSIZEY / 2 });
	if (st == 1) stage->CenterRender({ WINSIZEX / 2,WINSIZEY / 2 });
	else if (st == 2) stage2->CenterRender({ WINSIZEX / 2, WINSIZEY / 2 });
	black->CenterRender({ WINSIZEX / 2,WINSIZEY / 2 });

	IMAGE->drawText(to_string((int)round(filledPercent)) + "%", Vector2(CAMERA->camPos.x + WINSIZEX / 2 - 250, CAMERA->camPos.y - WINSIZEY / 2 + 50));
	IMAGE->drawText("Enemy : " + to_string(WORLD->enemyNum), Vector2(CAMERA->camPos.x + WINSIZEX / 2 - 250, CAMERA->camPos.y - WINSIZEY / 2 + 150));
}

void Stage::Release()
{
	SCENE->st = nullptr;
}

void Stage::Fill(int x, int y, int r, int g, int b, int a)
{
	black->texturePtr->LockRect(0, &lr, 0, 0);

	DWORD* textureColor = (DWORD*)lr.pBits;
	int index = y * WINSIZEX + x;
	D3DXCOLOR targetPixel = textureColor[index];
	targetPixel.r = r;
	targetPixel.g = g;
	targetPixel.b = b;
	targetPixel.a = a;
	textureColor[index] = targetPixel;

	black->texturePtr->UnlockRect(0);
}

void Stage::PlayerInBorder()
{
	FloodFill(OBJECT->bossPos.x, OBJECT->bossPos.y);
	ChangeTile();
	FillPercent();

	int random = rand() % 12;
	switch (random)
	{
	case 0:
		OBJECT->AddObject("SpeedItem", new SpeedItem, Vector2(rand() % WINSIZEX, rand() % WINSIZEY), ITEM);
		break;
	case 5:
		OBJECT->AddObject("HpItem", new HpItem, Vector2(rand() % WINSIZEX, rand() % WINSIZEY), ITEM);
		break;
	case 9:
		OBJECT->AddObject("InvincibleItem", new invincibleItem, Vector2(rand() % WINSIZEX, rand() % WINSIZEY), ITEM);
		break;
	}
}

void Stage::PlayerHit()
{
	if (!OBJECT->player->invincible)
	{
		for (int i = 0; i < WINSIZEY; i++)
		{
			for (int j = 0; j < WINSIZEX; j++)
			{
				if (WORLD->map[i][j] == 5)
				{
					WORLD->map[i][j] = 0;
					Fill(j, i, 0, 0, 0, 255);
				}
			}
		}

		OBJECT->player->hp--;
		OBJECT->player->vPos = OBJECT->player->prevPos;
		OBJECT->AddObject("PlayerHitEffect", new PlayerHitEffect, OBJECT->player->vPos, EFFECT);
	}
}

void Stage::NextStage()
{
	if (st == 1)
	{
		OBJECT->ClearAllObject();
		MapStartSetting();
		OBJECT->player->vPos = { 0,0 };
		OBJECT->player->PInit();
		OBJECT->player->maxHp = 12;

		OBJECT->AddObject("HpBar", new Hp, Vector2(50, 100), UI);

		OBJECT->AddObject("Enemy", new FlashEnemy, Vector2(rand() % WINSIZEX + 1, rand() % WINSIZEY + 1), ENEMY);
		OBJECT->AddObject("Enemy", new FlashEnemy, Vector2(rand() % WINSIZEX + 1, rand() % WINSIZEY + 1), ENEMY);
		OBJECT->AddObject("Enemy", new FlashEnemy, Vector2(rand() % WINSIZEX + 1, rand() % WINSIZEY + 1), ENEMY); 
		OBJECT->AddObject("Stage2Boss", new Stage2Boss, { WINSIZEX / 2, WINSIZEY / 2 }, ENEMY);
		
		CAMERA->camPos = { WINSIZEX / 2, WINSIZEY / 2 };
		CAMERA->viewSize = { 50, 50 };
		OBJECT->player->cam = true;

		st++;
	}
	else if (st == 2)
	{
		OBJECT->ClearAllObject();
		OBJECT->player->isDestroy = true;
		OBJECT->AddObject("Cu", new ClearUi, { WINSIZEX / 2, WINSIZEY / 2 }, UI);
	}
}

void Stage::MapStartSetting()
{
	for (int i = 0; i < WINSIZEY; i++)
	{
		for (int j = 0; j < WINSIZEX; j++)
		{
			if (i == 0 || i == WINSIZEY - 1)
			{
				WORLD->map[i][j] = 4;
				Fill(j, i, 255, 255, 255, 255);
			}
			else if (j == 0 || j == WINSIZEX - 1)
			{
				WORLD->map[i][j] = 4;
				Fill(j, i, 255, 255, 255, 255);
			}
			else
			{
				WORLD->map[i][j] = 0;
				Fill(j, i, 0, 0, 0, 255);
			}
		}
	}
}

void Stage::FloodFill(int x, int y)
{
	if (WORLD->map[y][x] == 0)
	{
		WORLD->map[y][x] = 2;

		FloodFill(x + 1, y);
		FloodFill(x - 1, y);
		FloodFill(x, y + 1);
		FloodFill(x, y - 1);
	}
}

void Stage::FillPercent()
{
	count = 0;

	for (int i = 0; i < WINSIZEY; i++)
	{
		for (int j = 0; j < WINSIZEX; j++)
		{
			if (WORLD->map[i][j] == 1 || WORLD->map[i][j] == 3 || WORLD->map[i][j] == 5)
			{
				count++;
			}
			else if (WORLD->map[i][j] == 6)
			{

			}
		}
	}

	filledPercent = 100 / ((float)WINSIZEX * (float)WINSIZEY) * count;
}

void Stage::ChangeTile()
{
	for (int i = 0; i < WINSIZEY; i++)
	{
		for (int j = 0; j < WINSIZEX; j++)
		{
			if (WORLD->map[i][j] == 0)
			{
				WORLD->map[i][j] = 1;
				Fill(j, i, 0, 0, 0, 0);
			}
			else if (WORLD->map[i][j] == 2)
			{
				WORLD->map[i][j] = 0;
			}
			else if (WORLD->map[i][j] == 5)
			{
				WORLD->map[i][j] = 1;
				Fill(j, i, 0, 0, 0, 0);
			}
		}
	}
}