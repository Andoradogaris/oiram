#include "Gravity.h"



sf::Vector2f Gravity::ApplyGravity(sf::CircleShape& shape)
{
    return sf::Vector2f(0.f, gravityScale);
}
