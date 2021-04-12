#pragma once
#include "Object.h"
class EnemyDeadEffect :
    public Object
{
private:
    vecTexture* image;

    CDXUTTimer* timer;

    int aniFrame = 0;

public:
    EnemyDeadEffect() {}
    virtual ~EnemyDeadEffect() {}

    // Object��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

