#pragma once
#include "singleton.h"
class CameraManager :
    public singleton< CameraManager>
{
public:
    CameraManager() { Init(); }
    ~CameraManager() {}

    Vector2 camPos, viewSize;
    D3DXMATRIX matView, matProj;
    float shakeTime;

    void Init();
    void Update();
    void Reset();
    void SetCam(Vector2 pos);
    void MoveCam(Vector2 pos);
    void SetTransform();
    void CameraShake(float Time);
};

#define CAMERA CameraManager::GetInstance()