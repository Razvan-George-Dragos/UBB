//
// Created by Razvan on 6/14/2022.
//

#ifndef EXAMEN_PENTRU_OBSERVER_H
#define EXAMEN_PENTRU_OBSERVER_H
#include <vector>

class observer {
public:
    virtual void update()=0;
    virtual ~observer()=default;

};
class Subject{
private:
    std::vector<observer*> vec;
public:
    void addObserver(observer* o) {vec.push_back(o);};
    void notify();
};
#endif //EXAMEN_PENTRU_OBSERVER_H
