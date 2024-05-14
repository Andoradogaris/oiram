#include "Entity.h"


#include "../../Physics/Collision/Collision.h"
#include "../../Utils/ObjectManager/ObjectManager.h"
#include "Components/Renderer/Renderer.h"
#include "Components/Transform/Transform.h"

void Entity::AddComponent(const std::string& componentID, Components* component){
    if(!components.contains(componentID))
    {
        components.insert(std::pair(componentID, component));
    }else
    {
        components[componentID] = component;
    }
}

std::string Entity::GetClass()
{
    return "Entity";
}

std::string Entity::ClassName()
{
    return "Entity";
}


Entity::Entity()
{
    renderer = ObjectManager::get()->CastCreateObject<Renderer>("Renderer");
    AddComponent("rend",renderer);
    transform = ObjectManager::get()->CastCreateObject<Transform>("Transform");
    AddComponent("transf", transform);
    colision = ObjectManager::get()->CastCreateObject<Collision>(Collision::ClassName());
    AddComponent("Collision", colision);
}

void Entity::InitializeEntity()
{

}
