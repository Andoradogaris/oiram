#pragma once
#include "../Components.h"


struct EntityList;
class WindowManager;
class Player;
class Transform;
class Renderer;

class CameraManager : public Components
{
public:
    Transform* playerTransform;
    std::vector<EntityList*>* entityList;
    static std::string ClassName();
    WindowManager* window_manager;
    std::pair<Renderer*, int> rendererPair;
    float maxX = 1920;
    float minX = 500;
    void MoveCamera(Player* player);
    void SetPlayerTransform(Player* player);
};
