#include "Character.h"

#include "../../../Physics/Rigidbody/Rigidbody.h"
#include "../../../Utils/ObjectManager/ObjectManager.h"

std::string Character::GetClass()
{
    return "Character";
}

void Character::InitCharacterComponents()
{
    AddComponent("rigidbody",ObjectManager::Get()->CastCreateObject<Rigidbody>("Rigidbody"));
}
