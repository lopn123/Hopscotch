#include "DXUT.h"
#include "ReturnBullet.h"

ReturnBullet::ReturnBullet(Vector2 Direction, int Speed)
	:dir(Direction), speed(Speed)
{
}

void ReturnBullet::Init()
{
	image = IMAGE->FindImage("Bullet");

	timer = new CDXUTTimer;
	timer->Start();
}

void ReturnBullet::Update()
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
		rad = atan2(OBJECT->player->vPos.y - vPos.y, OBJECT->player->vPos.x - vPos.x);
		chk = true;
		timer->Reset();
		timer->Stop();
	}

	if (!chk)
		vPos += dir * speed * D_TIME;
	else
		vPos += Vector2(cos(rad), sin(rad)) * (speed * 2) * D_TIME;
}

void ReturnBullet::Render()
{
	image->CenterRender(vPos);
}

void ReturnBullet::Release()
{
	SAFE_DELETE(timer);
}
