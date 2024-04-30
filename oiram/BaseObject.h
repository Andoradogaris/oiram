#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Maths/Vector2.h"

class BaseObject
{

public:
    virtual std::string GetClass();
    static std::string ClassName();
};
