#pragma once
#include "../../BaseObject.h"
#include "../../Objects/Entities/Characters/Player/Player.h"

class InputManager : public BaseObject
{
public:
    InputManager() = default;
    sf::RenderWindow* windowscreen;
    std::string GetClass() override;
    void SetWindowRef(sf::RenderWindow* wind);
    void ListenEvent();
    static std::string ClassName();
    Player* player;
    bool right = false;
    bool left = false;
    bool up = false;
    bool down = false;
};
