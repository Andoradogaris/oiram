#include "Rigidbody.h"
#include "../../Utils/TemplateUtils.h"
#include "../Collision/Collision.h"
#include "../../Objects/Entities/Components/Renderer/Renderer.h"


void Rigidbody::Gravity(float deltaTime,Collision* col, Renderer* rend, float multiplier)
{
    if(useGravity)
    {
        AddForce(Vector2<float>(0, gravityScale * multiplier), Constant,col,rend, deltaTime);
    }
}

void Rigidbody::AddForce(const Vector2<float> force, ForceMode mode,Collision* col, Renderer* rend, float deltaTime)
{

    switch(mode)
    {
        //Vitesse constante pas d'accélération
        case Constant:
            velocity.x += force.x * deltaTime;
            velocity.y += force.y * deltaTime;
            break;
        //Accélération à un moment T
        case Impulse: 
            velocity.x -= force.x;
            velocity.y -= force.y;
            break;
        //Comme un impulse mais dans une direction aléatoire
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

    CheckCollisions(col, rend);
}

void Rigidbody::CheckCollisions(Collision* col, Renderer* rend)
{
    std::vector<CollisionDir> directions ;
    directions = col->collisionDirection(rend->sprite.getGlobalBounds());
        
    for(int i = 0; i < directions.size(); i++)
    {
        //std::cout << directions.at(i) << std::endl;
            
        switch(directions.at(i))
        {
        case Up:
            if(velocity.y < 0)
            {
                velocity.y = 0;
            }
            break;
        case Down:
            if(velocity.y > 0)
            {
                velocity.y = 0;
            }
            break;
        case Left:
            if(velocity.x < 0)
            {
                velocity.x = 0;
            }
            break;
        case Right:
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

std::string Rigidbody::ClassName()
{
    return "Rigidbody";
}