#include "DXUT.h"
#include "PlayerDeadUi.h"

void PlayerDeadUi::Init()
{
	image = IMAGE->FindImage("GameOver");
}

void PlayerDeadUi::Update()
{
	CAMERA->SetCam({ WINSIZEX / 2, WINSIZEY / 2 });
	if (DXUTWasKeyPressed(VK_SPACE))
	{
		OBJECT->player->hp = OBJECT->player->maxHp;
		isDestroy = true;
	}
	else if (DXUTWasKeyPressed(VK_RETURN))
	{
		OBJECT->player->isDestroy = true;
		SCENE->ChangeScene("Title");
	}
}

void PlayerDeadUi::Render()
{
	image->CenterRender({ WINSIZEX / 2, WINSIZEY / 2 });
}

void PlayerDeadUi::Release()
{
}
