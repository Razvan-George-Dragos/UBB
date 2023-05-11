//
// Created by Razvan on 6/13/2022.
//
#include <string>
#include <ostream>

#ifndef EXAMEN_PENTRU_QUESTION_H
#define EXAMEN_PENTRU_QUESTION_H
/*class Question{
private:
    int id;
    std::string text;
    std::string nameOfUser;
public:
    //Question()=default;
    Question(int i, std::string t, std::string n);
    int getId() const {return this->id; };
    std::string getText() const { return this->text; };
    std::string getNameOfUser() const { return this->nameOfUser; };
    void setId(int i) { this->id=i; };
    void setText(std::string t) { this->text= std::move(t);};
    void setNameOfUser(std::string n) { this->nameOfUser=std::move(n); };
    ~Question()=default;

};*/
class Question{
private:
    int id;
    std::string text;
    std::string nameOfUser;
public:
    Question(int id, std::string text, std::string nameOfUser);

    int getId() const;

    void setId(int id);

    const std::string &getText() const;

    void setText(const std::string &text);

    const std::string &getNameOfUser() const;

    friend std::ostream &operator<<(std::ostream &os, const Question &question);

    void setNameOfUser(const std::string &nameOfUser);
    ~Question()=default;
};
#endif //EXAMEN_PENTRU_QUESTION_H
