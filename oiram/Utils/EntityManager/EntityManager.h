#pragma once
#include "../../Objects/GameObject.h"
#include "../WindowManager/WindowManager.h"

struct EntityList
{
    EntityList(std::string& myName, Character* myEntity):name(myName),entity(myEntity){};
    std::string name;
    Character* entity;    
};

class EntityManager : public BaseObject
{
public:
    Rigidbody* rb;
    Renderer* rend;
    sf::Clock clock;
    float deltaTime = 0.f;
    WindowManager* window_manager;
    void CreateActor();
    void ActorAction();
    std::string GetClass() override;
    static std::string ClassName();
    void RegisterActor(Character* actor, std::string className);
    std::vector<EntityList*> entityList;

};
