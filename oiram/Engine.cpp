#include "Engine.h"

float DeltaTime(sf::Clock& clock)
{
    return clock.getElapsedTime().asSeconds();
}