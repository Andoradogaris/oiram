#pragma once
#include "../Engine.h"
#include "Gravity/Gravity.h"

class ApplyPhysics
{
private:
    static sf::Vector2f movement;
public:
    static void CreatePhysics(sf::CircleShape& shape);
};
