#pragma once
#include <list>

#include "../../Objects/Entities/Components/Components.h"

enum class CollisionDir {
    Haut,
    Bas,
    Gauche,
    Droite,
    Aucune
};

class Collision : public Components
{
public :
    CollisionDir col;
    std::string GetClass() override;
    bool checkCollision(sf::FloatRect playerCol);
    std::list<CollisionDir> collisionDirection();
    static std::string ClassName();
};

