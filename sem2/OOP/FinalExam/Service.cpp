//
// Created by Razvan on 7/5/2022.
//

#include "Service.h"
#include <fstream>
#include <cstring>
#include <iostream>
Service::Service() {
    this->readPosts();
    this->readUsers();
    this->readTopics();

}

void Service::updatePose(int oid, int nid, std::string ntext, int ntime, int ndate, std::string nuser) {
    /*for(int i=0; i<this->vec.size(); i++){
        if(this->vec[i].getId()==oid)
        {
            this->vec[i].setId(nid);
            this->vec[i].setText(ntext);
            this->vec[i].setTime(ntime);
            this->vec[i].setDate(ndate);
            this->vec[i].setUser(nuser);
            //this->notify();
            return;
        }
    }*/
    int index=0;
    for(const auto& it : this->vec){
        if(it.getId()==oid){
            this->vec.erase(this->vec.begin()+index);
            this->addPost(Post(nid,ntext,ndate,ntime,nuser));
        }
        index++;
    }
}

void Service::sortDecByDate() {
    std::sort(vec.begin(),vec.end(),[](Post a, Post b){return a.getDate()>b.getDate() || (a.getDate()==b.getDate() && a.getTime()>b.getTime());});
}

void Service::readPosts() {
    std::ifstream fin("posts.txt");
    if(!fin.is_open())
        return;
    char t[300];
    while(true)
    {
        fin>>t;
        char* p= strtok(t,",");
        std::vector<std::string> vp;
        while(p){
            vp.push_back((std::string)p);
            p=strtok(nullptr,",");
        }
        if(vp.size()!=5)
            break;
        else
            this->addPost(Post(std::stoi(vp[0]),vp[1],std::stoi(vp[2]),std::stoi(vp[3]),vp[4]));

    }
    fin.close();

}

Service::~Service() {
    std::ofstream fou("posts.txt");
    if(!fou.is_open())
        return;
    for(const auto& it : this->vec)
        fou<<it<<"\n";
    fou.close();
    std::ofstream ft("topics.txt");
    if(!ft.is_open())
        return;
    for(auto it : this->topics)
    {
        ft<<it.getName()<<"\n";
        for(const auto& ns : it.getUsers())
            ft<<ns<<"\n";
    }
}

void Service::readUsers() {
    std::ifstream f("users.txt");
    if(!f.is_open())
        return;
    std::string u;
    while(f>>u){
        this->users.push_back(u);
    }
    f.close();
}

bool Service::checkIfUser(const std::string& x) {
    for(const auto& it : this->users)
    {
        if(it==x)
            return true;
    }
    return false;
}

void Service::readTopics() {
    std::ifstream finn("topics.txt");
    if(!finn.is_open())
        return;
    std::string t;
    int i=-1;
    while(finn>>t){
        if(!checkIfUser(t))
        {
            this->topics.push_back(Topic(t));
            i++;
        }
        else if(i>-1)
        {
            this->topics[i].addUser(t);
        }
    }
    finn.close();
}

void Service::addUserToTopic(std::string t, std::string u) {
    /*for(auto it : this->topics)
    {
        if(it.getName()==t)
        {
            std::cout<<"intra";
            it.addUser(u);
            std::cout<<it.getUsers().size();
        }

    }*/
    for(int i=0; i<this->topics.size(); i++){
        if(this->topics[i].getName()==t){
            this->topics[i].addUser(u);
        }
    }
}
