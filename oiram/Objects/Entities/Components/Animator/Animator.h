#pragma once

#include "../Components.h"
#include "../../../../BaseObject.h"
#include <map>

#include "../../Entity.h"
#include "../../Characters/Player/Player.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Animator : public Components {
public:
    struct Animation {
        std::string name;
        std::vector<sf::Sprite> frames;
    };

    std::vector<Animation> animations;
    int currentAnimation = -1; // Index de l'animation actuelle, initialisé à -1
    int currentFrame = 0; // Index de l'image actuelle au sein de l'animation
    float currentTime = 0.0f; // Temps écoulé pour l'animation actuelle

    Animator();

    // Ajouter une animation
    void AddAnimation(const std::string& name);

    // Définir l'animation actuelle
    void SetAnimation(const std::string& name);

    // Mettre à jour l'animation en fonction du temps écoulé
    void UpdateAnimation(float deltaTime);

    // Rechercher l'index d'une animation par son nom
    int FindAnimationIndex(const std::string& name) const;

private:
    // Fonction privée pour mettre à jour l'image actuelle en fonction du temps écoulé
    void UpdateCurrentFrame(float deltaTime);
};
