#pragma once
#include "singleton.h"
class SouondManager :
    public singleton< SouondManager>
{
private:

public:
    SouondManager();
    virtual ~SouondManager();
};

#define SOUND SouondManager::GetInstance()