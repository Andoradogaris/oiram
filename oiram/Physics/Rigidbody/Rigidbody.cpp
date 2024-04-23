#include "Rigidbody.h"

sf::Vector2f Rigidbody::Gravity(float multiplier)
{
    return {0.f, gravityScale * multiplier};
}

sf::Vector2f Rigidbody::Move(Vector2<float> positions)
{
    return {positions.x, positions.y};
}