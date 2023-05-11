//
// Created by Razvan on 7/4/2022.
//

#ifndef PRIMA_RESTANTA_OBSERVER_H
#define PRIMA_RESTANTA_OBSERVER_H
#include <vector>

class Observer {
public:
    virtual void update()=0;
    ~Observer()=default;
};
class Subject {
private:
    std::vector<Observer*> obs;
public:
    void addObserver(Observer* o){ this->obs.push_back(o); }
    void notify();
};


#endif //PRIMA_RESTANTA_OBSERVER_H
