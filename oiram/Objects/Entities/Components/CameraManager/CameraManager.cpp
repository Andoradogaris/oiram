﻿#include "CameraManager.h"

#include "../../../../Physics/Rigidbody/Rigidbody.h"
#include "../../Characters/Player/Player.h"
#include "../Renderer/Renderer.h"
#include "../../../../Utils/Utils.h"
#include "../../../../Utils/WindowManager/WindowManager.h"

std::string CameraManager::ClassName()
{
    return "CameraManager";
}

void CameraManager::MoveCamera(Player* player)
{
    Cast<Renderer>(player->components.at("rend"))->sprite.move(0, player->rb->velocity.y *  Utils::GetEngine()->deltaTime);
    for(size_t i = 0;  i < window_manager->objectToDraw.size(); i++)
    {
        rendererPair = window_manager->objectToDraw.at(i);
        if(rendererPair.first->sprite.getPosition().x > 10)
        {
            std::cout << "test" << std::endl;
        }
    }
}

void CameraManager::SetPlayerTransform(Player* player)
{
    playerTransform = Cast<Transform>(player->components.at("Transform"));
}