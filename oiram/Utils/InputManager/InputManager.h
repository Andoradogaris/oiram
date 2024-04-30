#pragma once
#include "../../BaseObject.h"

class InputManager : public BaseObject
{
public:
    InputManager() = default;
    sf::RenderWindow* windowscreen;
    std::string GetClass() override;
    void SetWindowRef(sf::RenderWindow* wind);
    void ListenEvent();
    static std::string ClassName();
};
