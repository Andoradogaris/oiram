#include "Player.h"

#include "../../../../Physics/Rigidbody/Rigidbody.h"
#include "../../../../oiram/Utils/TemplateUtils.h"
#include "../../../../Utils/Utils.h"
#include "../../../../Utils/ObjectManager/ObjectManager.h"

std::string Player::GetClass()
{
    return "Player";
}

std::string Player::ClassName()
{
    return "Player";
}

void Player::Jump()
{
    Rigidbody* rb = Cast<Rigidbody>(components.at("rigidbody"));
    rb->AddForce(Vector2<float>(moveX, jumpValue), Impulse, Utils::GetEngine()->deltaTime);
}

void Player::Move(float horizontal, float verticale)
{
    moveX = horizontal;
    moveY = verticale;
}

void Player::ResetMove()
{
    moveX = 0;
    moveY = 0;
}
