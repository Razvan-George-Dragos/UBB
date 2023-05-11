//
// Created by Razvan on 7/2/2022.
//

#ifndef PT_RESTANTA_1_DOMAIN_H
#define PT_RESTANTA_1_DOMAIN_H

#include <string>
#include <ostream>

class Question {
private:
    int id;
    std::string text;
    std::string correctAnswer;
    int score;
public:
    Question(int id, const std::string &text, const std::string &correctAnswer, int score);

    int getId() const;

    void setId(int id);

    const std::string &getText() const;

    void setText(const std::string &text);

    const std::string &getCorrectAnswer() const;

    void setCorrectAnswer(const std::string &correctAnswer);

    int getScore() const;

    void setScore(int score);

    friend std::ostream &operator<<(std::ostream &os, const Question &question);

    ~Question()=default;
};


#endif //PT_RESTANTA_1_DOMAIN_H
