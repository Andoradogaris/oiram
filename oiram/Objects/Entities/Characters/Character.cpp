#include "Character.h"

#include "../../../Physics/Rigidbody/Rigidbody.h"

std::string Character::GetClass()
{
    return "Character";
}

void Character::InitCharacterComponents()
{
    AddComponent("rigid",new Rigidbody());
}
