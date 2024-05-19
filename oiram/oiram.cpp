#include "BaseObject.h"
#include <iostream>

#include "Utils/Utils.h"
#include "Utils/Engine/Engine.h"
#include "Utils/ObjectManager/ObjectManager.h"

//fonction qui crée et lance l'engine
int main()
{
    Engine* engine = ObjectManager::get()->CastCreateObject<Engine>(Engine::ClassName());
    Utils::SetEngine(engine);
    engine->StartEngine();
    return 0;
}
