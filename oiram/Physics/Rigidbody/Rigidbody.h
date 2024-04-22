#pragma once
#include "../../Engine.h"


class Rigidbody:Engine
{
private:
    static const float gravityScale;
    
    public :
        static sf::Vector2f Gravity(sf::CircleShape& shape);
        static sf::Vector2f Move(sf::Shape& shape, sf::Vector2f positions);
};
