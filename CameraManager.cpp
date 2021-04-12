#include "DXUT.h"
#include "CameraManager.h"

void CameraManager::Init()
{
	camPos = { WINSIZEX / 2, WINSIZEY / 2 };
	viewSize = { WINSIZEX, WINSIZEY };
	shakeTime = 0;

	D3DXMatrixOrthoLH(&matProj, viewSize.x, -viewSize.y, 0, 1);
}

void CameraManager::Update()
{
	if (shakeTime >= timeGetTime())
	{
		camPos += Vector2(rand() % 21 - 10, rand() % 21 - 10);
	}

	D3DXMatrixLookAtLH(&matView, &Vector3(camPos.x, camPos.y, 0), &Vector3(camPos.x, camPos.y, 10), &Vector3(0, 1, 0));
	D3DXMatrixOrthoLH(&matProj, viewSize.x, -viewSize.y, 0, 1);
}

void CameraManager::Reset()
{
	camPos = { WINSIZEX / 2, WINSIZEY / 2 };
	viewSize = { WINSIZEX, WINSIZEY };
}

void CameraManager::SetCam(Vector2 pos)
{
	camPos = pos;
}

void CameraManager::MoveCam(Vector2 pos)
{
	camPos += pos;
}

void CameraManager::SetTransform()
{
	g_device->SetTransform(D3DTS_PROJECTION, &matProj);
	g_device->SetTransform(D3DTS_VIEW, &matView);
}

void CameraManager::CameraShake(float Time)
{
	if (shakeTime <= Time + timeGetTime())
	{
		shakeTime = Time + timeGetTime();
	}
}
