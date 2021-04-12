#pragma once
#include "singleton.h"
#include "Scene.h"
#include "Stage.h"

class SceneManager :
    public singleton< SceneManager>
{
private:
    Scene* nowScene, *nextScene;
    map<string, Scene*> scenes;

    void Release();

public:
    SceneManager();
    virtual ~SceneManager();

    void Update();
    void Render();

    Scene* AddScene(const string& key, Scene* scene);
    Scene* ChangeScene(const string& key);

    Stage* st;
};

#define SCENE SceneManager::GetInstance()