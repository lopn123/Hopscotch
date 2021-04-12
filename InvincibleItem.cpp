#include "DXUT.h"
#include "invincibleItem.h"
#include "InvinItemGetEffect.h"

void invincibleItem::Init()
{
	image = IMAGE->FindImage("InvinItem");
}

void invincibleItem::Update()
{
	if (alpha < 255) alpha += 3;

	if (WORLD->map[(int)vPos.y][(int)vPos.x] == 1 || WORLD->map[(int)vPos.y][(int)vPos.x] == 3)
	{
		OBJECT->player->GetItem(this);
		OBJECT->AddObject("Effect", new InvinItemGetEffect, vPos, EFFECT);
		isDestroy = true;
	}
}

void invincibleItem::Render()
{
	image->CenterRender(vPos, 0, { 1,1 }, D3DCOLOR_RGBA(255, 255, 255, alpha));
}

void invincibleItem::Release()
{
}
