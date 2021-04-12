#pragma once
#include "Object.h"
class ScoreBoard :
    public Object
{
private:
    texture* image;

    int alpha = 255;
    int hp;

public:
    ScoreBoard() {}
    virtual ~ScoreBoard() {}
    // Object을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

