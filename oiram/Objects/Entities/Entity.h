#pragma once


#include <unordered_map>

#include "../GameObject.h"
#include "../../BaseObject.h"
#include "Components/Components.h"


class Entity : public GameObject
{
private:

public:
    void InitializeEntity();
    void AddComponent(const std::string& ComponentID, Components* component);
    std::string GetClass() override;
    std::unordered_map<std::string, Components*> components;


};
