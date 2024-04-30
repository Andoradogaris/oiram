// oiram.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//
#include "BaseObject.h"
#include <iostream>

#include "Utils/ObjectManager/ObjectManager.h"
#include "Utils/WindowManager/WindowManager.h"


int main()
{

    WindowManager* window_manager = ObjectManager::Get()->CastCreateObject<WindowManager>(WindowManager::ClassName());
    window_manager->WindowDraw();

    
    
    return 0;
}
