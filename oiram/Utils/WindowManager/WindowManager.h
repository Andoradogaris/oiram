#pragma once
#define NOMINMAX
#include <windows.h>
#include <list>
#include "../../Engine.h"
class Renderer;


class WindowManager
{
private:
    std::list<Renderer*> objectToDraw;
public:
    void WindowDraw();
    void AddNewObject(Renderer* object);
};
