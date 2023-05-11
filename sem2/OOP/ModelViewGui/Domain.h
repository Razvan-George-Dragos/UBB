//
// Created by Razvan on 7/4/2022.
//

#ifndef EU_MVIEW_DOMAIN_H
#define EU_MVIEW_DOMAIN_H
#include <string>
#include <utility>
#include <algorithm>
#include <ostream>

class Idea {
private:
    std::string descriprion;
    std::string status;
    std::string name;
    int act;
public:
    Idea(const std::string &descriprion, const std::string &status, const std::string &name, int act);

    const std::string &getDescriprion() const;

    void setDescriprion(const std::string &descriprion);

    const std::string &getStatus() const;

    void setStatus(const std::string &status);

    const std::string &getName() const;

    void setName(const std::string &name);

    int getAct() const;

    friend std::ostream &operator<<(std::ostream &os, const Idea &idea);

    void setAct(int act);
    ~Idea()=default;
};


#endif //EU_MVIEW_DOMAIN_H
