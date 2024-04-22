#include "Renderer.h"

sf::Texture texture;
sf::Sprite sprite;
std::map<std::string, std::string> spriteMap = {
    {"Player","Assets/mario_projet.png"},
    {"Champignon", "Assets/cahmpignon_projet.png"},
    {"Obstacle","Assets/block_projet.png"}
};

void SetTexture(Entity& entity)
{
    if(!texture.loadFromFile(spriteMap[]));
}