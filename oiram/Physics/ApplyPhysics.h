#pragma once
#include "../Engine.h"


class ApplyPhysics: Engine
{
private:
    static sf::Vector2f movement;
public:
    static void CreatePhysics(sf::CircleShape& shape, sf::Vector2f& force);
};
