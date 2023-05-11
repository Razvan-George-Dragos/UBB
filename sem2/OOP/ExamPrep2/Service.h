//
// Created by Razvan on 7/2/2022.
//

#ifndef PT_RESTANTA_1_SERVICE_H
#define PT_RESTANTA_1_SERVICE_H
#include "Domain.h"
#include <vector>
#include <algorithm>
#include "Observer.h"
class Service : public Subject{
private:
    std::vector<Question> vect;
public:
    Service();
    void add(const Question& q);
    bool valid_id(int i);
    void sortbyid();
    void sortbyscore();
    void update(int oid, int id, std::string ntext, std::string nans);
    int checkAnswer(int id, const std::string& ans);
    void readFromFile();
    std::vector<Question> getAllQues();
    ~Service();
};


#endif //PT_RESTANTA_1_SERVICE_H
