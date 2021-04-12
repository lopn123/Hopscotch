#pragma once
#include "Object.h"
class Stage1BossExplosion :
    public Object
{
private:
    vecTexture* image;

    CDXUTTimer* timer;

    int aniFrame = 0;

public:
    Stage1BossExplosion() {}
    virtual ~Stage1BossExplosion() {}

    // Object��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

