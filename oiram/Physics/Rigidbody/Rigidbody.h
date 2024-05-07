#pragma once
// #include "../../BaseObject.h"
#include "../../Objects/Entities/Components/Components.h"


enum ForceMode
{
    Constant,
    Impulse,
    Explosive
};

class Rigidbody: public Components
{
private:
    const float gravityScale = 9.81f;
    double timer = 0.f;
    
public :
    bool useGravity = false;
    Vector2<float> velocity = 0.f;
    Vector2<float> test = 0.f;
    float mass = 80;
    void Gravity(float deltaTime, float multiplier = 1.f);
    void AddForce(const Vector2<float> force, ForceMode mode, float deltaTime=0);
    void CheckCollisions();
    static std::string ClassName();
};