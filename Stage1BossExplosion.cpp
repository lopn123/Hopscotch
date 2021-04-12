#include "DXUT.h"
#include "Stage1BossExplosion.h"

void Stage1BossExplosion::Init()
{
	image = IMAGE->FindVecImage("Stage1BossExplosion");

	timer = new CDXUTTimer;
	timer->Start();
}

void Stage1BossExplosion::Update()
{
	if (timer->GetTime() >= 0.05f)
	{
		aniFrame++;
		timer->Reset();
	}
	if (aniFrame >= 23) isDestroy = true;
}

void Stage1BossExplosion::Render()
{
	image->FindImage(aniFrame)->CenterRender(vPos);
}

void Stage1BossExplosion::Release()
{
	SAFE_DELETE(timer);
}
