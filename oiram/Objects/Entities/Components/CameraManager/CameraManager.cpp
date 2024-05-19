#include "CameraManager.h"

#include "../../../../Physics/Rigidbody/Rigidbody.h"
#include "../../Characters/Player/Player.h"
#include "../Renderer/Renderer.h"
#include "../../../../Utils/Utils.h"
#include "../../../../Utils/WindowManager/WindowManager.h"
//fonction static pour recuper le nom de la classe (utiliser par l'afactory)
std::string CameraManager::ClassName()
{
    return "CameraManager";
}

//fonction pour deplacer chaque objet du monde a l'écran 
void CameraManager::MoveCamera(Player* player)
{
    Cast<Renderer>(player->components.at("rend"))->sprite.move(0, player->rb->velocity.y *  Utils::GetEngine()->deltaTime);
    for(size_t i = 0;  i < window_manager->objectToDraw.size(); i++)
    {
        
        rendererPair = window_manager->objectToDraw.at(i);
        if(rendererPair.first->sprite.getPosition().x != player->renderer->sprite.getPosition().x
            || rendererPair.first->sprite.getPosition().y != player->renderer->sprite.getPosition().y)
        {
            rendererPair.first->sprite.move(-player->rb->velocity.x*Utils::GetEngine()->deltaTime,0);
        }
    }
}

//fonction pour set le transform de oiram en variable de la classe
void CameraManager::SetPlayerTransform(Player* player)
{
    playerTransform = Cast<Transform>(player->components.at("Transform"));
}
