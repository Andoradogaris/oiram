#include "Engine.h"

#include "../WindowManager/WindowManager.h"
#include "../ObjectManager/ObjectManager.h"

float Engine::GetDeltaTime()
{
    return deltaTime;
}

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
    WindowManager* windowManager = ObjectManager::Get()->CastCreateObject<WindowManager>(WindowManager::ClassName());
    InputManager* inputManager = ObjectManager::Get()->CastCreateObject<InputManager>(InputManager::ClassName());
    windowManager->inputManagerGame = inputManager;
    windowManager->WindowDraw();
}
