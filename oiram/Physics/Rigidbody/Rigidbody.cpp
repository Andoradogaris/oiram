#include "Rigidbody.h"
#include "../../Utils/TemplateUtils.h"
#include "../Collision/Collision.h"
#include "../../Objects/Entities/Components/Renderer/Renderer.h"


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
            
            if (rdmXDir < 0.5f)
            {
                velocity.x += rdmforce;
            } else {
                velocity.x -= rdmforce;
            }

            if (rdmYDir < 0.5f)
            {
                velocity.y += length - rdmforce;
            } else {
                velocity.y -= length - rdmforce;
            }
            break;
    }

    CheckCollisions();
}

void Rigidbody::CheckCollisions()
{
    Collision* col = Cast<Collision>(GetOwner()->components.at("Collision"));
    Renderer* rend = Cast<Renderer>(GetOwner()->renderer);

    if(col->checkCollision(rend->sprite.getGlobalBounds()))
    {
        std::vector<CollisionDir> directions = col->collisionDirection();
        
        for(int i = 0; i < directions.size(); i++)
        {
            
            switch(directions[i])
            {
                case CollisionDir::Haut:
                    if(velocity.y > 0)
                    {
                        velocity.y = 0;
                    }
                    break;
                case CollisionDir::Bas:
                    if(velocity.y < 0)
                    {
                        velocity.y = 0;
                    }
                    break;
                case CollisionDir::Gauche:
                    if(velocity.x < 0)
                    {
                        velocity.x = 0;
                    }
                    break;
                case CollisionDir::Droite:
                    if(velocity.x > 0)
                    {
                        velocity.x = 0;
                    }
                    break;
                default:
                    break;
            }
        }
    }
}

std::string Rigidbody::ClassName()
{
    return "Rigidbody";
}