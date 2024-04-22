#include "WindowManager.h"

#include "../../Objects/Entities/Components/Renderer/Renderer.h"

std::list<GameObject> objectToDraw;

void WindowManager::WindowDraw()
{
    RECT desktop;
    GetWindowRect(GetDesktopWindow(), &desktop);
    int horizontal = desktop.right;
    int vertical = desktop.bottom;

    sf::RenderWindow window(sf::VideoMode(horizontal, vertical), "My window");
    while (window.isOpen())
    {
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