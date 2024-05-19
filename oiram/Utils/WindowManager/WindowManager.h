#pragma once
#define NOMINMAX
#include <windows.h>
#include <list>

#include "../../Objects/Entities/Components/Renderer/Renderer.h"
#include "../InputManager/InputManager.h"



class EntityManager;

class WindowManager : public BaseObject
{
public:
    EntityManager* entityManager;
    Player* player;
    sf::Clock clock;
    float deltaTime = 0.f;
    std::vector<std::pair<Renderer*, int>> objectToDraw;
    void WindowDraw();
    std::string GetClass() override;
    void AddNewObject(Renderer* object, int layerValue);
    static std::string ClassName();
    InputManager* inputManagerGame;
};
