#pragma once

#include <list>
// #include <map>

#include "../../Engine.h"
#include "Components/Components.h"


class Entity
{
private:
    std::list<Components> components;
public:
    void InitializeEntity();
    void AddComponent(Components component);
    virtual std::string GetClass();
<<<<<<< Updated upstream
=======
    std::list< Components> components;
>>>>>>> Stashed changes
};
