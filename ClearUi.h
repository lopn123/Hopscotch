#pragma once
#include "Object.h"
class ClearUi :
    public Object
{
private:

public:
    ClearUi() {}
    virtual ~ClearUi() {}

    // Object��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

