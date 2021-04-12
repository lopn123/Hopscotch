#include "DXUT.h"
#include "Hp.h"

void Hp::Init()
{
	image = IMAGE->FindImage("HpItem");
}

void Hp::Update()
{
	vPos.x = CAMERA->camPos.x - WINSIZEX / 2 + 50;
	vPos.y = CAMERA->camPos.y - WINSIZEY / 2 + 100;
}

void Hp::Render()
{
	for (int i = 0; i < OBJECT->player->hp; i++)
	{
		image->CenterRender({ vPos.x + i * 60, vPos.y });
	}
}

void Hp::Release()
{
}
