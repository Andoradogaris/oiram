#include "WindowManager.h"

#include "../TemplateUtils.h"
#include "../../Objects/Entities/Components/Renderer/Renderer.h"
#include "../../Objects/Entities/Characters/Player/Player.h"
#include "../EventManager/EventManager.h"
#include "../ObjectManager/ObjectManager.h"

std::list<GameObject> objectToDraw;

void WindowManager::WindowDraw()
{

    RECT desktop;
    GetWindowRect(GetDesktopWindow(), &desktop);
    int horizontal = desktop.right;
    int vertical = desktop.bottom;
    Player* player = ObjectManager::Get()->CastCreateObject<Player>(Player::ClassName());
    player->InitializeEntity();
    Cast<Renderer>(player->components.at("rend"))->SetTexture(player);
    AddNewObject(Cast<Renderer>(player->components.at("rend")));
    sf::RenderWindow window(sf::VideoMode(horizontal, vertical), "My window");
    EventManager* eventManager = ObjectManager::Get()->CastCreateObject<EventManager>(EventManager::ClassName());
    eventManager->SetWindowRef(&window);
    while (window.isOpen())
    {
        eventManager->ListenEvent();
        window.clear(sf::Color::Black);
        
        for (auto obj : objectToDraw)
        {
            window.draw(obj->sprite);
        }

        window.display();
    }

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
