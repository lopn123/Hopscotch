#include "DXUT.h"
#include "NormalBullet.h"

NormalBullet::NormalBullet(Vector2 Direction, int Speed)
	:dir(Direction), speed(Speed)
{
}

void NormalBullet::Init()
{
	image = IMAGE->FindImage("Bullet");
}

void NormalBullet::Update()
{
	float distance;
	distance = sqrt(pow(OBJECT->player->vPos.x - vPos.x, 2) + pow(OBJECT->player->vPos.y - vPos.y, 2));

	if (distance < 50 && OBJECT->player->isOut && !OBJECT->player->invincible)
	{
		SCENE->st->PlayerHit();
		isDestroy = true;
	}

	vPos += dir * speed * D_TIME;
}

void NormalBullet::Render()
{
	image->CenterRender(vPos);
}

void NormalBullet::Release()
{
}
