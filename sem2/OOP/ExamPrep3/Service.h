//
// Created by Razvan on 7/3/2022.
//

#ifndef PRIMA_RESTANTA_SERVICE_H
#define PRIMA_RESTANTA_SERVICE_H
#include "Domain.h"
#include <vector>
#include "Observer.h"
class Service : public Subject{
private:
    std::vector<Idea> vec;
    std::vector<Idea> saved;
public:
    Service();
    void addIdea(const Idea& a) {this->vec.push_back(a); this->notify(); }
    std::vector<Idea> getAllIdeas() { return this->vec; }
    std::vector<Idea> getAcceptedIdeas();
    bool checkIdea(std::string des, int ac);
    void acceptIdea(std::string des, int ac);
    void saveToFile(std::string des, int ac);
    void readFromFile();
    void sortByAct();
    ~Service();
};


#endif //PRIMA_RESTANTA_SERVICE_H
