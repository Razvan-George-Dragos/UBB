//
// Created by Razvan on 7/5/2022.
//

#ifndef RESTANTA_OOP_SERVICE_H
#define RESTANTA_OOP_SERVICE_H
#include "Domain.h"
#include "Observer.h"
class Service : public Subject {
private:
    std::vector<Post> vec;
    std::vector<std::string> users;
    std::vector<Topic> topics;
public:
    Service();
    void addPost(const Post& p) { this->vec.push_back(p); this->sortDecByDate(); this->notify(); }
    void updatePose(int oid, int nid, std::string ntext, int ntime, int ndate, std::string nuser);
    void sortDecByDate();
    void readPosts();
    void readUsers();
    void addUserToTopic(std::string t, std::string u);
    std::vector<std::string> getUsers() { return this->users; }
    std::vector<Topic> getTopics() { return this->topics; }
    bool checkIfUser(const std::string& x);
    void readTopics();
    std::vector<Post> getAllPosts() { return this->vec; }
    ~Service();
};


#endif //RESTANTA_OOP_SERVICE_H
