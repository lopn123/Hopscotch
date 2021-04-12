#pragma once
#include "Object.h"
class ExplosionBullet :
    public Object
{
private:
    texture* image;

    Vector2 dir;
    int speed;

public:
    ExplosionBullet(Vector2 Direction, int Speed = 1400);
    virtual ~ExplosionBullet() {};

    // Object��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

