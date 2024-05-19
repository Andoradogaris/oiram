#pragma once
#include "../BaseObject.h"
//template pour cast des classe
template<class T, class S = BaseObject>
static T* Cast(S* Object){
    return (T*)(Object);
}
