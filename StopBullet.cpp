#include "DXUT.h"
#include "StopBullet.h"

StopBullet::StopBullet(Vector2 Direction, int Speed)
	:dir(Direction), speed(Speed)
{
}

void StopBullet::Init()
{
	image = IMAGE->FindImage("Bullet");

	timer = new CDXUTTimer;
	timer->Start();
}

void StopBullet::Update()
{
	float distance;
	distance = sqrt(pow(OBJECT->player->vPos.x - vPos.x, 2) + pow(OBJECT->player->vPos.y - vPos.y, 2));

	if (distance < 50 && OBJECT->player->isOut && !OBJECT->player->invincible)
	{
		SCENE->st->PlayerHit();
		isDestroy = true;
	}

	if (timer->GetTime() > 0.6f)
	{
		if (timer->GetTime() > 1)
		{
			speed += 400;
			timer->Reset();
			timer->Stop();
		}
	}
	else
	{
		vPos += dir * speed * D_TIME;
	}
}

void StopBullet::Render()
{
	image->CenterRender(vPos);
}

void StopBullet::Release()
{
	SAFE_DELETE(timer);
}
