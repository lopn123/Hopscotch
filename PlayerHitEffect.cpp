#include "DXUT.h"
#include "PlayerHitEffect.h"

void PlayerHitEffect::Init()
{
	image = IMAGE->FindImage("HpItem");

	timer = new CDXUTTimer;
	timer->Start();
}

void PlayerHitEffect::Update()
{
	vPos.y -= 1.f;
	if (timer->GetTime() > 3) isDestroy = true;
}

void PlayerHitEffect::Render()
{
	image->CenterRender(vPos, 0, { 1,1 }, D3DCOLOR_RGBA(255, 255, 255, 100));
}

void PlayerHitEffect::Release()
{
	SAFE_DELETE(timer);
}
