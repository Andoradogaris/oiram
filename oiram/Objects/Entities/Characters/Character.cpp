#include "Character.h"
#include "../../../Physics/Collision/Collision.h"
#include "../../../Physics/Rigidbody/Rigidbody.h"
#include "../../../Utils/ObjectManager/ObjectManager.h"


void Character::ApplyMovement(float deltaTime)
{
}

std::string Character::GetClass()
{
    return "Character";
}

void Character::InitCharacterComponents()
{
    //On ajoute les components propres à notre personnage
    rb = ObjectManager::get()->CastCreateObject<Rigidbody>(Rigidbody::ClassName());
    col = ObjectManager::get()->CastCreateObject<Collision>(Collision::ClassName());

    AddComponent("rigidbody",rb);
    
}

std::string Character::ClassName()
{
    return "Character";
}
