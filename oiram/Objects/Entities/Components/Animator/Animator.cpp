// #include "Animator.h"
//
// Animator::Animator() {}
//
// void Animator::AddAnimation(const std::string& name) {
//     Animation animation;
//     animation.name = name;
//     animations.push_back(animation);
// }
//
// void Animator::SetAnimation(const std::string& name) {
//     currentAnimation = FindAnimationIndex(name);
//     currentFrame = 0;
//     currentTime = 0.0f;
// }
//
// void Animator::UpdateAnimation(float deltaTime) {
//     if (currentAnimation == -1) {
//         return; // Aucune animation n'est sélectionnée
//     }
//
//     UpdateCurrentFrame(deltaTime);
//
//     // Mettre à jour l'objet avec les données de l'image actuelle
//     // ...
// }
//
// int Animator::FindAnimationIndex(const std::string& name) const {
//     for (size_t i = 0; i < animations.size(); i++) {
//         if (animations[i].name == name) {
//             return i;
//         }
//     }
//     return -1; // Animation non trouvée
// }
//
// void Animator::UpdateCurrentFrame(float deltaTime) {
//     Animation& currentAnimation = animations[currentAnimation];
//
//     currentTime += deltaTime;
//
//     // Avancer vers l'image suivante si nécessaire
//     while (currentTime > currentAnimation.frames[currentFrame].getTextureRect().height) {
//         currentTime -= currentAnimation.frames[currentFrame].getTextureRect().height;
//         currentFrame++;
//
//         // Boucler vers le début si la fin de l'animation est atteinte
//         if (currentFrame >= currentAnimation.frames.size()) {
//             currentFrame = 0;
//         }
//     }
// }