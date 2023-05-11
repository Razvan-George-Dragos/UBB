//
// Created by Razvan on 7/2/2022.
//

#ifndef PT_RESTANTA_1_OBSERVER_H
#define PT_RESTANTA_1_OBSERVER_H
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

#endif //PT_RESTANTA_1_OBSERVER_H
