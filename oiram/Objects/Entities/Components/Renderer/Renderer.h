#pragma once

#include "../Components.h"
#include "../../../../BaseObject.h"
#include <map>

#include "../../Entity.h"
#include "../../Characters/Player/Player.h"

class Renderer : public Components
{
public:
    std::string GetClass() override;

    Renderer();
    std::map<std::string, std::string> spriteMap;

    sf::Texture texture;
    sf::Sprite sprite;
    void SetTexture(Entity& entity);
};
