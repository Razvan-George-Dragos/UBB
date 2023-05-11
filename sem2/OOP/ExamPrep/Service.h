//
// Created by Razvan on 6/13/2022.
//
#include "Answear.h"
#include "Question.h"
#include "observer.h"
#include <vector>
#ifndef EXAMEN_PENTRU_SERVICE_H
#define EXAMEN_PENTRU_SERVICE_H
class Service : public Subject{
private:
    std::vector<Answear> AnsList;
    std::vector<Question> QueList;
public:
    Service();
    void add_question(const Question& q);
    void add_answaer(const Answear& a);
    void readQuestionsFromFile();
    void readAnswearsFromFile();
    std::vector<Answear> getAnswearsForAQuestion(int i);
    std::vector<Question> getAllQuestions();
    std::vector<Answear> getAllAnswears();
    void sortAnswers();
    void voteAnswer(int i, int v);
    ~Service();
};
#endif //EXAMEN_PENTRU_SERVICE_H
