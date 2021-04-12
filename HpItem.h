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

    // Object을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

