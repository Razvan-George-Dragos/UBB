//
// Created by Razvan on 7/4/2022.
//

#include "Domain.h"

Idea::Idea(const std::string &descriprion, const std::string &status, const std::string &name, int act) : descriprion(
        descriprion), status(status), name(name), act(act) {}

const std::string &Idea::getDescriprion() const {
    return descriprion;
}

void Idea::setDescriprion(const std::string &descriprion) {
    Idea::descriprion = descriprion;
}

const std::string &Idea::getStatus() const {
    return status;
}

void Idea::setStatus(const std::string &status) {
    Idea::status = status;
}

const std::string &Idea::getName() const {
    return name;
}

void Idea::setName(const std::string &name) {
    Idea::name = name;
}

int Idea::getAct() const {
    return act;
}

void Idea::setAct(int act) {
    Idea::act = act;
}

std::ostream &operator<<(std::ostream &os, const Idea &idea) {
    os << idea.descriprion << "," << idea.status << "," << idea.name << ","
       << idea.act;
    return os;
}
