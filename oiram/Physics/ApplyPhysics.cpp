#include "ApplyPhysics.h"

 sf::Vector2f ApplyPhysics::movement;

void ApplyPhysics::CreatePhysics(sf::CircleShape& shape)
{
    movement = Gravity::ApplyGravity(shape);
    
    shape.move(movement);
}