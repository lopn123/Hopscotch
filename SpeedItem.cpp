#include "DXUT.h"
#include "SpeedItem.h"
#include "SpeedItemGetEffect.h"

void SpeedItem::Init()
{
	image = IMAGE->FindImage("SpeedItem");
}

void SpeedItem::Update()
{
	if (alpha < 255) alpha += 3;

	if (WORLD->map[(int)vPos.y][(int)vPos.x] == 1 || WORLD->map[(int)vPos.y][(int)vPos.x] == 3)
	{
		OBJECT->player->GetItem(this);
		OBJECT->AddObject("Effect", new SpeedItemGetEffect, vPos, EFFECT);
		isDestroy = true;
	}
}

void SpeedItem::Render()
{
	image->CenterRender(vPos, 0, { 1,1 }, D3DCOLOR_RGBA(255, 255, 255, alpha));
}

void SpeedItem::Release()
{
}
