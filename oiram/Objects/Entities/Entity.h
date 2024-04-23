#pragma once

#include <list>

#include "../../Engine.h"
#include "Components/Components.h"



class Entity
{

    
public:
    Entity() = default;
    void InitializeEntity();
    void AddComponent(Components component);
    virtual std::string GetClass();
    std::list<Components> components;
};
