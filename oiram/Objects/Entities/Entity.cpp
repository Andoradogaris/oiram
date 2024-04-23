#include "Entity.h"

#include "Components/Renderer/Renderer.h"
#include "Components/Transform/Transform.h"


void Entity::AddComponent(Components component)
{
    components.push_back(component);
}

std::string Entity::GetClass()
{
    return "";
}

void Entity::InitializeEntity()
{
    AddComponent(Transform());
    AddComponent(Renderer());
}

