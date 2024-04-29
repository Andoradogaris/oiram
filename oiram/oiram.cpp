// oiram.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include "BaseObject.h"
#include <iostream>


#include "Physics/Rigidbody/Rigidbody.h"

#include "Utils/WindowManager/WindowManager.h"

Vector2<float> A;
Vector2<float> B;
Vector2<float> C = Vector2(0.f);


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    Engine engine;
    Rigidbody rb;
    
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            //std::cout << engine.clock.getElapsedTime().asSeconds() << "\n";        
            
            //rb.AddForce(Vector2<float>(.2f, .2f), Impulse);
            
            rb.useGravity = true;
            rb.Gravity(.1f);
            
            std::cout << rb.velocity.x << " | " << rb.velocity.y << "\n";
            
            
            window.clear(sf::Color::Black);
            
        
            window.display();
            engine.clock.restart();

            WindowManager window_manager;
            window_manager.WindowDraw();
    
            // sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
            //
            // while (window.isOpen())
            // {
            //     sf::Event event;
            //     while (window.pollEvent(event))
            //     {
            //         if (event.type == sf::Event::Closed)
            //             window.close();
            //     }
            //     clock.restart();
            //
            //     float deltaTime = clock.restart().asSeconds();
            //     
            //     window.clear(sf::Color::Black);
            //     
            //
            //     window.display();
            // }
        }

    return 0;
}
