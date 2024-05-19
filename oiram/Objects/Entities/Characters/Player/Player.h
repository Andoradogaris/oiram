#pragma once
#include "../Character.h"
#include "../../../../Utils/TemplateUtils.h"
#include "../../../../Utils/Utils.h"


class CameraManager;

class Player : public Character
{
public:
    bool resetVelocity = true;
    bool jumping = false;
    CameraManager* camera;
    Player();
    float speed = 500.f;
    float jumpValue = 30.f;
    float moveX = 0;
    float moveY = 0;
    Collision* _col = Cast<Collision>(components.at("Collision"));
    Renderer* _rend = Cast<Renderer>(components.at("rend"));
    float _deltaTime = Utils::GetEngine()->deltaTime;
    std::string GetClass() override;
    static std::string ClassName();
    void Jump();
    void Move(float horizontal, float verticale);
    void ResetMove();
    void ApplyMovement(float deltaTime) override;
    void InitializePlayerCam();
};
