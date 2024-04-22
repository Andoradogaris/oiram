#include "Rigidbody.h"

const float Rigidbody::gravityScale = .01f;

sf::Vector2f Rigidbody::Gravity(float multiplier)
{
    return sf::Vector2f(0.f, gravityScale * multiplier);
}

sf::Vector2f Rigidbody::Move(sf::Vector2f positions)
{
    return sf::Vector2f(positions.x, positions.y);
}