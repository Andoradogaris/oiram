#pragma once
#include "../Components.h"
#include "../../../../Engine.h"
#include <map>

#include "../../Entity.h"
#include "../../Characters/Player/Player.h"

class Renderer : Components
{
private:
    std::map<std::string, std::string> spriteMap;
public:
    
    sf::Texture texture;
    sf::Sprite sprite;
    void SetTexture(Entity& entity);
};
