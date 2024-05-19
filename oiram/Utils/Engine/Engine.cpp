#include "Engine.h"
#include "../WindowManager/WindowManager.h"
#include "../ObjectManager/ObjectManager.h"
#include "../EntityManager/EntityManager.h"

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
    WindowManager* windowManager = ObjectManager::get()->CastCreateObject<WindowManager>(WindowManager::ClassName());
    InputManager* inputManager = ObjectManager::get()->CastCreateObject<InputManager>(InputManager::ClassName());
    EntityManager* entityManager = ObjectManager::get()->CastCreateObject<EntityManager>(EntityManager::ClassName());
    entityManager->window_manager = windowManager;
    windowManager->entityManager = entityManager;
    entityManager->CreateActor();
    windowManager->inputManagerGame = inputManager;
    windowManager->WindowDraw();
}
