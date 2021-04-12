#include "DXUT.h"
#include "SpeedItemGetEffect.h"

void SpeedItemGetEffect::Init()
{
	image = IMAGE->FindVecImage("SpeedItemGetEffect");

	timer = new CDXUTTimer;
	timer->Start();
}

void SpeedItemGetEffect::Update()
{
	if (timer->GetTime() >= 0.05f)
	{
		aniFrame++;
		timer->Reset();
	}
	if (aniFrame >= 23) isDestroy = true;
}

void SpeedItemGetEffect::Render()
{
	image->FindImage(aniFrame)->CenterRender(vPos);
}

void SpeedItemGetEffect::Release()
{
	SAFE_DELETE(timer);
}
