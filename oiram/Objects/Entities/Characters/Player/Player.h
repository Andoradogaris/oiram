#pragma once
#include "../Character.h"
#include "../../../GameObject.h"

class Player : public Character
{

public:
    Player();
    std::string GetClass() override;
};
