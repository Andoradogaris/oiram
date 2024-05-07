#pragma once
#include "../Entity.h"

class Platform : public Entity
{
public:
    static std::string ClassName();
    std::string GetClass() override;
};
