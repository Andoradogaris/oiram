#pragma once
#include <SFML/System/Vector2.hpp>
#include "../Components.h"


class Transform : public Components
{
public:
    std::string GetClass() override;
    Vector2<float> position;
    Vector2<float> rotation;
    Vector2<float> scale;
};
