#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Maths/Vector2.h"
#include <random>

class Engine
{

public:
    sf::Clock clock;
    float deltaTime = clock.getElapsedTime().asSeconds();
};
