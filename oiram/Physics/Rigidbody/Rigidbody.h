#pragma once
#include "../../Engine.h"


class Rigidbody:Engine
{
private:
    static const float gravityScale;
    
    public :
        static sf::Vector2f Gravity();
        static sf::Vector2f Move(sf::Vector2f positions);
};
