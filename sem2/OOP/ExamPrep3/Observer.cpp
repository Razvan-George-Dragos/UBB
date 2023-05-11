//
// Created by Razvan on 7/4/2022.
//

#include "Observer.h"

void Subject::notify() {
    for( auto o : this->obs )
        o->update();
}
