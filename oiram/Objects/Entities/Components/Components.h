#pragma once

#include "../../../BaseObject.h"

class Entity;

class Components : public  BaseObject
{
public:
    Components() = default;
    Components(Entity* Parent);
    Entity* GetOwner();
    std::string GetClass() override;
    static std::string ClassName();

private:
    Entity* Owner;
};
