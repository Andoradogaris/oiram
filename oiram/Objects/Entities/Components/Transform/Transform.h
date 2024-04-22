#pragma once
#include <SFML/System/Vector2.hpp>
#include "../Components.h"


class Transform : public Components
{
public:
    sf::Vector2f position;
    sf::Vector2f rotation;
    sf::Vector2f scale;
};
