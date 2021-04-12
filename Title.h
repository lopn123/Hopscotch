#pragma once
#include "Scene.h"
class Title :
    public Scene
{
private:
    texture* background, *black;
    texture* start, *how, *exit;
    texture* startOn, *howOn, *exitOn;
    texture* guide;

    int sel = 1, alpha = 0;
    bool isGuideWindow = false;

    void UiSelect();
public:
    Title() {}
    virtual ~Title() {}

    // Scene을(를) 통해 상속됨
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

