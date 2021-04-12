#include "DXUT.h"
#include "Title.h"

void Title::Init()
{
	CAMERA->Reset();

	background = IMAGE->FindImage("Title");
	black = IMAGE->FindImage("black");

	start = IMAGE->FindImage("GameStart");
	how = IMAGE->FindImage("HowTo");
	exit = IMAGE->FindImage("Exit");
	startOn = IMAGE->FindImage("GameStartOn");
	howOn = IMAGE->FindImage("HowToOn");
	exitOn = IMAGE->FindImage("ExitOn");
	guide = IMAGE->FindImage("Guide");

	sel = 1;
}

void Title::Update()
{
	if (alpha < 255) alpha++;
	else
	{
		if (!isGuideWindow)
		{
			if (DXUTWasKeyPressed(VK_UP))
			{
				if (sel == 1) sel = 3;
				else sel--;
			}
			else if (DXUTWasKeyPressed(VK_DOWN))
			{
				if (sel == 3) sel = 1;
				else sel++;
			}
			else if (DXUTWasKeyPressed(VK_SPACE))
			{
				switch (sel)
				{
				case 1:
					SCENE->ChangeScene("Stage");
					break;
				case 2:
					isGuideWindow = true;
					break;
				case 3:
					PostQuitMessage(0);
				}
			}
		}
		else
		{
			if (DXUTWasKeyPressed(VK_SPACE))
			{
				isGuideWindow = false;
			}
		}
	}

}

void Title::Render()
{
	black->CenterRender({ WINSIZEX / 2, WINSIZEY / 2 });
	background->CenterRender({ WINSIZEX / 2,WINSIZEY / 2 }, 0, { 1,1 }, D3DCOLOR_RGBA(255, 255, 255, alpha));

	if (alpha == 255)
	{
		UiSelect();
		if (isGuideWindow) guide->CenterRender({ WINSIZEX / 2, WINSIZEY / 2 });
	}
}

void Title::Release()
{
}

void Title::UiSelect()
{
	switch (sel)
	{
	case 1:
		startOn->CenterRender({ WINSIZEX - 250 , WINSIZEY - 300 });
		how->CenterRender({ WINSIZEX - 250 , WINSIZEY - 200 });
		exit->CenterRender({ WINSIZEX - 250 , WINSIZEY - 100 });
		break;
	case 2:
		start->CenterRender({ WINSIZEX - 250 , WINSIZEY - 300 });
		howOn->CenterRender({ WINSIZEX - 250 , WINSIZEY - 200 });
		exit->CenterRender({ WINSIZEX - 250 , WINSIZEY - 100 });
		break;
	case 3:
		start->CenterRender({ WINSIZEX - 250 , WINSIZEY - 300 });
		how->CenterRender({ WINSIZEX - 250 , WINSIZEY - 200 });
		exitOn->CenterRender({ WINSIZEX - 250 , WINSIZEY - 100 });
	}
}