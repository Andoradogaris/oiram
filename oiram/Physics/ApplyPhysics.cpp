#include "ApplyPhysics.h"

 sf::Vector2f ApplyPhysics::movement;

void ApplyPhysics::CreatePhysics(sf::CircleShape& shape, sf::Vector2f& force)
{
    movement += Gravity::ApplyGravity(shape);
    movement += Impulse::AddForce(force);
    
    shape.move(movement);
    
    movement = sf::Vector2f(0.f, 0.f);
}