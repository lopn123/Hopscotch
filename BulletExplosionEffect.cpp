#include "DXUT.h"
#include "BulletExplosionEffect.h"

void BulletExplosionEffect::Init()
{
	image = IMAGE->FindVecImage("BulletExplosionEffect");

	timer = new CDXUTTimer;
	timer->Start();
	aniFrame = 0;
}

void BulletExplosionEffect::Update()
{
	if (timer->GetTime() >= 0.05f)
	{
		aniFrame++;
		timer->Reset();
	}
	if (aniFrame >= 23) isDestroy = true;
}

void BulletExplosionEffect::Render()
{
	image->FindImage(aniFrame)->CenterRender(vPos);
}

void BulletExplosionEffect::Release()
{
	SAFE_DELETE(timer);
}
