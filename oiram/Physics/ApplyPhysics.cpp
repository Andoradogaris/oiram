#include "ApplyPhysics.h"

void ApplyPhysics::GetNextMovement()
{
    sf::CircleShape Player(50.f);
    
    sf::Vector2f movement = Gravity::ApplyGravity(Player);
}