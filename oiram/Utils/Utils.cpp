#include "Utils.h"

Engine* Utils::engine = nullptr;

void Utils::SetEngine(Engine* valEngine)
{
    engine = valEngine;
}

Engine* Utils::GetEngine()
{
    return engine;
}
