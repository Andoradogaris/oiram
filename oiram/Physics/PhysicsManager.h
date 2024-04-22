#pragma once
#include "../Engine.h"

class ApplyPhysics : public Engine
{
private:
    sf::Vector2f movement;
public:
    void CreatePhysics(sf::CircleShape& shape, const sf::Vector2f& force);
};
