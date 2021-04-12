#pragma once
#include "Scene.h"
class Stage :
    public Scene
{
private:
    texture* stage, *black, *bigBlack, *stage2;

    D3DLOCKED_RECT lr;

    int count = 0;
    int st = 1;
    float rot = 0;

    void MapStartSetting();
    void FloodFill(int x, int y);
    void FillPercent();
    void ChangeTile();

public:
    Stage() {}
    virtual ~Stage() {}

    // Scene을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;

    float filledPercent = 0;

    void Fill(int x, int y, int r, int g, int b, int a);
    void EnemyMapFill(int x, int y, int r, int g, int b, int a);
    void PlayerInBorder();
    void PlayerHit();
    void NextStage();
};

