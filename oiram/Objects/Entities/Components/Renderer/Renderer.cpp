#include "Renderer.h"

#include <filesystem>


std::string Renderer::GetClass()
{
    return "Renderer";
}

Renderer::Renderer()
{
    spriteMap = {
        {"Player","\\Assets\\mario_projet.png"},
        {"Champignon", "\\Assets\\cahmpignon_projet.png"},
        {"Obstacle","\\Assets\\block_projet.png"}
    };
}

void Renderer::SetTexture(Entity* entity)
{
    auto Path = std::filesystem::current_path().parent_path().parent_path().string();
    if(!texture.loadFromFile(Path.append(spriteMap.at( entity->GetClass()))))
    {
        std::cout << Path << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setScale(1,1);
}
