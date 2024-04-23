#pragma once
#include "../Engine.h"

class ApplyPhysics
{
private:
    sf::Vector2f movement;
public:
    void CreatePhysics(sf::CircleShape& shape, const Vector2<float>& force);
};
