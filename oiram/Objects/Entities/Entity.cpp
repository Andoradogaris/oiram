#include "Entity.h"



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

    AddComponent("transf", new Transform());
    AddComponent("rend",new Renderer());

}
