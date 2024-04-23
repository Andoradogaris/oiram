#pragma once

#include <list>

#include "../../Engine.h"
#include "Components/Components.h"
#include "Components/Renderer/Renderer.h"
#include "Components/Transform/Transform.h"


class Entity
{

    
public:
    void InitializeEntity();
    void AddComponent(Components component);
    virtual std::string GetClass();
    std::list<Components> components;
};
