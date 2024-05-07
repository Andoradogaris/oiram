#pragma once
#include <list>

#include "../../Objects/Entities/Components/Components.h"

class Collision : public Components
{
public :
    std::string GetClass() override;
    std::list<sf::FloatRect> collidersToCheck;
    bool checkCollision(sf::FloatRect playerCol);
    //CollisionDir collisionDirection();
    static std::string ClassName();
};

