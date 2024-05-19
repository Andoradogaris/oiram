#include "Components.h"

//fonction pour set et get le parent d'une classe
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
