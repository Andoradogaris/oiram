#include "Entity.h"


void Entity::AddComponent(Components component)
{
    components.push_back(component);
}

void Entity::InitializeEntity()
{
    AddComponent(Transform());
    AddComponent(Renderer());
}