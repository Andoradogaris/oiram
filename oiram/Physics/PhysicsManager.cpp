#include "PhysicsManager.h"
#include <iostream>
#include "Rigidbody/Rigidbody.h"

std::string ApplyPhysics::GetClass()
{
    return "ApplyPhysics";
}

void ApplyPhysics::CreatePhysics(sf::CircleShape& shape, const Vector2<float>& force)
{
    Rigidbody rb;
    
    
    //shape.move(movement);
    //std::cout << movement.x << movement.y << std::endl;

    //movement = sf::Vector2f(0.f, 0.f);
}

std::string ApplyPhysics::ClassName()
{
    return "ApplyPhysics";
}
