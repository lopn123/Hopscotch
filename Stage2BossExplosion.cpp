#include "DXUT.h"
#include "Stage2BossExplosion.h"

void Stage2BossExplosion::Init()
{
	int random = rand() % 2;
	if(random == 0)
		image = IMAGE->FindVecImage("Stage2BossExplosion");
	else
		image = IMAGE->FindVecImage("Stage2BossExplosion2");

	timer = new CDXUTTimer;
	timer->Start();
}

void Stage2BossExplosion::Update()
{
	if (timer->GetTime() >= 0.05f)
	{
		aniFrame++;
		timer->Reset();
	}
	if (aniFrame >= 31) isDestroy = true;
}

void Stage2BossExplosion::Render()
{
	image->FindImage(aniFrame)->CenterRender(vPos);
}

void Stage2BossExplosion::Release()
{
	SAFE_DELETE(timer);
}
