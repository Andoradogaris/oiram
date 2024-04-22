#include "Collision.h"

bool checkCollision(sf::FloatRect playerCol, std::list<sf::FloatRect> collidersToCheck)
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