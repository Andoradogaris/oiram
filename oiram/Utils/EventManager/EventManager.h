#pragma once
#include "../../Engine.h"
class EventManager
{
public:
    EventManager() = default;
    sf::RenderWindow* windowscreen;
    void SetWindowRef(sf::RenderWindow* wind);
    void ListenEvent();
};
