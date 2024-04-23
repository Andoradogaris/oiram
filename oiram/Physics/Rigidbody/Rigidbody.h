#pragma once
#include "../../Engine.h"
#include "../../Objects/Entities/Components/Components.h"

class Rigidbody: public Components
{
private:
    const float gravityScale = 0.1f;
    
    public :
        bool useGravity = false;
        float velocity = 1.f;
        Vector2<float> Gravity(float multiplier = 1.f);
        Vector2<float> Move(Vector2<float> positions);
};

