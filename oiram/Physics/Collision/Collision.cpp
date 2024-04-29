#include "Collision.h"


std::string Collision::GetClass()
{
    return "Collision";
}

bool Collision::checkCollision(sf::FloatRect playerCol, std::list<sf::FloatRect> collidersToCheck)
{
    
    for (const auto& col : collidersToCheck)
    {
        if (playerCol.intersects(col))
        {
            return true;
        }
    }
    return false;
}
