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

    // Object을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

