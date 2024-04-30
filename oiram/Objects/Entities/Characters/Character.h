#pragma once
#include "../Entity.h"


class Rigidbody;

class Character : public Entity
{
public:
    std::string GetClass() override;
    Rigidbody* rb;
    void InitCharacterComponents();
    static std::string ClassName();
};
