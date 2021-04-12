#pragma once
#include "Object.h"
class EnemyAfterImage :
    public Object
{
private:
    texture* image;

    CDXUTTimer* timer;

public:
    EnemyAfterImage() {}
    virtual ~EnemyAfterImage() {}

    // Object��(��) ���� ��ӵ�
    virtual void Init() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
};

