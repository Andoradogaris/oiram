#include "InputManager.h"

std::string InputManager::GetClass()
{
    return "EventManager";
}

void InputManager::SetWindowRef(sf::RenderWindow* wind)
{
    windowscreen = wind;
}

void InputManager::ListenEvent()
{

    sf::Event event;
    while(windowscreen->pollEvent(event))
    {
        if (event.type == sf::Event::Closed )
        {
            windowscreen->close();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Escape)
            {
                windowscreen->close();
            }
        }
    }

    
}

std::string InputManager::ClassName()
{
    return "EventManager";
}
