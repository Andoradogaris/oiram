#include "WindowManager.h"


void WindowManager::WindowDraw()
{
    RECT desktop;
    GetWindowRect(GetDesktopWindow(), &desktop);
    int horizontal = desktop.right;
    int vertical = desktop.bottom;

    sf::RenderWindow window(sf::VideoMode(horizontal, vertical), "My window");
}