//
// Created by Razvan on 7/3/2022.
//

#include "Domain.h"

#include <utility>

Idea::Idea(std::string descriprion, std::string status, std::string name, int act) : descriprion(std::move(
        descriprion)), status(std::move(status)), name(std::move(name)), act(act) {}

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
