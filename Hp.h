#pragma once
#include "Object.h"
class Hp :
    public Object
{
private:
    Vector2 size = { 1,1 };

public:
    Hp() {}
    virtual ~Hp() {}

    // Object��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

