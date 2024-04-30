#include "Collision.h"

#include "../../Utils/WindowManager/WindowManager.h"


std::string Collision::GetClass()
{
    return "Collision";
}

bool Collision::checkCollision(sf::FloatRect playerCol)
{
    /*WindowManager* windowManager;
    std::list<sf::FloatRect> collidersToCheck;

    for (auto item : windowManager->objectToDraw)
    {
        collidersToCheck.push_back(item.) 
    }
    auto collidersToCheck = windowManager->objectToDraw;
    
    for (const auto& col : collidersToCheck)
    {
        if (playerCol.intersects(col))
        {
            return true;
        }
    }
    return false;*/
}

std::string Collision::ClassName()
{
    return "Collision";
}
