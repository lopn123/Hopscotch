#pragma once
#include "singleton.h"
#include "Object.h"
#include "Player.h"

class ObjectManager :
    public singleton<ObjectManager>
{
public:
    ObjectManager();
    virtual ~ObjectManager();

    list<Object*> m_objList[Tag::END];

    void Update();
    void Render();
    void Release();

    Object* AddObject(const string& key, Object* _obj, Vector2 pos, Tag tag);
    bool isMapOut(Object* _obj);
    void ClearAllObject();

    Player* player;
    Vector2 bossPos = { WINSIZEX / 2, WINSIZEY / 2 };
};

#define OBJECT ObjectManager::GetInstance()