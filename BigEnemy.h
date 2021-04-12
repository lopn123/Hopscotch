#pragma once
#include "Object.h"
class BigEnemy :
    public Object
{
private:

    Vector2 dir = { 1, -1 };
    int speed = 4;
    int alpha = 255;
    float rot = 0, rad = 0;
    bool isDead = false;

    void Move();

public:
    BigEnemy() {}
    virtual ~BigEnemy() {}

    // Object을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;

};

