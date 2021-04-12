#pragma once
#include "Object.h"
class PlayerHitEffect :
    public Object
{
private:
    texture* image;

    CDXUTTimer* timer;

public:
    PlayerHitEffect() {}
    virtual ~PlayerHitEffect() {}

    // Object��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

