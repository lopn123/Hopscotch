#pragma once
#include "Object.h"
class invincibleItem :
    public Object
{
private:

    int alpha = 0;
public:
    invincibleItem() {}
    virtual ~invincibleItem() {}

    // Object을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

