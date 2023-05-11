//
// Created by Razvan on 6/13/2022.
//

#include "Question.h"

#include <utility>


Question::Question(int id, std::string text, std::string nameOfUser) : id(id), text(std::move(text)),
                                                                                     nameOfUser(std::move(nameOfUser)) {}

int Question::getId() const {
    return id;
}

void Question::setId(int id) {
    Question::id = id;
}

const std::string &Question::getText() const {
    return this->text;
}

void Question::setText(const std::string &text) {
    Question::text = text;
}

const std::string &Question::getNameOfUser() const {
    return nameOfUser;
}

void Question::setNameOfUser(const std::string &nameOfUser) {
    Question::nameOfUser = nameOfUser;
}

std::ostream &operator<<(std::ostream &os, const Question &question) {
    os << question.id << "," << question.text << "," << question.nameOfUser<<"\n";
    return os;
}
