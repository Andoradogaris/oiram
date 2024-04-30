#include "Rigidbody.h"


void Rigidbody::Gravity(float deltaTime, float multiplier)
{
    if(useGravity)
    {
        AddForce(Vector2<float>(0, gravityScale * multiplier), Constant, deltaTime);
    }
}

void Rigidbody::AddForce(const Vector2<float> force, ForceMode mode, float deltaTime)
{
    if (mode == Constant){
        float ForceXToAdd = force.x * deltaTime;
        float ForceYToAdd = force.y * deltaTime;
        velocity.x += ForceXToAdd;
        velocity.y += ForceYToAdd;
    }
    else{
        velocity.x += force.x;
        velocity.y += force.y;
    }
    // switch(mode)
    // {
    //     case Constant:
    //         
    //         break;
    //     case Impulse:
    //             
    //         break;
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
    //}
}

std::string Rigidbody::ClassName()
{
    return "Rigidbody";
}
