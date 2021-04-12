#pragma once
#pragma comment(lib, "legacy_stdio_definitions.lib")
#pragma comment(lib, "dsound.lib")

#include <map>
#include <string>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <list>
#include <vector>
#include <SDKsound.h>

using namespace std;

#define g_device DXUTGetD3D9Device()
#define D_TIME DXUTGetElapsedTime() * TimeScale

const int WINSIZEX = 1920;
const int WINSIZEY = 1080;

static bool isWindowed = false;
static float TimeScale = 1;

typedef D3DXVECTOR2 Vector2;
typedef D3DXVECTOR3 Vector3;

#include "CameraManager.h"
#include "ImageManager.h"
#include "SceneManager.h"
#include "ObjectManager.h"
#include "World.h"