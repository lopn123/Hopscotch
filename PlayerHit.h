#pragma once
#include "Object.h"
class PlayerHit :
    public Object
{
private:
    texture* image;

    CDXUTTimer* timer;

public:
    PlayerHit() {}
    virtual ~PlayerHit() {}

    // Object을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

