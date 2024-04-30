#include "ObjectManager.h"

ObjectManager* ObjectManager::m_instance = nullptr;

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
    gameObjectsList.clear();
}

ObjectManager* ObjectManager::Get()
{
    if(m_instance == nullptr)
    {
        m_instance = new ObjectManager();
    }
    return m_instance;
}


std::string ObjectManager::GetClass()
{
    return "ObjectManager";
}

std::string ObjectManager::ClassName()
{
    return "ObjectManager";
}
