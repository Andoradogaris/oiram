#include "PhysicsManager.h"

#include <iostream>

#include "Rigidbody/Rigidbody.h"

void ApplyPhysics::CreatePhysics(sf::CircleShape& shape, const Vector2<float>& force)
{
    Rigidbody rb;
    
    // movement += rb.Gravity();
    // movement += rb.Move(force);
    
    shape.move(movement);
    //std::cout << movement.x << movement.y << std::endl;

    movement = sf::Vector2f(0.f, 0.f);
}