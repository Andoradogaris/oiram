#pragma once
#include "../../Engine.h"

class Gravity : Engine
{
private:
    static const float gravityScale;
    
public :
    static sf::Vector2f ApplyGravity(sf::CircleShape& shape);
};

