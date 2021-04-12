#include "DXUT.h"
#include "PlayerHit.h"

void PlayerHit::Init()
{
	image = IMAGE->FindImage("PlayerHit");

	timer = new CDXUTTimer;
	timer->Start();
}

void PlayerHit::Update()
{
	vPos.y-= 0.1f;
	if (timer->GetTime() > 3) isDestroy = true;
}

void PlayerHit::Render()
{
	image->CenterRender(vPos);
}

void PlayerHit::Release()
{
	SAFE_DELETE(timer);
}
