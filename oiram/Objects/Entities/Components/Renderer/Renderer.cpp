#include "Renderer.h"
#include <filesystem>

std::string Renderer::GetClass()
{
    return "Renderer";
}

//fonction constructeur qui initialise la map avec les chemins des textures du jeu
Renderer::Renderer()
{
    spriteMap = {
        {"Player","\\Assets\\mario_projet.png"},
        {"Champignon", "\\Assets\\cahmpignon_projet.png"},
        {"Platform","\\Assets\\block_projet.png"}
    };
}

//fonction pour load la textures sur le sprite
void Renderer::SetTexture(Entity* entity)
{
    std::string Path = std::filesystem::current_path().parent_path().parent_path().string();
    if(!texture.loadFromFile(Path.append(spriteMap.at( entity->GetClass()))))
    {
        std::cout << Path << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setScale(1,1);
}

//fonction static pour récupérer le nom de la classe
std::string Renderer::ClassName()
{
    return "Renderer";
}
