#pragma once
#include "../../Engine.h"
#include "../../Objects/Entities/Components/Components.h"

class Rigidbody: public Components
{
private:
    static const float gravityScale;
    
    public :
        static sf::Vector2f Gravity(float multiplier = 1.f);
        static sf::Vector2f Move(sf::Vector2f positions);
};
