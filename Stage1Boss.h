#pragma once
#include "Object.h"
class Stage1Boss :
    public Object
{
private:

    CDXUTTimer *fireTimer, *timer;

    Vector2 dir = { -1,1 };
    int speed = 12;
    int alpha = 255;
    float rot = 0, rad = 0;
    bool isDead = false;

    void Move();
    void Pattern();

public:
    Stage1Boss() {}
    virtual ~Stage1Boss() {}

    // Object을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;

};

