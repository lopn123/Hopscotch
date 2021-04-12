#include "DXUT.h"
#include "AfterImage.h"

void AfterImage::Init()
{
	image = IMAGE->FindImage("Player");

	timer = new CDXUTTimer;
	timer->Start();
}

void AfterImage::Update()
{
	if (timer->GetTime() > 0.2f) isDestroy = true;
}

void AfterImage::Render()
{
	image->CenterRender(vPos, 0, { 1,1 }, D3DCOLOR_RGBA(255, 255, 255, 60));
}

void AfterImage::Release()
{
	SAFE_DELETE(timer);
}
