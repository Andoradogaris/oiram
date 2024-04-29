#include "Rigidbody.h"

Engine engine;

void Rigidbody::Gravity(float multiplier)
{
    if(useGravity)
    {        
        velocity.y -= mass * gravityScale * multiplier;
    }
}

void Rigidbody::AddForce(const Vector2<float> force, ForceMode mode)
{    
    switch(mode)
    {
        case Constant:
            velocity.x += force.x;
            velocity.y += force.y;
            break;
        // case Impulse:
        //         timer += engine.deltaTime;
        //         velocity.x += force.x / timer;
        //         velocity.y += force.y / timer;
        //     break;
        // case Explosive:
        //     
        //     std::random_device rd;
        //     std::mt19937 gen(rd());
        //
        //     float length = force.Length();
        //
        //     std::uniform_real_distribution<float> distribution(0, length);
        //     float rdm = distribution(gen);
        //
        //     Vector2 explosionForce(rdm, length - rdm);
        //
        //     break;
    }
}