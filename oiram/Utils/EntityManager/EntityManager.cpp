#include "EntityManager.h"
#include "../../Objects/Entities/Characters/Player/Player.h"
#include "../ObjectManager/ObjectManager.h"
#include "../Utils.h"
#include "../../Physics/Rigidbody/Rigidbody.h"

void EntityManager::CreateActor()
{
    Player* player = ObjectManager::Get()->CastCreateObject<Player>(Player::ClassName());
    RegisterActor(player, player->GetClass());
    player->InitializeEntity();
    player->InitCharacterComponents();
    Cast<Renderer>(player->components.at("rend"))->SetTexture(player);
    window_manager->AddNewObject(Cast<Renderer>(player->components.at("rend")));
    window_manager->player = player;
    rb = Cast<Rigidbody>(player->components.at("rigidbody"));
    rend = Cast<Renderer>(player->components.at("rend"));
    rend->sprite.move(500, 500);
    rb->useGravity = true;
}

void EntityManager::ActorAction()
{
    deltaTime = clock.restart().asSeconds();
    Utils::GetEngine()->deltaTime = deltaTime;
    for (EntityList* entity : entityList)
    {
        if(entity->name == "Player")
        {
            rb = Cast<Rigidbody>(Cast<Player>(entity->entity)->components.at("rigidbody"));
            rend = Cast<Renderer>(Cast<Player>(entity->entity)->components.at("rend"));
            rb->Gravity(deltaTime,1.f);
            rend->sprite.move(rb->velocity.x * deltaTime, rb->velocity.y * deltaTime);
        }
        else if (entity->name == "Boomga")
        {
            
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

void EntityManager::RegisterActor(GameObject* actor, std::string className)
{
    EntityList* entity = new EntityList(className,actor);
    entityList.push_back(entity);
}
