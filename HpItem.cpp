#include "DXUT.h"
#include "HpItem.h"
#include "HpItemGetEffect.h"

void HpItem::Init()
{
	image = IMAGE->FindImage("HpItem");
}

void HpItem::Update()
{
	if (alpha < 255) alpha += 3;

	if (WORLD->map[(int)vPos.y][(int)vPos.x] == 1 || WORLD->map[(int)vPos.y][(int)vPos.x] == 3)
	{
		OBJECT->player->GetItem(this);
		OBJECT->AddObject("Effect", new HpItemGetEffect, vPos, EFFECT);
		isDestroy = true;
	}
}

void HpItem::Render()
{
	image->CenterRender(vPos, 0, { 1,1 }, D3DCOLOR_RGBA(255, 255, 255, alpha));
}

void HpItem::Release()
{
}
