#pragma once
#include <list>

#include "../../Objects/Entities/Components/Components.h"

class Collision : public Components
{
public :
    std::string GetClass() override;
    bool checkCollision(sf::FloatRect playerCol, std::list<sf::FloatRect> collidersToCheck);
    static std::string ClassName();
};

