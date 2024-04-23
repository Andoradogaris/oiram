#pragma once
#include "../../Engine.h"
#include <windows.h>
#include <list>

#include "../../Objects/GameObject.h"
#include "../../Objects/Entities/Components/Renderer/Renderer.h"


class WindowManager
{
private:
    std::list<Renderer*> objectToDraw;
public:
    void WindowDraw();
    void AddNewObject(Renderer object);
};
