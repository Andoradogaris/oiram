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

        if(event.type == sf::Event::KeyReleased )
        {
            if(event.key.scancode == sf::Keyboard::Scan::Space)
            {
                player->Jump();
            }
        }
        
        if(event.key.scancode == sf::Keyboard::Scan::Right)
        {
            player->Move(1.f,0.f);
        }else if(event.key.scancode == sf::Keyboard::Scan::Left)
        {
            player->Move(-1.f,0.f);
        }

        if(event.key.scancode == sf::Keyboard::Scan::Up)
        {
            player->Move(0.f,-1.f);
        }else if(event.key.scancode == sf::Keyboard::Scan::Down)
        {
            player->Move(0.f,1.f);
        }

    }

    
}

std::string InputManager::ClassName()
{
    return "EventManager";
}
