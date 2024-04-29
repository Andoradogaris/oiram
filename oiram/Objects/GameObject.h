#pragma once
#include "../BaseObject.h"

class GameObject : public  BaseObject
{
public:
    std::string GetClass() override;
    std::string name;
};
