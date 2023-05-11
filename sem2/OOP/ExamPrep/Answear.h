//
// Created by Razvan on 6/13/2022.
//
#include <string>
#ifndef EXAMEN_PENTRU_ANSWEAR_H
#define EXAMEN_PENTRU_ANSWEAR_H
class Answear{
private:
    int id;
    int QsId;
    std::string text;
    std::string userName;
    int nrVotes;
public:
    //Answear()=default;
    Answear(int i, int qi, std::string t, std::string u, int nrv);
    int getId() const { return this->id; };
    int getQsId() const { return this->QsId;}
    int getNrVotes() const { return this->nrVotes;}
    std::string getText() const { return this->text;};
    std::string getUserName() const { return this->userName; };
    void setVotes(int x) {this->nrVotes=x;};

    ~Answear()=default;
};
#endif //EXAMEN_PENTRU_ANSWEAR_H
