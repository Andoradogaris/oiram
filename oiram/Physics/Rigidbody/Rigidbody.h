#pragma once
#include "../../Objects/Entities/Components/Components.h"


class Renderer;
class Collision;

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
    void Gravity(float deltaTime,Collision* col, Renderer* rend, float multiplier = 1.f);
    void AddForce(const Vector2<float> force, ForceMode mode, Collision* col, Renderer* rend, float deltaTime=0);
    void CheckCollisions(Collision* col, Renderer* rend);
    static std::string ClassName();
};