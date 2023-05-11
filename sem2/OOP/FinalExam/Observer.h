//
// Created by Razvan on 7/6/2022.
//

#ifndef RESTANTA_OOP_OBSERVER_H
#define RESTANTA_OOP_OBSERVER_H


#include <vector>

class Observer {
public:
    virtual void update()=0;
    virtual ~Observer()=default;
};
class Subject{
private:
    std::vector<Observer*> obs;
public:
    void addObserver(Observer* o) {this->obs.push_back(o);}
    void notify();
};
#endif //RESTANTA_OOP_OBSERVER_H
