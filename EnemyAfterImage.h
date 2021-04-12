#pragma once
#include "Object.h"
class EnemyAfterImage :
    public Object
{
private:
    texture* image;

    CDXUTTimer* timer;

public:
    EnemyAfterImage() {}
    virtual ~EnemyAfterImage() {}

    // Object을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

