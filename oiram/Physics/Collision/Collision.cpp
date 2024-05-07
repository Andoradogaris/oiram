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
            //std::cout << "true" << std::endl;
            return true;
        }
    }
    //std::cout << "false" << std::endl;
    return false;
}

std::vector<CollisionDir> Collision::collisionDirection(const sf::FloatRect& entityCol)
{
    std::vector<CollisionDir> result;

    if (checkCollision(entityCol))
    {
        for (const sf::FloatRect& colRect : collidersToCheck)
        {
            float overlapLeft = colRect.left - (entityCol.left + entityCol.width);
            float overlapRight = (colRect.left + colRect.width) - entityCol.left;
            float overlapTop = colRect.top - (entityCol.top + entityCol.height);
            float overlapBottom = (colRect.top + colRect.height) - entityCol.top;

            if (overlapLeft > 0 || overlapRight > 0 || overlapTop > 0 || overlapBottom > 0)
            {
                if (overlapLeft < overlapRight || overlapLeft < overlapTop || overlapLeft < overlapBottom)
                {
                    result.push_back(CollisionDir::Gauche);
                }

                if (overlapRight < overlapLeft || overlapRight < overlapTop || overlapRight < overlapBottom)
                {
                    result.push_back(CollisionDir::Droite);
                }

                if (overlapTop < overlapLeft || overlapTop < overlapRight || overlapTop < overlapBottom)
                {
                    result.push_back(CollisionDir::Haut);
                }

                if (overlapBottom < overlapLeft || overlapBottom < overlapRight || overlapBottom < overlapTop)
                {
                    result.push_back(CollisionDir::Bas);
                }
            }
        }

        if(!result.empty())
        {
            return result;
        }
    }
    result.push_back(CollisionDir::Aucune);
    
    return result;
}

std::string Collision::ClassName()
{
    return "Collision";
}
