// oiram.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include "BaseObject.h"
#include <iostream>

#include "Utils/Utils.h"
#include "Utils/Engine/Engine.h"
#include "Utils/ObjectManager/ObjectManager.h"


int main()
{
    Engine* engine = ObjectManager::get()->CastCreateObject<Engine>(Engine::ClassName());
    Utils::SetEngine(engine);
    engine->StartEngine();
    return 0;
}
