#include "DXUT.h"
#include "EnemyDeadEffect.h"

void EnemyDeadEffect::Init()
{
	image = IMAGE->FindVecImage("EnemyDeadEffect");

	timer = new CDXUTTimer;
	timer->Start();

	aniFrame = 0;

}

void EnemyDeadEffect::Update()
{
	if (timer->GetTime() >= 0.1f)
	{
		aniFrame++;
		timer->Reset();
	}
	if (aniFrame >= 9) isDestroy = true;
}

void EnemyDeadEffect::Render()
{
	image->FindImage(aniFrame)->CenterRender(vPos);
}

void EnemyDeadEffect::Release()
{
	SAFE_DELETE(timer);
}
