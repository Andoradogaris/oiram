#include "ApplyPhysics.h"
#include "Rigidbody/Rigidbody.h"

sf::Vector2f ApplyPhysics::movement;

void ApplyPhysics::CreatePhysics(sf::CircleShape& shape, sf::Vector2f& force)
{
    movement += Rigidbody::Gravity();
    movement += Rigidbody::Move(force);
    
    shape.move(movement);
    
    movement = sf::Vector2f(0.f, 0.f);
}