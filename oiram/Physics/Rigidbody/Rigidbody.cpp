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

    switch(mode)
    {
        case Constant:
            velocity.x += force.x * deltaTime;
            velocity.y += force.y * deltaTime;
            break;
        case Impulse:
            velocity.x -= force.x;
            velocity.y -= force.y;
            break;
        case Explosive:

            std::random_device rd;
            std::mt19937 gen(rd());
        
            float length = force.Length();

            std::uniform_real_distribution<float> forceDistrib(0.f, length);
            std::uniform_real_distribution<float> directionDistrib(0.f, 1.f);

            float rdmforce = forceDistrib(gen);
            float rdmXDir = directionDistrib(gen);
            float rdmYDir = directionDistrib(gen);
            
            if (rdmXDir < 0.5f) {
                velocity.x += rdmforce;
            } else {
                velocity.x -= rdmforce;
            }

            if (rdmYDir < 0.5f) {
                velocity.y += length - rdmforce;
            } else {
                velocity.y -= length - rdmforce;
            }

            std::cout << "Velocity: (" << velocity.x << ", " << velocity.y << ")" << std::endl;

            break;
    }
}

std::string Rigidbody::ClassName()
{
    return "Rigidbody";
}
