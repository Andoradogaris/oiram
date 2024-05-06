#include "WindowManager.h"

#include "../TemplateUtils.h"
#include "../Utils.h"
#include "../../Objects/Entities/Components/Renderer/Renderer.h"
#include "../../Objects/Entities/Characters/Player/Player.h"
#include "../../Physics/Rigidbody/Rigidbody.h"
#include "../EntityManager/EntityManager.h"
#include "../InputManager/InputManager.h"
#include "../ObjectManager/ObjectManager.h"

std::list<GameObject> objectToDraw;

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

        for (auto obj : objectToDraw)
        {
            window.draw(obj->sprite);
        }

        window.display();
    }
    
    clock.restart();
}

std::string WindowManager::GetClass()
{
    return "WindowManager";
}

void WindowManager::AddNewObject(Renderer* object)
{
    objectToDraw.push_back(object);
    
}

std::string WindowManager::ClassName()
{
    return "WindowManager";
}
