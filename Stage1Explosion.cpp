#include "DXUT.h"
#include "Stage1Explosion.h"

void Stage1Explosion::Init()
{
	image = IMAGE->FindVecImage("Stage1Explosion");

	timer = new CDXUTTimer;
	timer->Start();
}

void Stage1Explosion::Update()
{
	if (timer->GetTime() >= 0.05f)
	{
		aniFrame++;
		timer->Reset();
	}
	if (aniFrame >= 22) isDestroy = true;
}

void Stage1Explosion::Render()
{
	image->FindImage(aniFrame)->CenterRender(vPos);
}

void Stage1Explosion::Release()
{
	SAFE_DELETE(timer);
}
