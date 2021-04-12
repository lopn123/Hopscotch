#include "DXUT.h"
#include "TpEffect.h"

void TpEffect::Init()
{
	image = IMAGE->AddVecImage("TpEffect", "Effect/TpEffect", 5);

	timer = new CDXUTTimer;
	timer->Start();
}

void TpEffect::Update()
{
	if (!chk)
	{
		rot++;

		if (aniFrame < 4)
		{
			if (timer->GetTime() >= 0.1f)
			{
				aniFrame++;
				timer->Reset();
			}
		}
		else
		{
			chk = true;
		}
	}
	else
	{
		rot--;

		if (timer->GetTime() >= 0.1f)
		{
			aniFrame--;
			timer->Reset();
		}
		if (aniFrame == 0) isDestroy = true;
	}
	

}

void TpEffect::Render()
{
	image->FindImage(aniFrame)->CenterRender(vPos, rot, { 2,2 }, D3DCOLOR_RGBA(255, 255, 255, 100));
}

void TpEffect::Release()
{
	SAFE_DELETE(timer);
}
