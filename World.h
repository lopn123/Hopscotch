#pragma once
#include "singleton.h"

class World : public singleton<World>
{
public:
	World() {}
	~World() {}

	int map[WINSIZEY][WINSIZEX] = { 0 };
	int score = 0, enemyNum;
};

#define WORLD World::GetInstance()