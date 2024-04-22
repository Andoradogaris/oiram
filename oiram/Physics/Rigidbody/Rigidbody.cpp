#include "Rigidbody.h"

const float Rigidbody::gravityScale = .01f;

sf::Vector2f Rigidbody::Gravity(sf::CircleShape& shape)
{
    return sf::Vector2f(0.f, gravityScale);
}

sf::Vector2f Rigidbody::Move(sf::Shape& shape, sf::Vector2f positions)
{
    return sf::Vector2f(positions.x, positions.y);
}