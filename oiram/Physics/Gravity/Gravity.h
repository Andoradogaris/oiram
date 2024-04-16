#pragma once
#include "../../Engine.h"

class Gravity : Engine
{
private:
    const float gravityScale = 0.1f;
    
public :
    sf::Vector2f ApplyGravity(sf::CircleShape& shape);
};

