#include "ApplyPhysics.h"

void ApplyPhysics::GetNextMovement()
{
    sf::CircleShape Player(50.f);
    Player.setPosition(Gravity::ApplyGravity(Player));
}