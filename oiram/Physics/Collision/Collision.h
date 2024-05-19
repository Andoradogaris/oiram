#pragma once
#include <list>

#include "../../Objects/Entities/Components/Components.h"

enum CollisionDir {
    Up,
    Down,
    Left,
    Right,
    Nothing
};

class Collision : public Components
{
public :
    CollisionDir col;
    std::string GetClass() override;
    std::list<sf::FloatRect> collidersToCheck;
    bool checkCollision(sf::FloatRect playerCol);
    std::vector<CollisionDir> collisionDirection(const sf::FloatRect& objet1);
    static std::string ClassName();
};

