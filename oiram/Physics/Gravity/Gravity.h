#pragma once
#include "../../Engine.h"

class Gravity : Engine
{
private:
    static const float gravityScale = 0.1f;
    
public :
    static sf::Vector2f ApplyGravity(sf::CircleShape& shape);
};

