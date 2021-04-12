#include "DXUT.h"
#include "FlashEffect.h"

void FlashEffect::Init()
{
	image = IMAGE->FindVecImage("FlashEffect");

	timer = new CDXUTTimer;
	timer->Start();

	aniFrame = 0;
}

void FlashEffect::Update()
{
	if (timer->GetTime() >= 0.01f)
	{
		aniFrame++;
		timer->Reset();
	}
	if (aniFrame >= 29) isDestroy = true;
}

void FlashEffect::Render()
{
	image->FindImage(aniFrame)->CenterRender(vPos);
}

void FlashEffect::Release()
{
	SAFE_DELETE(timer);
}
