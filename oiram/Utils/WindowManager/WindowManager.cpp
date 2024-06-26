﻿#include "WindowManager.h"

#include "../TemplateUtils.h"
#include "../Utils.h"
#include "../../Objects/Entities/Components/Renderer/Renderer.h"
#include "../../Objects/Entities/Characters/Player/Player.h"
#include "../../Physics/Rigidbody/Rigidbody.h"
#include "../EntityManager/EntityManager.h"
#include "../InputManager/InputManager.h"
#include "../ObjectManager/ObjectManager.h"

std::list<GameObject> objectToDraw;
//fonction qui dessine chaque objet a l'écran et qui réinitialise le delatime du moteur
void WindowManager::WindowDraw()
{

    RECT desktop;
    GetWindowRect(GetDesktopWindow(), &desktop);
    int horizontal = desktop.right;
    int vertical = desktop.bottom;
    sf::RenderWindow window(sf::VideoMode(horizontal, vertical), "My window");
    inputManagerGame->SetWindowRef(&window);
    inputManagerGame->player = player;
    
    while (window.isOpen())
    {
        inputManagerGame->ListenEvent();
        entityManager->ActorAction();
        window.clear(sf::Color::Black);

        deltaTime = clock.restart().asSeconds();
        Utils::GetEngine()->deltaTime = deltaTime;
        std::sort(objectToDraw.begin(), objectToDraw.end());
        for (auto obj : objectToDraw)
        {
            window.draw(obj.first->sprite);
        }
        window.display();
    }
    
    clock.restart();
}

//fonction pour enregistrer un objet dans la liste des objets a dessiner
void WindowManager::AddNewObject(Renderer* object, int layerValue)
{
    objectToDraw.push_back(std::make_pair(object, layerValue));
    
}

//fonction pour obtenir le nom de la classe
std::string WindowManager::GetClass()
{
    return "WindowManager";
}


std::string WindowManager::ClassName()
{
    return "WindowManager";
}
