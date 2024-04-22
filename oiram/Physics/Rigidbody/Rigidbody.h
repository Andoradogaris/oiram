#pragma once
#include "../../Engine.h"
#include "../../Objects/Entities/Components/Components.h"

class Rigidbody: public Components
{
private:
    const float gravityScale = 0.1f;
    
    public :
        sf::Vector2f Gravity(float multiplier = 1.f);
        sf::Vector2f Move(sf::Vector2f positions);
};


#pragma once
#include "../Character.h"
#include "../../../GameObject.h"

