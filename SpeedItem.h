#pragma once
#include "Object.h"
class SpeedItem :
    public Object
{
private:

    int alpha = 0;
public:
    SpeedItem() {}
    virtual ~SpeedItem() {}

    // Object��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

