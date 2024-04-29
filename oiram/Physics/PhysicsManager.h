#pragma once
#include "../BaseObject.h"

class ApplyPhysics : public BaseObject
{
private:
public:
    Vector2<float> movement;
    std::string GetClass() override;
    void CreatePhysics(sf::CircleShape& shape, const Vector2<float>& force);
};
