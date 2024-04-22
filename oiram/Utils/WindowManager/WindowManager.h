#pragma once
#include "../../Engine.h"
#include <windows.h>
#include <list>

#include "../../Objects/GameObject.h"

class WindowManager
{
private:
    std::list<GameObject> objectToDraw;
public:
    void WindowDraw();
    void AddNewObject(GameObject& object);
};
