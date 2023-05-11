//
// Created by Razvan on 7/5/2022.
//

#ifndef RESTANTA_OOP_DOMAIN_H
#define RESTANTA_OOP_DOMAIN_H
#include <string>
#include <algorithm>
#include <utility>
#include <ostream>
#include <vector>
class Post {
private:
    int id;
    std::string text;
    int date;
    int time;
    std::string user;
public:
    Post(int id, std::string text, int date, int time, std::string user);

    int getId() const;

    void setId(int id);

    const std::string &getText() const;

    void setText(const std::string &text);

    int getDate() const;

    void setDate(int date);

    int getTime() const;

    void setTime(int time);

    const std::string &getUser() const;

    void setUser(const std::string &user);

    friend std::ostream &operator<<(std::ostream &os, const Post &post);

    ~Post()=default;
};

class Topic{
private:
    std::string name;
    std::vector<std::string> users;
public:
    Topic(const std::string& n);
    void addUser(const std::string& u){ this->users.push_back(u);}
    std::string getName(){ return this->name;}
    std::vector<std::string> getUsers(){return this->users;}
    ~Topic()=default;
};

#endif //RESTANTA_OOP_DOMAIN_H
