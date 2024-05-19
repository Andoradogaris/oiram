#include "ObjectManager.h"

ObjectManager* ObjectManager::m_instance = nullptr;

ObjectManager::ObjectManager()
{
}

//destructeur qui permet de suprimé toutes les entité crée de la mémoire de notre ordinateur
ObjectManager::~ObjectManager()
{
    gameObjectsList.clear();
}

//fonction singleton pour que l'objectmanager ne puisse se créer qu'une seul fois
ObjectManager* ObjectManager::get()
{
    if(m_instance == nullptr)
    {
        m_instance = new ObjectManager();
    }
    return m_instance;
}

//fonction pour récupérer le nom de la classe
std::string ObjectManager::GetClass()
{
    return "ObjectManager";
}

std::string ObjectManager::ClassName()
{
    return "ObjectManager";
}

