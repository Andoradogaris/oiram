#pragma once
#include "../Character.h"
#include "../../../../Utils/TemplateUtils.h"


class Player : public Character
{
public:
    float speed = 5.f;
    float jumpValue = 30.f;
    float moveX;
    float moveY;
    std::string GetClass() override;
    static std::string ClassName();
    void Jump();
    void Move(float horizontal, float verticale);
    void ResetMove();
};
