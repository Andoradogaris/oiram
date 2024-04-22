#include "Collision.h"



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
