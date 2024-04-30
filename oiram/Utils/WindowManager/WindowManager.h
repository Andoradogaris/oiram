#pragma once
#define NOMINMAX
#include <windows.h>
#include <list>

#include "../../Objects/Entities/Components/Renderer/Renderer.h"
#include "../InputManager/InputManager.h"

class WindowManager : public BaseObject
{
public:
    sf::Clock clock;
    float deltaTime = 0.f;
    std::list<Renderer*> objectToDraw;
    void WindowDraw();
    std::string GetClass() override;
    void AddNewObject(Renderer* object);
    static std::string ClassName();
    InputManager* inputManagerGame;
};
