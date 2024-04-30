#pragma once
#include "Engine/Engine.h"

class Utils
{
public:
    static void SetEngine(Engine* valEngine);
    static Engine* GetEngine();
private:
    static Engine* engine;

};
