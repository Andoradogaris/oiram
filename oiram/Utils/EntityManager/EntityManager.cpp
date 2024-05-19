#include "EntityManager.h"
#include "../../Objects/Entities/Characters/Player/Player.h"
#include "../ObjectManager/ObjectManager.h"
#include "../Utils.h"
#include "../../Objects/Entities/Components/CameraManager/CameraManager.h"
#include "../../Objects/Entities/Components/Transform/Transform.h"
#include "../../Objects/Entities/Obstacles/Platform.h"
#include "../../Physics/Collision/Collision.h"
#include "../../Physics/Rigidbody/Rigidbody.h"

void EntityManager::CreateActor()
{
    //On créé un joueur
    Player* player = ObjectManager::get()->CastCreateObject<Player>(Player::ClassName());
    Renderer* playerRend = Cast<Renderer>(player->components.at("rend"));
    player->InitializeEntity();
    player->InitCharacterComponents();
    player->InitializePlayerCam();
    player->camera->window_manager = window_manager;
    player->camera->entityList = &entityList;
    player->camera->SetPlayerTransform(player);
    Cast<Renderer>(player->components.at("rend"))->SetTexture(player);
    RegisterActor(player, player->GetClass());

    //On créé une plateforme
    Platform* platform = ObjectManager::get()->CastCreateObject<Platform>(Platform::ClassName());
    Renderer* platformRend = Cast<Renderer>(platform->components.at("rend"));
    platformRend->SetTexture(platform);
    platformRend->sprite.scale(100.f, 1.f);

    RegisterActor(platform, platform->GetClass());

    //On créé une plateforme
    Platform* platform2 = ObjectManager::get()->CastCreateObject<Platform>(Platform::ClassName());
    Renderer* platform2Rend = Cast<Renderer>(platform2->components.at("rend"));
    platform2Rend->SetTexture(platform2);
    platform2Rend->sprite.scale(1.f, 5.f);
    RegisterActor(platform2, platform2->GetClass());
    
    window_manager->AddNewObject(playerRend, 1);
    window_manager->AddNewObject(platformRend, 2);
    window_manager->AddNewObject(platform2Rend, 2);
    window_manager->player = player;
    rb = Cast<Rigidbody>(player->components.at("rigidbody"));
    playerRend->sprite.move(500, 510);
    Cast<Transform>(player->components.at("Transform"))->position.x = playerRend->sprite.getPosition().x;
    rb->useGravity = true;

    platformRend->sprite.move(0,550);
    platform2Rend->sprite.move(600,500);
    
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
                Collision* entityCol = Cast<Collision>(entityList[i]->entity->components.at("Collision"));
                Renderer* entityRend = Cast<Renderer>(entityList[j]->entity->components.at("rend"));
                entityCol->collidersToCheck.push_back(entityRend->sprite.getGlobalBounds());
            }
            
        }

    }
}
