#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Maths/Vector2.h"
#include <random>

class BaseObject
{

public:
    sf::Clock clock;
    float deltaTime = clock.getElapsedTime().asSeconds();
    virtual std::string GetClass();
    static std::string ClassName();
};
