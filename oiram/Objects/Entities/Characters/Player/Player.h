#pragma once
#include "../Character.h"
#include "../../../../Utils/TemplateUtils.h"


class Player : public Character
{
public:
    Player();
    float speed = 5.f;
    float jumpValue = 30.f;
    float moveX = 0;
    float moveY = 0;
    std::string GetClass() override;
    static std::string ClassName();
    void Jump();
    void Move(float horizontal, float verticale);
    void ResetMove();
    void ApplyMovement(float deltaTime) override;
};
