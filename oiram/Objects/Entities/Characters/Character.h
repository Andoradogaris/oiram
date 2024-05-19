#pragma once
#include "../Entity.h"


class Rigidbody;
class Collision;

class Character : public Entity
{
public:
    virtual void ApplyMovement(float deltaTime);
    std::string GetClass() override;
    Rigidbody* rb;
    void InitCharacterComponents();
    static std::string ClassName();
};
