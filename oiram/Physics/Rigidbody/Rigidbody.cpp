#include "Rigidbody.h"

sf::Vector2f Rigidbody::Gravity(float multiplier)
{
    return {0.f, gravityScale * multiplier};
}

sf::Vector2f Rigidbody::Move(sf::Vector2f positions)
{
    return {positions.x, positions.y};
}