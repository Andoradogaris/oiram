#pragma once

#include <map>
#include "../Components.h"
#include "../../../../Engine.h"
class Entity;



class Renderer : public Components
{
private:
    std::map<std::string, std::string> spriteMap;
public:
    
    sf::Texture texture;
    sf::Sprite sprite;
    void SetTexture(Entity* entity);
};
