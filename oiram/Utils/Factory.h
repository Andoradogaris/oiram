#pragma once
#include "../BaseObject.h"

class Factory: public BaseObject
{
    std::string GetClass() override;
};

inline std::string Factory::GetClass()
{
    return "Factory";
}

