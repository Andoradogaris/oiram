#include "EntityManager.h"
#include "../../Objects/Entities/Characters/Player/Player.h"
#include "../ObjectManager/ObjectManager.h"
#include "../Utils.h"
#include "../../Objects/Entities/Obstacles/Platform.h"
#include "../../Physics/Collision/Collision.h"
#include "../../Physics/Rigidbody/Rigidbody.h"

void EntityManager::CreateActor()
{
    Player* player = ObjectManager::Get()->CastCreateObject<Player>(Player::ClassName());
    RegisterActor(player, player->GetClass());
    player->InitializeEntity();
    player->InitCharacterComponents();
    Cast<Renderer>(player->components.at("rend"))->SetTexture(player);
    Platform* platform = ObjectManager::Get()->CastCreateObject<Platform>(Platform::ClassName());
    Cast<Renderer>(platform->components.at("rend"))->SetTexture(platform);
    RegisterActor(platform, platform->GetClass());
    
    window_manager->AddNewObject(Cast<Renderer>(player->components.at("rend")));
    window_manager->AddNewObject(Cast<Renderer>(platform->components.at("rend")));
    window_manager->player = player;
    rb = Cast<Rigidbody>(player->components.at("rigidbody"));
    rend = Cast<Renderer>(player->components.at("rend"));
    rend->sprite.move(500, 400);
    rb->useGravity = true;

    Cast<Renderer>(platform->components.at("rend"))->sprite.move(500,550);
    
    RegisterCollisionList();
}

void EntityManager::ActorAction()
{
    deltaTime = clock.restart().asSeconds();
    Utils::GetEngine()->deltaTime = deltaTime;
    for (EntityList* entity : entityList)
    {
        if(entity->name != "Platform")
        {
            Cast<Character>(entity->entity)->ApplyMovement(deltaTime);
            
        }
    }
}

std::string EntityManager::GetClass()
{
    return "EntityManager";
}

std::string EntityManager::ClassName()
{
    return "EntityManager";
}

void EntityManager::RegisterActor(Entity* actor, std::string className)
{
    EntityList* entity = new EntityList(className,actor);
    entityList.push_back(entity);
}

void EntityManager::RegisterCollisionList()
{
    
    for (size_t i = 0; i < entityList.size(); i++)
    {
        for(size_t j = 0; j < entityList.size(); j++)
        {
            if(i != j)
            {
                Cast<Collision>(entityList[i]->entity->components.at("Collision"))->collidersToCheck.push_back(Cast<Renderer>(entityList[j]->entity->components.at("rend"))->sprite.getGlobalBounds());
            }
            
        }

    }
}
