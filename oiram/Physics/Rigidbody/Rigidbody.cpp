#include "Rigidbody.h"

Vector2<float> Rigidbody::Gravity(float multiplier)
{
    if(useGravity)
    {
        return {0.f, gravityScale * multiplier};   
    }
}

Vector2<float> Rigidbody::Move(Vector2<float> positions)
{
    return {positions.x, positions.y};
}

void Rigidbody::AddForce(const Vector2<float> force)
{
    Vector2<float> acceleration = force / mass;

    velocity += acceleration;
}