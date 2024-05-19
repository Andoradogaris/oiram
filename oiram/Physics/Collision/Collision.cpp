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
            //return true si pour au moins un collider de la scène, il y a une collision avec notre objet parent
            return true;
        }
    }
    return false;
}

std::vector<CollisionDir> Collision::collisionDirection(const sf::FloatRect& entityCol)
{
    std::vector<CollisionDir> result;

    if (checkCollision(entityCol))
    {
        //On a une collision donc on cherche dans quelle direction
        for (const sf::FloatRect& colRect : collidersToCheck)
        {
            //Coin en haut à droite de la boite de collision du parent
            float entityColRight = entityCol.left + entityCol.width;
            //Coin en bas à gauche de la boite de collision du parent
            float entityColBottom = entityCol.top + entityCol.height;

            //Coin en bas à droite de la boite de collision de l'entité de la collision
            float colRectRight = colRect.left + colRect.width;
            //Coin en bas à gauche de la boite de collision de l'entité de la collision
            float colRectBottom = colRect.top + colRect.height;

            //Si la droite d'un objet heurte la gauche du parent
            bool LeftCheckResult = colRect.left - entityColRight <= 0;
            //Si la gauche d'un objet heurte la droite du parent
            bool RightCheckResult = colRectRight - entityCol.left >= 0;
            //Si le bas d'un objet heurte le haut du parent
            bool TopCheckResult = colRect.top - entityColBottom <= 0;
            //Si le bas d'un objet heurte le haut du parent
            bool BottomCheckResult = colRectBottom - entityCol.top >= 0;

            //On vérifie que les objets soient bien superposés sur la hauteur également
            bool overlapLeft = LeftCheckResult && (TopCheckResult || BottomCheckResult);
            bool overlapRight = RightCheckResult && (TopCheckResult || BottomCheckResult);
            bool overlapTop =  TopCheckResult && (LeftCheckResult || RightCheckResult);
            bool overlapBottom = BottomCheckResult && (LeftCheckResult || RightCheckResult);
            
            std::cout << "overlapLeft : " << overlapLeft << std::endl;
            std::cout << "overlapRight : " << overlapRight << std::endl;
            std::cout << "overlapTop : " << overlapTop << std::endl;
            std::cout << "overlapBottom : " << overlapBottom << std::endl;
            
            // if (overlapLeft && (entityCol.top <= colRectBottom || entityColBottom >= colRect.top))
            // {
            //     result.push_back(Left);
            // }
            //
            // if (overlapRight && (entityCol.top <= colRectBottom || entityColBottom >= colRect.top))
            // {
            //     result.push_back(Right);
            // }
            
            if (overlapBottom && (entityCol.left <= colRectRight || entityColRight >= colRect.left))
            {
                result.push_back(Down);
            }
            
            if (overlapTop && (entityCol.left <= colRectRight || entityColRight >= colRect.left))
            {
                result.push_back(Up);
            }
        }

        std::cout << result.size() << std::endl;

        if(!result.empty())
        {
            return result;
        }
    }
    result.push_back(Nothing);
    
    return result;
}

std::string Collision::ClassName()
{
    return "Collision";
}
