#include "Collision.h"

#include "../../Utils/WindowManager/WindowManager.h"


enum class CollisionDir {
    Haut,
    Bas,
    Gauche,
    Droite,
    Aucune
};

std::string Collision::GetClass()
{
    return "Collision";
}

bool Collision::checkCollision(sf::FloatRect entityCol)
{
    WindowManager* windowManager;
    std::list<sf::FloatRect> collidersToCheck;

    for (Renderer* item : windowManager->objectToDraw)
    {
        collidersToCheck.push_back(item->sprite.getGlobalBounds());
    }
    
    for (const sf::FloatRect& col : collidersToCheck)
    {
        if (entityCol.intersects(col))
        {
            return true;
        }
    }
    return false;
}

CollisionDir collisionDirection(const sf::FloatRect& objet1, const sf::FloatRect& objet2)
{
    float overlapLeft = objet2.left - (objet1.left + objet1.width);
    float overlapRight = (objet2.left + objet2.width) - objet1.left;
    float overlapTop = objet2.top - (objet1.top + objet1.height);
    float overlapBottom = (objet2.top + objet2.height) - objet1.top;
    
    if (overlapLeft > 0 && overlapRight > 0 && overlapTop > 0 && overlapBottom > 0) {
        if (overlapLeft < overlapRight && overlapLeft < overlapTop && overlapLeft < overlapBottom) {
            return CollisionDir::Gauche;
        } else if (overlapRight < overlapLeft && overlapRight < overlapTop && overlapRight < overlapBottom) {
            return CollisionDir::Droite;
        } else if (overlapTop < overlapLeft && overlapTop < overlapRight && overlapTop < overlapBottom) {
            return CollisionDir::Haut;
        } else if (overlapBottom < overlapLeft && overlapBottom < overlapRight && overlapBottom < overlapTop) {
            return CollisionDir::Bas;
        }
    }
    
    return CollisionDir::Aucune;
}

std::string Collision::ClassName()
{
    return "Collision";
}
