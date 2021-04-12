#pragma once
#include "Object.h"
class StopBullet :
    public Object
{
private:
    texture* image;

    CDXUTTimer* timer;

    Vector2 dir;
    int speed;

public:
    StopBullet(Vector2 Direction, int Speed = 1400);
    virtual ~StopBullet() {};

    // Object��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

