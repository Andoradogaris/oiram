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


void Entity::InitializeEntity()
{

    AddComponent("transf", ObjectManager::Get()->CastCreateObject<Transform>("Transform"));
    AddComponent("rend",ObjectManager::Get()->CastCreateObject<Renderer>("Renderer"));

}
