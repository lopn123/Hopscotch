#pragma once
#include "Object.h"
class ReturnBullet :
    public Object
{
private:
    texture* image;

    CDXUTTimer* timer;

    Vector2 dir;
    int speed;
    float rad = 0;

    bool chk = false;

public:
    ReturnBullet(Vector2 Direction, int Speed = 1400);
    virtual ~ReturnBullet() {};

    // Object��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

