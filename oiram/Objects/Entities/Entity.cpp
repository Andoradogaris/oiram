#include "Entity.h"
#include "../../Physics/Collision/Collision.h"
#include "../../Utils/ObjectManager/ObjectManager.h"
#include "Components/Renderer/Renderer.h"
#include "Components/Transform/Transform.h"

//fonction pour ajouter les components dans la liste de component de l'entité
void Entity::AddComponent(const std::string& componentID, Components* component){
    if(!components.contains(componentID))
    {
        components.insert(std::pair(componentID, component));
    }else
    {
        components[componentID] = component;
    }
}

//fonction pour récupérer le nom de la classe
std::string Entity::GetClass()
{
    return "Entity";
}

std::string Entity::ClassName()
{
    return "Entity";
}

//fonction constructeur qui ajoute les différent renderer dans la map de component de l'entité
Entity::Entity()
{
    renderer = ObjectManager::get()->CastCreateObject<Renderer>("Renderer");
    AddComponent("rend",renderer);
    transform = ObjectManager::get()->CastCreateObject<Transform>("Transform");
    AddComponent("Transform", transform);
    colision = ObjectManager::get()->CastCreateObject<Collision>(Collision::ClassName());
    AddComponent("Collision", colision);
}

void Entity::InitializeEntity()
{

}
