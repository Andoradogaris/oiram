#include "Player.h"

#include "../../../../Physics/Collision/Collision.h"
#include "../../../../Physics/Rigidbody/Rigidbody.h"
#include "../../../../Utils/Utils.h"
#include "../../../../Utils/ObjectManager/ObjectManager.h"
#include "../../Components/CameraManager/CameraManager.h"
#include "../../Components/Transform/Transform.h"



Player::Player()
{
}

//fonction pour recuperer le nom de la classe
std::string Player::GetClass()
{
    return "Player";
}

//fonction static pour recuperer le nom de la classe (Utiliser par l'afactory)
std::string Player::ClassName()
{
    return "Player";
}

//fonction de saut de oiram
void Player::Jump()
{
    rb->velocity = Vector2<float>(0,0);
    rb->AddForce(Vector2<float>(-moveX*_deltaTime, jumpValue), Impulse, _col, _rend, _deltaTime);
}

//fonction de mouvement de oiram
void Player::Move(float horizontal, float verticale)
{
    moveX = horizontal * speed;
    moveY = verticale * speed;
    rb->AddForce(Vector2<float>(moveX, moveY), Constant,_col, _rend, _deltaTime = Utils::GetEngine()->deltaTime);
}

//fonction pour réinitialiser le mouvement de oiram
void Player::ResetMove()
{
    moveX = 0;
    moveY = 0;
    rb->velocity.x = 0;
    
}

//fonction pour deplacer la caméra ou deplacer oiram en fonction de sa position dans le monde
void Player::ApplyMovement(float deltaTime)
{
    //cas ou le oiram doit faire bouger la caméra
    if(Cast<Transform>(components.at("Transform"))->position.x < camera->maxX &&
        Cast<Transform>(components.at("Transform"))->position.x > camera->minX)
    {
        camera->MoveCamera(this);
        rb->Gravity(deltaTime,Cast<Collision>(components.at("Collision")), Cast<Renderer>(components.at("rend")),1.f);
    }
    //cas ou oiram bouge dans l'écran
    else
    {
        rb->Gravity(deltaTime,Cast<Collision>(components.at("Collision")), Cast<Renderer>(components.at("rend")),1.f);
        renderer->sprite.move(rb->velocity.x *  Utils::GetEngine()->deltaTime, rb->velocity.y *  Utils::GetEngine()->deltaTime);
    }
    Cast<Transform>(components.at("Transform"))->position.x += rb->velocity.x *  Utils::GetEngine()->deltaTime;
}

//fonction pour set le component camera en variable de oiram
void Player::InitializePlayerCam()
{
    camera = ObjectManager::get()->CastCreateObject<CameraManager>(CameraManager::ClassName());
}
