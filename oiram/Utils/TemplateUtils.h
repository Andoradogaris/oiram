#pragma once
#include "../BaseObject.h"

template<class T, class S = BaseObject>
static T* Cast(S* Object){
    return (T*)(Object);
}
