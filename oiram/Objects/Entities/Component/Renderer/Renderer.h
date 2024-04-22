#pragma once
#include "../Components.h"
#include "../../../../Engine.h"
#include <map>

#include "../../Entity.h"

class Renderer : Components
{

    
public:
    std::map<Entity, std::string> spriteMap = {};
    sf::Texture texture;
    sf::Sprite sprite;
    void SetTexture(Entity& entity);
};
