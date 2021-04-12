#include "DXUT.h"
#include "ScoreBoard.h"

void ScoreBoard::Init()
{
	image = IMAGE->FindImage("ScoreBoard");
	hp = OBJECT->player->hp;
}

void ScoreBoard::Update()
{
	CAMERA->SetCam(vPos);
	if (round(SCENE->st->filledPercent) > 0)
	{
		SCENE->st->filledPercent--;
		WORLD->score += 100;
	}
	else if (hp > 0)
	{
		hp--;
		WORLD->score += 1000;
	}
	else
	{
		if (alpha > 0) alpha--;
		else
		{
			SCENE->st->NextStage();
			isDestroy = true;
		}
	}
}

void ScoreBoard::Render()
{
	image->CenterRender(vPos);
	IMAGE->drawText("Score : " + to_string(WORLD->score), { WINSIZEX / 2 - 300, WINSIZEY / 2 - 50 }, 100, D3DCOLOR_RGBA(255, 255, 255, alpha));
}

void ScoreBoard::Release()
{
}
