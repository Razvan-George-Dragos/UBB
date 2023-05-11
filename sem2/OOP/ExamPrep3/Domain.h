//
// Created by Razvan on 7/3/2022.
//

#ifndef PRIMA_RESTANTA_DOMAIN_H
#define PRIMA_RESTANTA_DOMAIN_H
#include <string>
#include <algorithm>
#include <utility>
#include <ostream>

class Idea {
private:
    std::string descriprion;
    std::string status;
    std::string name;
    int act;
public:
    Idea(std::string descriprion, std::string status, std::string name, int act);
    ~Idea()=default;

    const std::string &getDescriprion() const;

    void setDescriprion(const std::string &descriprion);

    const std::string &getStatus() const;

    void setStatus(const std::string &status);

    const std::string &getName() const;

    void setName(const std::string &name);

    int getAct() const;

    void setAct(int act);

    friend std::ostream &operator<<(std::ostream &os, const Idea &idea);
};


#endif //PRIMA_RESTANTA_DOMAIN_H
