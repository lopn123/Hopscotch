#pragma once
#include "Object.h"
class Stage2Boss :
    public Object
{
private:

    CDXUTTimer* fireTimer, *fireTimer2, *timer;

    Vector2 dir = { -1, -1 };
    int speed = 8;
    int alpha = 255;
    int count = 0;
    float rot = 0, rad = 0;
    bool isDead = false;

    void Move();
    void Pattern();

public:
    Stage2Boss() {}
    virtual ~Stage2Boss() {}

    // Object을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;

};

