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
    WindowManager* windowManager = ObjectManager::Get()->CastCreateObject<WindowManager>(WindowManager::ClassName());
    InputManager* inputManager = ObjectManager::Get()->CastCreateObject<InputManager>(InputManager::ClassName());
    EntityManager* entityManager = ObjectManager::Get()->CastCreateObject<EntityManager>(EntityManager::ClassName());
    entityManager->window_manager = windowManager;
    windowManager->entityManager = entityManager;
    entityManager->CreateActor();
    windowManager->inputManagerGame = inputManager;
    windowManager->WindowDraw();
}
