#include "Player.h"
#include "../../../../Physics/Rigidbody/Rigidbody.h"
#include "../../../../Utils/Utils.h"
#include "../../../../Utils/ObjectManager/ObjectManager.h"


Player::Player()
{
}

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
    rb->velocity = Vector2<float>(0,0);
    rb->AddForce(Vector2<float>(-moveX, jumpValue), Impulse, _col, _rend, _deltaTime);
}

void Player::Move(float horizontal, float verticale)
{
    moveX = horizontal * speed;
    moveY = verticale * speed;
    rb->AddForce(Vector2<float>(moveX, 0), Constant,_col, _rend, _deltaTime = Utils::GetEngine()->deltaTime);
}

void Player::ResetMove()
{
    moveX = 0;
    moveY = 0;
}

void Player::ApplyMovement(float deltaTime)
{
    rb->Gravity(deltaTime,_col, _rend,1.f);
    renderer->sprite.move(rb->velocity.x *  _deltaTime, rb->velocity.y *  _deltaTime);
}
