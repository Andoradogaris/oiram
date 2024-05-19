#include "Utils.h"

Engine* Utils::engine = nullptr;
//fonction qui contient notre engine pour pouvoir l'appeler de partout de manière static
void Utils::SetEngine(Engine* valEngine)
{
    engine = valEngine;
}

Engine* Utils::GetEngine()
{
    return engine;
}
