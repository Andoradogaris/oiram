#include "Animator.h"

#include "../Renderer/Renderer.h"

Animator::Animator()
{
    rend = Cast<Renderer>(GetOwner()->components.at("Renderer"));
}

void Animator::AddAnimation(const std::string& name) {
    Animation animation;
    animation.name = name;
    animations.push_back(animation);
}

void Animator::SetAnimation(const std::string& name) {
    currentAnimation = FindAnimationIndex(name);
    currentFrame = 0;
    currentTime = 0.0f;
}

void Animator::UpdateAnimation(float deltaTime) {
    if (currentAnimation == -1) {
        return;
    }

    UpdateCurrentFrame(deltaTime);
    
}

int Animator::FindAnimationIndex(const std::string& name) const {
    for (size_t i = 0; i < animations.size(); i++) {
        if (animations[i].name == name) {
            return i;
        }
    }
    return -1; // Animation non trouvée
}

void Animator::UpdateCurrentFrame(float deltaTime)
{
    Animation& _currentAnimation = animations.at(currentAnimation);

    currentTime += deltaTime;

    // Avancer vers l'image suivante si nécessaire
    while (currentTime > _currentAnimation.frames[currentFrame].getTextureRect().height)
    {
        currentTime -= _currentAnimation.frames[currentFrame].getTextureRect().height;
        currentFrame++;

        // Boucler vers le début si la fin de l'animation est atteinte
        if (currentFrame >= _currentAnimation.frames.size()) {
            currentFrame = 0;
        }
    }
    //Entity.components.at("Renderer")
    //SetFrame()
}

void Animator::SetFrame()
{
    rend->sprite.setTexture(*animations.at(currentAnimation).frames.at(currentFrame).getTexture());
}