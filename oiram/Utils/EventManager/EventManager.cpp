#include "EventManager.h"

std::string EventManager::GetClass()
{
    return "EventManager";
}

void EventManager::SetWindowRef(sf::RenderWindow* wind)
{
    windowscreen = wind;
}

void EventManager::ListenEvent()
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
