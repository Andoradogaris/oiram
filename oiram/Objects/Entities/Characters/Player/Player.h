#pragma once
#include "../Character.h"
#include "../../../GameObject.h"

class Player : public Character
{
public:
    std::string GetClass();
};
