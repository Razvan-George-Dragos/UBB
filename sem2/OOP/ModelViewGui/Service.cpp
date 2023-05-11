//
// Created by Razvan on 7/4/2022.
//

#include "Service.h"
#include <fstream>
#include <cstring>
Service::Service() {
    this->readFromFile();
    this->sortByAct();
}

void Service::readFromFile() {
    char t[300];
    std::ifstream fin("ideas.txt");
    if(!fin.is_open())
        return;
    while(true)
    {
        std::vector<std::string> v;
        fin>>t;
        char* p= strtok(t,",");
        while(p)
        {
            v.push_back((std::string)p);
            p= strtok(nullptr,",");
        }
        if(v.size()!=4)
            break;
        else
            this->addIdea(Idea(v[0],v[1],v[2],std::stoi(v[3])));
    }
}

Service::~Service() {
    std::ofstream fout("ideas.txt");
    if(!fout.is_open())
        return;
    for(const auto& it : this->vec)
        fout<<it<<"\n";
    if(this->saved.empty())
        return;
    std::ofstream gout("saved.txt");
    if(!gout.is_open())
        return;
    for(const auto& it : this->saved)
        gout<<it<<"\n";
}

void Service::sortByAct() {
    std::sort(vec.begin(),vec.end(),[](Idea a, Idea b){return a.getAct()<b.getAct();});
}

std::vector<Idea> Service::getAcceptedIdeas() {
    std::vector<Idea> v;
    for(const auto& it : this->vec){
        if(it.getStatus()=="accepted")
            v.push_back(it);
    }
    return v;
}

bool Service::checkIdea(std::string des, int ac) {
    if(ac<1 || ac>3)
        return false;
    if(des.empty())
        return false;
    for(const auto& it : this->vec)
    {
        if(it.getAct()==ac && it.getDescriprion()==des)
            return false;
    }
    return true;
}



void Service::saveToFile(int r) {
    int i=0;
    for(const auto& it : this->vec)
    {
        if(it.getStatus()=="accepted")
            i++;
        if(i==r)
            this->saved.push_back(it);
    }
}

void Service::acceptamideea(int r) {
    this->vec[r].setStatus("accepted");
}
