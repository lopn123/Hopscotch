#pragma once
#include "Object.h"
class HpItem :
    public Object
{
private:

    int alpha = 0;
public:
    HpItem() {}
    virtual ~HpItem() {}

    // Object��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

