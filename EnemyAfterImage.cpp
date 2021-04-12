#include "DXUT.h"
#include "EnemyAfterImage.h"

void EnemyAfterImage::Init()
{
	image = IMAGE->FindImage("SpeedEnemy");

	timer = new CDXUTTimer;
	timer->Start();
}

void EnemyAfterImage::Update()
{
	if (timer->GetTime() > 0.3f) isDestroy = true;
}

void EnemyAfterImage::Render()
{
	image->CenterRender(vPos, 0, { 1,1 }, D3DCOLOR_RGBA(255, 255, 255, 60));
}

void EnemyAfterImage::Release()
{
	SAFE_DELETE(timer);
}
