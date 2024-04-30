// oiram.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include "BaseObject.h"
#include <iostream>

#include "Physics/Rigidbody/Rigidbody.h"
#include "Utils/ObjectManager/ObjectManager.h"
#include "Utils/WindowManager/WindowManager.h"

Vector2<float> A;
Vector2<float> B;
Vector2<float> C = Vector2(0.f);


int main()
{

    WindowManager* window_manager = ObjectManager::Get()->CastCreateObject<WindowManager>(WindowManager::ClassName());
    window_manager->WindowDraw();

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
    

    return 0;
}
