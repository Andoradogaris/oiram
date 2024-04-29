#pragma once
#include "../Entity.h"

class Character : public Entity
{
public:
    std::string GetClass() override;

    void InitCharacterComponents();
};
