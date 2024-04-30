#include "Engine.h"

#include "../WindowManager/WindowManager.h"
#include "../ObjectManager/ObjectManager.h"

std::string Engine::ClassName()
{
    return "Engine";
}

std::string Engine::GetClass()
{
    return "Engine";
}

void Engine::StartEngine()
{
    WindowManager* window_manager = ObjectManager::Get()->CastCreateObject<WindowManager>(WindowManager::ClassName());
    window_manager->WindowDraw();   
}
