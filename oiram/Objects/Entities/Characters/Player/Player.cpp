#include "Player.h"
#include "../../../../Physics/Rigidbody/Rigidbody.h"
#include "../../../../Utils/Utils.h"
#include "../../../../Utils/ObjectManager/ObjectManager.h"
#include "../../Components/CameraManager/CameraManager.h"
#include "../../Components/Transform/Transform.h"



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
    jumping = true;
    rb->velocity = Vector2<float>(0,0);
    rb->AddForce(Vector2<float>(-moveX*_deltaTime, jumpValue), Impulse, _col, _rend, _deltaTime);
}

void Player::Move(float horizontal, float verticale)
{
    moveX = horizontal * speed;
    moveY = verticale * speed;
    rb->AddForce(Vector2<float>(moveX, moveY), Constant,_col, _rend, _deltaTime = Utils::GetEngine()->deltaTime);
}

void Player::ResetMove()
{
    moveX = 0;
    moveY = 0;
    if(!jumping)
    {
        rb->velocity = Vector2<float>(0,0);
    }
}

void Player::ApplyMovement(float deltaTime)
{
    if(Cast<Transform>(components.at("Transform"))->position.x < camera->maxX &&
        Cast<Transform>(components.at("Transform"))->position.x > camera->minX)
    {
        if(resetVelocity)
        {
            rb->velocity = Vector2<float>(0,0);
            resetVelocity = false;
        }
        camera->MoveCamera(this);
        rb->Gravity(deltaTime,Cast<Collision>(components.at("Collision")), Cast<Renderer>(components.at("rend")),1.f);
    }else
    {
        resetVelocity = true;
        rb->Gravity(deltaTime,Cast<Collision>(components.at("Collision")), Cast<Renderer>(components.at("rend")),1.f);
        renderer->sprite.move(rb->velocity.x *  Utils::GetEngine()->deltaTime, rb->velocity.y *  Utils::GetEngine()->deltaTime);
        
    }
    Cast<Transform>(components.at("Transform"))->position.x += rb->velocity.x *  Utils::GetEngine()->deltaTime;
    // std::cout << rb->velocity.x<< std::endl;
}

void Player::InitializePlayerCam()
{
    camera = ObjectManager::get()->CastCreateObject<CameraManager>(CameraManager::ClassName());
}
