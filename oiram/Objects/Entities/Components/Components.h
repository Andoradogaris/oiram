#pragma once

#include "../../../BaseObject.h"

class Components : public  BaseObject
{
public:
    std::string GetClass() override;
    static std::string ClassName();
};
