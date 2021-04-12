#include "DXUT.h"
#include "ClearUi.h"

void ClearUi::Init()
{
	image = IMAGE->FindImage("Clear");
}

void ClearUi::Update()
{
	CAMERA->SetCam({ WINSIZEX / 2, WINSIZEY / 2 });

	if (DXUTWasKeyPressed(VK_RETURN))
	{
		SCENE->ChangeScene("Title");
	}
}

void ClearUi::Render()
{
	image->CenterRender({ WINSIZEX / 2, WINSIZEY / 2 });
	IMAGE->drawText("Score : " + to_string(WORLD->score), { WINSIZEX / 2 - 300, WINSIZEY / 2 - 50 }, 100);
}

void ClearUi::Release()
{
}
