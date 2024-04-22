// oiram.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <list>

#include "Engine.h"
#include "Physics/PhysicsManager.h"
#include "Physics/Collision/Collision.h"
#include <windows.h>

#include "Objects/GameObject.h"

sf::CircleShape Player(50.f);
sf::RectangleShape rectangle(sf::Vector2f(100.f, 100.f));
sf::RectangleShape rectangle2(sf::Vector2f(100.f, 100.f));
sf::Vector2f testImpulseForce(.001f, 0.f);




int main()
{
    sf::Clock clock;
    rectangle.setPosition(sf::Vector2f(0.f, 300.f));
    rectangle2.setPosition(sf::Vector2f(100.f, 500.f));
    sf::FloatRect playerCol;
    std::list<sf::FloatRect> platformsCols;
    Collision collision;
    ApplyPhysics applyPhysics;

    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        playerCol = Player.getGlobalBounds();
        platformsCols.push_back(rectangle.getGlobalBounds());
        platformsCols.push_back(rectangle2.getGlobalBounds());
        clock.restart();

        float deltaTime = clock.restart().asSeconds();
        
        if (!collision.checkCollision(playerCol, platformsCols))
        {
            applyPhysics.CreatePhysics(Player, testImpulseForce * deltaTime);
        }
        else {
            Player.move(0.05f, 0.f);
        }

        Player.setFillColor(sf::Color(100, 250, 50));

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        window.draw(Player);
        window.draw(rectangle);
        window.draw(rectangle2);

        window.display();
    }

    return 0;
}