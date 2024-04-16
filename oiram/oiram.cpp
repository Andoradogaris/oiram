// oiram.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <SFML/Graphics.hpp>

float gravityScale = 0.1f;
sf::CircleShape Player(50.f);
sf::RectangleShape rectangle(sf::Vector2f(100.f, 100.f));
sf::RectangleShape rectangle2(sf::Vector2f(100.f, 100.f));

void ApplyGravity(sf::CircleShape& shape)
{
    shape.move(0.f, gravityScale);
}

int main()
{
    rectangle.setPosition(sf::Vector2f(0.f, 300.f));
    rectangle2.setPosition(sf::Vector2f(100.f, 500.f));
    sf::FloatRect playerCol;
    sf::FloatRect rectangleCol;
    sf::FloatRect rectangle2Col;

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
        rectangleCol = rectangle.getGlobalBounds();
        rectangle2Col = rectangle2.getGlobalBounds();

        if (!playerCol.intersects(rectangleCol) && !playerCol.intersects(rectangle2Col))
        {
            ApplyGravity(Player);
        }
        else {
            Player.move(0.005f, 0.f);
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