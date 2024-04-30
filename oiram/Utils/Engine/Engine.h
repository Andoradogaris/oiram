#pragma once
#include "../../BaseObject.h"


class Engine : public BaseObject
{
public:
    sf::Clock clock;
    float deltaTime;
    float GetDeltaTime();
    static std::string ClassName();
    std::string GetClass() override;
    void StartEngine();
};
