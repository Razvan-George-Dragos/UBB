//
// Created by Razvan on 7/4/2022.
//

#ifndef EU_MVIEW_SERVICE_H
#define EU_MVIEW_SERVICE_H
#include "Domain.h"
#include <vector>
class Service {
private:
    std::vector<Idea> vec;
    std::vector<Idea> saved;
public:
    Service();
    void addIdea(const Idea& a) {this->vec.push_back(a); this->sortByAct(); }
    std::vector<Idea> getAllIdeas() { return this->vec; }
    std::vector<Idea> getAcceptedIdeas();
    bool checkIdea(std::string des, int ac);
    void saveToFile(int r);
    void acceptamideea(int r);
    void readFromFile();
    void sortByAct();
    ~Service();
};
#endif //EU_MVIEW_SERVICE_H
