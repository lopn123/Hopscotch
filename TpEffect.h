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

    // Object��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

