#include "Engine.h"
#include "../WindowManager/WindowManager.h"
#include "../ObjectManager/ObjectManager.h"
#include "../EntityManager/EntityManager.h"
//fonction static pour retourner le deltatime du moteur a tout le monde
float Engine::GetDeltaTime()
{
    return deltaTime;
}

//fonction pour récuperer le nom de la classe
std::string Engine::ClassName()
{
    return "Engine";
}

std::string Engine::GetClass()
{
    return "Engine";
}

//fonction qui crée tout les manager du moteur de jeu et qui les initialise
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
