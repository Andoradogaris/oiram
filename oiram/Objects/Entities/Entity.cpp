#include "Entity.h"

#include "Components/Transform/Transform.h"

<<<<<<< Updated upstream
=======

// void Entity::AddComponent(std::map<std::string, Components> component)
// {
//     // components.push_back(component);
// }

>>>>>>> Stashed changes
void Entity::AddComponent(Components component)
{
    components.push_back(component);
}

void Entity::InitializeEntity()
{
    // std::map<std::string, Components> transform = {"transf",Transform()};
    // AddComponent(transform);
    // AddComponent({"rend",Renderer()});
    AddComponent(Transform());
    //AddComponent(Renderer());
}