//
// Created by Razvan on 7/2/2022.
//

#include "Domain.h"

int Question::getId() const {
    return id;
}

void Question::setId(int id) {
    Question::id = id;
}

const std::string &Question::getText() const {
    return text;
}

void Question::setText(const std::string &text) {
    Question::text = text;
}

const std::string &Question::getCorrectAnswer() const {
    return correctAnswer;
}

void Question::setCorrectAnswer(const std::string &correctAnswer) {
    Question::correctAnswer = correctAnswer;
}

int Question::getScore() const {
    return score;
}

void Question::setScore(int score) {
    Question::score = score;
}

Question::Question(int id, const std::string &text, const std::string &correctAnswer, int score) : id(id), text(text),
                                                                                                   correctAnswer(
                                                                                                           correctAnswer),
                                                                                                   score(score) {}

std::ostream &operator<<(std::ostream &os, const Question &question) {
    os << question.id << "," << question.text << "," << question.correctAnswer
       << "," << question.score;
    return os;
}


