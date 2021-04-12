#pragma once
#include "Object.h"
class TpEnemy :
    public Object
{
private:

    CDXUTTimer* timer;

    Vector2 startPos;
    D3DCOLOR color = D3DCOLOR_RGBA(255, 255, 255, 255);
    int alpha = 255;
    int count = 0;
    float rad = 0;
    bool isDead = false;
    bool chk = false;

public:
    TpEnemy() {}
    virtual ~TpEnemy() {}

    // Object을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;

};

