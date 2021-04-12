#pragma once
#include "Object.h"
class AfterImage :
    public Object
{
private:
    texture* image;

    CDXUTTimer* timer;

public:
    AfterImage() {}
    virtual ~AfterImage() {}

    // Object��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

