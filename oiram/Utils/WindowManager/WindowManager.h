#pragma once
#define NOMINMAX
#include <windows.h>
#include <list>

#include "../../Objects/Entities/Components/Renderer/Renderer.h"

class WindowManager : public BaseObject
{
public:
    std::list<Renderer*> objectToDraw;
    void WindowDraw();
    std::string GetClass() override;
    void AddNewObject(Renderer* object);
    static std::string ClassName();
    
};
