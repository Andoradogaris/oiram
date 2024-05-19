#pragma once
#include <unordered_map>

#include "WindowManager/WindowManager.h"

class BaseObject;

template<class BaseClass = BaseObject>
class Creator
{
public:
    virtual ~Creator(){}
    virtual BaseClass* Create() = 0;
};

template<class BaseClass = BaseObject, class DerivedClass = BaseObject>
class DerivedCreator : public Creator<BaseClass>
{
public:
    BaseClass* Create() override
    {
        BaseClass* object = new DerivedClass();
        return object;
    }
};

template<class BaseClass = BaseObject>
class Factory
{
public:
    Factory() = default;
    ~Factory()
    {
        Clear();
    }
    //fonction pour enregistrer une nouvelle classe
    void RegisterNewCreator(std::string classId, Creator<BaseClass>* creatorClass)
    {
        if(!factoryConstructor.contains(classId))
        {
            factoryConstructor.insert(std::make_pair(classId, creatorClass));
        }
    }
    //fonction pour vérifier si la classe a déjà été enregistré
    bool IsAlreadyRegistered(std::string classId)
    {
        return factoryConstructor.contains(classId);
    }
    //fonction pour ajouter une classe dans l'afactory et la créé
    BaseClass* CreateClass(std::string classId)
    {
        BaseClass* object = nullptr;
        if(factoryConstructor.contains(classId))
        {
            object = factoryConstructor.at(classId)->Create();
        }
        return object;
    }
    //fonction pour clear l'afactory
    void Clear()
    {
        factoryConstructor.clear();
    }

    std::unordered_map<std::string,Creator<BaseClass>*> factoryConstructor;
};




