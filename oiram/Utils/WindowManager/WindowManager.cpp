#include "WindowManager.h"

#include "../../Objects/Entities/Components/Renderer/Renderer.h"
#include "../../Objects/Entities/Characters/Player/Player.h"
#include "../EventManager/EventManager.h"

std::list<GameObject> objectToDraw;

void WindowManager::WindowDraw()
{

    RECT desktop;
    GetWindowRect(GetDesktopWindow(), &desktop);
    int horizontal = desktop.right;
    int vertical = desktop.bottom;

    sf::RenderWindow window(sf::VideoMode(horizontal, vertical), "My window");
    EventManager eventManager;
    eventManager.SetWindowRef(&window);
    while (window.isOpen())
    {
        eventManager.ListenEvent();
        window.clear(sf::Color::Black);
        for (GameObject obj : objectToDraw)
        {
            // window.draw(obj);
        }

        window.display();
    }

}

void WindowManager::AddNewObject(GameObject object)
{
    objectToDraw.push_back(object);
    
}