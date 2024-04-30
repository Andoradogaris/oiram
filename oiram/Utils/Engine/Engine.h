#pragma once
#include "../../BaseObject.h"


class Engine : public BaseObject
{
public:
    static std::string ClassName();
    std::string GetClass() override;
    void StartEngine();
};
