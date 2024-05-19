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
        // Detecte si on veux fermer le jeu
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

        // Détecte si l'on saute
        if(event.type == sf::Event::KeyReleased )
        {
            if(event.key.scancode == sf::Keyboard::Scan::Space)
            { 
                player->Jump();
            }
        }

        //Detecte si l'on se déplace a gauche ou a droite
        if(event.type == sf::Event::KeyPressed)
        {
            // Déplacement axe x
            if(event.key.scancode == sf::Keyboard::Scan::Right)
            {
                player->Move(10.f,0.f);
                right = true;
            }else if(event.key.scancode == sf::Keyboard::Scan::Left)
            {
                player->Move(-10.f,0.f);
                left = true;
            }

            // Déplacement axe y
            if(event.key.scancode == sf::Keyboard::Scan::Up)
            {
                // player->Move(0.f,-10.f);
            }else if(event.key.scancode == sf::Keyboard::Scan::Down)
            {
                // player->Move(0.f,10.f);
            } 

            }
        // Détection fin de déplacement
        if(event.type == sf::Event::KeyReleased)
        {
            if(event.key.scancode == sf::Keyboard::Scan::Right && right)
            {
                player-> ResetMove();
                right = false;
            }
            if(event.key.scancode == sf::Keyboard::Scan::Left && left)
            {
                player-> ResetMove();
                left = false;
            }
            if(event.key.scancode == sf::Keyboard::Scan::Up)
            {
                // player-> ResetMove();
                // up = false;
            }else if(event.key.scancode == sf::Keyboard::Scan::Down)
            {
                // player-> ResetMove();
                // down = false;
            } 

  
        }


    }

    
}

std::string InputManager::ClassName()
{
    return "EventManager";
}
