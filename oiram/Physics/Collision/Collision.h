#pragma once
#include <list>

#include "../../Objects/Entities/Components/Components.h"
#include "../../Engine.h"

class Collision : Components
{
public :
    bool checkCollision(sf::FloatRect playerCol, std::list<sf::FloatRect> collidersToCheck);
};

