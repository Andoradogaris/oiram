#pragma once
#include "../Character.h"

class Player : public Character
{

public:
    Player();
    std::string GetClass() override;
};
