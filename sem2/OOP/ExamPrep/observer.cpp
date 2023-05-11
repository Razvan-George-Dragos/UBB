//
// Created by Razvan on 6/14/2022.
//

#include "observer.h"

void Subject::notify()
{
    for(auto o : this->vec)
    {
        o->update();
    }
}
