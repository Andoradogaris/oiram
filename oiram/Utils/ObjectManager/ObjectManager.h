#pragma once
#include <vector>
#include "../Factory.h"
#include "../TemplateUtils.h"
#include "../../BaseObject.h"

#include "../Engine/Engine.h"

class ObjectManager: public BaseObject
{
private:
    ObjectManager();
    Factory<BaseObject> factory;
    static ObjectManager* m_instance;
public:
    ~ObjectManager();
    template<class T = BaseObject>
    T* CastCreateObject(std::string classId)
    {
        if(!factory.IsAlreadyRegistered(classId))
        {
            factory.RegisterNewCreator(classId, new DerivedCreator<BaseObject, T>());
        }
        BaseObject* object = factory.CreateClass(classId);
        return Cast<T>(object);
    }
    static ObjectManager* get();
    std::string GetClass() override;
    std::vector<BaseObject*> gameObjectsList;
    static std::string ClassName();
};
