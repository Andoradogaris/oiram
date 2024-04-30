#include "Character.h"

#include "../../../Physics/Rigidbody/Rigidbody.h"
#include "../../../Utils/ObjectManager/ObjectManager.h"

std::string Character::GetClass()
{
    return "Character";
}

void Character::InitCharacterComponents()
{
    rb = ObjectManager::Get()->CastCreateObject<Rigidbody>("Rigidbody");
    AddComponent("rigidbody",rb);
}

std::string Character::ClassName()
{
    return "Character";
}
