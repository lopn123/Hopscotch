#include "DXUT.h"
#include "ExplosionBullet.h"
#include "BulletExplosionEffect.h"

ExplosionBullet::ExplosionBullet(Vector2 Direction, int Speed)
	:dir(Direction), speed(Speed)
{
}

void ExplosionBullet::Init()
{
	image = IMAGE->FindImage("ExplosionBullet");
}

void ExplosionBullet::Update()
{
	float distance;
	distance = sqrt(pow(OBJECT->player->vPos.x - vPos.x, 2) + pow(OBJECT->player->vPos.y - vPos.y, 2));

	if (distance < 50 && OBJECT->player->isOut && !OBJECT->player->invincible)
	{
		SCENE->st->PlayerHit();
		OBJECT->AddObject("BulletExplosionEffect", new BulletExplosionEffect, vPos, EFFECT);
		isDestroy = true;
	}
	else if (WORLD->map[(int)vPos.y][(int)vPos.x] == 1 || WORLD->map[(int)vPos.y][(int)vPos.x] == 3)
	{
		CAMERA->CameraShake(600);
		OBJECT->AddObject("BulletExplosionEffect", new BulletExplosionEffect, vPos, EFFECT);
		isDestroy = true;
	}

	vPos += dir * speed * D_TIME;
}

void ExplosionBullet::Render()
{
	image->CenterRender(vPos);
}

void ExplosionBullet::Release()
{
}
