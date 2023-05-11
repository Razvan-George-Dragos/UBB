//
// Created by Razvan on 7/2/2022.
//

#include "Service.h"
#include <fstream>
#include <cstring>
Service::Service() {
    this->readFromFile();
}

void Service::add(const Question& q) {
    this->vect.push_back(q);
    this->notify();
}

void Service::readFromFile() {
    std::ifstream fin("ques.txt");
    if(!fin.is_open())
        return;
    char t[300];
    while(true)
    {
        std::vector<std::string> v;
        fin>>t;
        char* p=strtok(t,",");
        while(p)
        {
            v.push_back((std::string)p);
            p=strtok(nullptr,",");
        }
        if(v.size()!=4)
            break;
        else
            this->add(Question(std::stoi(v[0]),v[1],v[2],std::stoi(v[3])));
    }
    fin.close();
}

Service::~Service() {
    std::ofstream fout("ques.txt");
    if(!fout.is_open())
        return;
    for(const auto& it : this->vect)
        fout<<it<<"\n";
    fout.close();
}

std::vector<Question> Service::getAllQues() {
    return this->vect;
}

bool Service::valid_id(int i) {
    //std::all_of(vect.begin(),vect.end(),[](Question a,int &i){return a.getId()!=i;});
    for(const auto& it : this->vect)
    {
        if(it.getId()==i)
            return false;
    }
    return true;
}

int Service::checkAnswer(int id, const std::string& ans) {
    for(const auto& it : this->vect){
        if(it.getId()==id && it.getCorrectAnswer()==ans)
            return it.getScore();
    }
    return 0;
}

void Service::sortbyid() {
    std::sort(vect.begin(),vect.end(),[](Question a, Question b){return a.getId()<b.getId();});
}

void Service::sortbyscore() {
    std::sort(vect.begin(),vect.end(),[](Question a, Question b){return a.getScore()>b.getScore();});
}

void Service::update(int oid, int id, std::string ntext, std::string nans) {
    /*int index=0;
    for(auto it : this->vect)
    {
        if(it.getId()==oid && this->valid_id(id))
        {
            *//*it.setId(id);
            it.setText(ntext);
            it.setCorrectAnswer(nans);*//*
            auto sc=it.getScore();
            this->vect.erase(vect.begin()+index);
            this->add(Question(id,ntext,nans,sc));
        }
        index++;
    }*/
    for(int i=0; i< this->vect.size(); i++){
        if(this->vect[i].getId()==oid && this->valid_id(id))
        {
            this->vect[i].setCorrectAnswer(nans);
            this->vect[i].setText(ntext);
            this->vect[i].setId(id);
        }
    }
    this->notify();
}



