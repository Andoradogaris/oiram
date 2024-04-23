#pragma once

#include "../../../../Maths/Vector2.h"
#include "../Components.h"


class Transform : public Components
{
public:
    Vector2<float> position;
    Vector2<float> rotation;
    Vector2<float> scale;
};
