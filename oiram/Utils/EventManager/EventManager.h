#pragma once
#include "../../BaseObject.h"

class EventManager : public BaseObject
{
public:
    EventManager() = default;
    sf::RenderWindow* windowscreen;
    std::string GetClass() override;
    void SetWindowRef(sf::RenderWindow* wind);
    void ListenEvent();
};
