#pragma once
#include "Object.h"
class PlayerDeadUi :
    public Object
{
private:


public:
    PlayerDeadUi() {}
    virtual ~PlayerDeadUi() {}

    // Object��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

