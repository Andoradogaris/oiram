#pragma once

#include <list>

#include "../../Engine.h"
#include "Components/Components.h"


class Entity
{
private:
    std::list<Components> components;
public:
    void InitializeEntity();
    void AddComponent(Components component);
};
