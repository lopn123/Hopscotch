#include "DXUT.h"
#include "InvinItemGetEffect.h"

void InvinItemGetEffect::Init()
{
	image = IMAGE->FindVecImage("InvinItemGetEffect");

	timer = new CDXUTTimer;
	timer->Start();
}

void InvinItemGetEffect::Update()
{
	if (timer->GetTime() >= 0.05f)
	{
		aniFrame++;
		timer->Reset();
	}
	if (aniFrame >= 23) isDestroy = true;
}

void InvinItemGetEffect::Render()
{
	image->FindImage(aniFrame)->CenterRender(vPos);
}

void InvinItemGetEffect::Release()
{
	SAFE_DELETE(timer);
}
