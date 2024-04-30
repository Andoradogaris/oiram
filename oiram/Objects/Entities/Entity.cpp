#include "Entity.h"


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


void Entity::InitializeEntity()
{
    transform = ObjectManager::Get()->CastCreateObject<Transform>("Transform");
    renderer = ObjectManager::Get()->CastCreateObject<Renderer>("Renderer");
    AddComponent("transf", transform);
    AddComponent("rend",renderer);

}
