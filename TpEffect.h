#pragma once
#include "Object.h"
class TpEffect :
    public Object
{
private:
    vecTexture* image;

    CDXUTTimer* timer;

    int aniFrame = 0;
    float rot = 0;
    bool chk = false;

public:
    TpEffect() {}
    virtual ~TpEffect() {}

    // Object을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

