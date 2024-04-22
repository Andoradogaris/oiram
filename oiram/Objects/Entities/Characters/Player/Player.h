#pragma once
#include "../Character.h"
#include "../../../GameObject.h"

class Player : public Character
{
public:
    __override std::string GetClass();
};
