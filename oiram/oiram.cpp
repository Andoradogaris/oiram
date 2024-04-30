// oiram.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include "BaseObject.h"
#include <iostream>

#include "Utils/WindowManager/WindowManager.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            
            window.clear(sf::Color::Black);
            
        
            window.display();

            WindowManager window_manager;
            window_manager.WindowDraw();
        }

    return 0;
}
