#pragma once
#include "../Character.h"
#include "../../../GameObject.h"

class Player : public Character
{
public:
    float jumpValue = 30.f;
    float moveX;
    float moveY;
    std::string GetClass() override;
    static std::string ClassName();
    void Jump();
    void Move(float horizontal, float verticale);
    void ResetMove();
};
