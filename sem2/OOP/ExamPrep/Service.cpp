//
// Created by Razvan on 6/13/2022.
//
#include <cassert>
#include "Service.h"
#include <fstream>
#include <cstring>
#include <iostream>
Service::Service() {
    this->readQuestionsFromFile();
    this->readAnswearsFromFile();
    this->sortAnswers();
}

void Service::add_question(const Question& q) {
    auto x=this->QueList.size();
    this->QueList.push_back(q);
    assert(this->QueList.size()==x+1);
    this->notify();
}

void Service::add_answaer(const Answear &a) {
    this->AnsList.push_back(a);
    this->notify();
}

void Service::readQuestionsFromFile()
{
    std::ifstream fin("questions.txt");
    if(!fin.is_open())
        return;
    char t[300];
    while(true)
    {
        std::vector<std::string> v;
        fin>>t;
        char* p=strtok(t, ",");
        while(p)
        {
            v.push_back((std::string)p);
            p=strtok(nullptr, ",");
        }
        if(v.size()!=3)
            break;
        else
            this->add_question(Question(std::stoi(v[0]),v[1],v[2]));
    }
    fin.close();
}

void Service::readAnswearsFromFile()
{
    std::ifstream f("answears.txt");
    if(!f.is_open())
        return;
    char t[300];
    while(true)
    {
        std::vector<std::string> vec;
        f>>t;
        char* p=strtok(t, ",");
        while(p)
        {
            vec.push_back((std::string)p);
            p=strtok(nullptr, ",");
        }
        if(vec.size()!=5)
            break;
        else
            this->add_answaer(Answear(std::stoi(vec[0]),std::stoi(vec[1]),vec[2], vec[3],std::stoi(vec[4])));
    }
    f.close();
}

std::vector<Answear> Service::getAnswearsForAQuestion(int i) {
    std::vector<Answear> va;
    for(const auto& it : this->AnsList){
        if(it.getQsId()==i)
            va.push_back(it);
    }
    return va;
}

std::vector<Question> Service::getAllQuestions() {
    return this->QueList;
}

std::vector<Answear> Service::getAllAnswears() {
    return this->AnsList;
}

Service::~Service() {
    std::ofstream fout("questions.txt");
    if(!fout.is_open())
        return;
    for(const auto& it : this->QueList){
       // fout<<it.getId()<<","<<it.getText()<<","<<it.getNameOfUser()<<"\n";
       fout<<it;
    }
    fout.close();
    std::ofstream gout("answears.txt");
    if(!gout.is_open())
        return;
    for(const auto& it : this->AnsList){
        gout<<it.getId()<<","<<it.getQsId()<<","<<it.getText()<<","<<it.getUserName()<<","<<it.getNrVotes()<<"\n";
    }
    gout.close();
}

void Service::sortAnswers() {
    bool ok= false;
    while(!ok)
    {
        ok=true;
        for(int i=0; i<this->AnsList.size()-1; i++)
        {
            if(this->AnsList[i].getNrVotes()>this->AnsList[i+1].getNrVotes())
            {
                auto aux=this->AnsList[i];
                this->AnsList[i]=this->AnsList[i+1];
                this->AnsList[i+1]=aux;
                ok=false;
            }
        }
    }
}

void Service::voteAnswer(int i, int v) {
    for(auto it : this->AnsList){
        if(it.getId()==i)
        {
            it.setVotes(v);
            std::cout<<it.getNrVotes()<<" "<<it.getText();
        }
    }
    this->sortAnswers();
}


