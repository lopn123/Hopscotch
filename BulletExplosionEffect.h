#pragma once
#include "Object.h"
class BulletExplosionEffect :
    public Object
{
private:
    vecTexture* image;

    CDXUTTimer* timer;

    int aniFrame = 0;

public:
    BulletExplosionEffect() {}
    virtual ~BulletExplosionEffect() {}

    // Object��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

