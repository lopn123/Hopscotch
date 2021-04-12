#pragma once
#include "Object.h"
class Player :
    public Object
{
private:
    CDXUTTimer *timer;
    CDXUTTimer* damagedTimer, * moveTimer;
    D3DCOLOR color = D3DCOLOR_XRGB(255, 255, 255);

    int speed = 14, move = 0;
    float rot = 0;
    bool speedUp = false;

    void Move();
    void OutCheck();
    void Cheat();

public:
    Player() {}
    virtual ~Player() {}
    // Object을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;

    Vector2 prevPos;
    int maxHp = 5, maxMove = 20;
    int hp = 5, canMoveVal = 100;
    bool isOut = false, invincible = false, cam = true;

    void PInit()
    {
        color = D3DCOLOR_XRGB(255, 255, 255);
        maxHp = 5, maxMove = 20;
        hp = 5, canMoveVal = 100;
        isOut = false, invincible = false, cam = true;
    }

    void GetItem(Object* obj);
};