#include "Collision.h"

#include "../../Utils/WindowManager/WindowManager.h"


std::string Collision::GetClass()
{
    return "Collision";
}

bool Collision::checkCollision(sf::FloatRect entityCol)
{
    
    for (const sf::FloatRect& colRect : collidersToCheck)
    {
        if (entityCol.intersects(colRect))
        {
            return true;
        }
    }
    return false;
}

std::vector<CollisionDir> Collision::collisionDirection(const sf::FloatRect& objet1, const sf::FloatRect& objet2)
{
    std::vector<CollisionDir> result;
    
    float overlapLeft = objet2.left - (objet1.left + objet1.width);
    float overlapRight = (objet2.left + objet2.width) - objet1.left;
    float overlapTop = objet2.top - (objet1.top + objet1.height);
    float overlapBottom = (objet2.top + objet2.height) - objet1.top;
    
    if (overlapLeft > 0 && overlapRight > 0 && overlapTop > 0 && overlapBottom > 0)
    {
        if (overlapLeft < overlapRight && overlapLeft < overlapTop && overlapLeft < overlapBottom)
        {
            result.push_back(CollisionDir::Gauche);
        }

        if (overlapRight < overlapLeft && overlapRight < overlapTop && overlapRight < overlapBottom)
        {
            result.push_back(CollisionDir::Droite);
        }

        if (overlapTop < overlapLeft && overlapTop < overlapRight && overlapTop < overlapBottom)
        {
            result.push_back(CollisionDir::Haut);
        }

        if (overlapBottom < overlapLeft && overlapBottom < overlapRight && overlapBottom < overlapTop)
        {
            result.push_back(CollisionDir::Bas);
        }
    }
    
    if(result.empty())
    {
        result.push_back(CollisionDir::Aucune);
    }
    
    return result;
}

std::string Collision::ClassName()
{
    return "Collision";
}
