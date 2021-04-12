#pragma once
#include "Object.h"
class Stage1Explosion :
    public Object
{
private:
    vecTexture* image;

    CDXUTTimer* timer;

    int aniFrame = 0;

public:
    Stage1Explosion() {}
    virtual ~Stage1Explosion() {}

    // Object을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

