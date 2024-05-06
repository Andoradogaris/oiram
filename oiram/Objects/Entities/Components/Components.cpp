#include "Components.h"

Components::Components(Entity* Parent)
{
    Owner = Parent;
}

Entity* Components::GetOwner()
{
    return Owner;
}

std::string Components::GetClass()
{
    return "Components";
}

std::string Components::ClassName()
{
    return "Components";
}
