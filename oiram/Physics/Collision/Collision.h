#pragma once
#include <list>

#include "../../Objects/Entities/Components/Components.h"

class Collision : Components
{
public :
    bool checkCollision(sf::FloatRect playerCol, std::list<sf::FloatRect> collidersToCheck);
};

