#pragma once
#include "../Engine.h"

class ApplyPhysics : public Engine
{
private:
    Vector2<float> movement;
public:
    void CreatePhysics(sf::CircleShape& shape, const Vector2<float>& force);
};
