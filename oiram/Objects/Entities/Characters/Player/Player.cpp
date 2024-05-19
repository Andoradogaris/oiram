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
    std::cout << "Jump" << std::endl;
    rb->velocity = Vector2<float>(0,0);
    rb->AddForce(Vector2<float>(-moveX, jumpValue), Impulse,Cast<Collision>(components.at("Collision")), Cast<Renderer>(components.at("rend")), Utils::GetEngine()->deltaTime);
}

void Player::Move(float horizontal, float verticale)
{
    moveX = horizontal * speed;
    moveY = verticale * speed;
    rb->AddForce(Vector2<float>(moveX, 0), Constant,Cast<Collision>(components.at("Collision")), Cast<Renderer>(components.at("rend")), Utils::GetEngine()->deltaTime);
}

void Player::ResetMove()
{
    moveX = 0;
    moveY = 0;
}

void Player::ApplyMovement(float deltaTime)
{
    if(Cast<Transform>(components.at("Transform"))->position.x < camera->maxX ||
        Cast<Transform>(components.at("Transform"))->position.x > camera->minX)
    {
        camera->MoveCamera(this);
        rb->Gravity(deltaTime,Cast<Collision>(components.at("Collision")), Cast<Renderer>(components.at("rend")),1.f);
        Cast<Transform>(components.at("Transform"))->position.x += rb->velocity.x; 
    }else
    {
        rb->Gravity(deltaTime,Cast<Collision>(components.at("Collision")), Cast<Renderer>(components.at("rend")),1.f);
        renderer->sprite.move(rb->velocity.x *  Utils::GetEngine()->deltaTime, rb->velocity.y *  Utils::GetEngine()->deltaTime);
        Cast<Transform>(components.at("Transform"))->position.x += rb->velocity.x; 
    }

}

void Player::InitializePlayerCam()
{
    camera = ObjectManager::get()->CastCreateObject<CameraManager>(CameraManager::ClassName());
}
