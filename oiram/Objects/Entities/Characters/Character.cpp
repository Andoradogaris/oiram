#include "Character.h"

#include "../../../Physics/Rigidbody/Rigidbody.h"

void Character::InitCharacterComponents()
{
    AddComponent(Rigidbody());
}
