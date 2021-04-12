#include "DXUT.h"
#include "HpItemGetEffect.h"

void HpItemGetEffect::Init()
{
	image = IMAGE->FindVecImage("HpItemGetEffect");

	timer = new CDXUTTimer;
	timer->Start();
}

void HpItemGetEffect::Update()
{
	if (timer->GetTime() >= 0.05f)
	{
		aniFrame++;
		timer->Reset();
	}
	if (aniFrame >= 23) isDestroy = true;
}

void HpItemGetEffect::Render()
{
	image->FindImage(aniFrame)->CenterRender(vPos);
}

void HpItemGetEffect::Release()
{
	SAFE_DELETE(timer);
}
