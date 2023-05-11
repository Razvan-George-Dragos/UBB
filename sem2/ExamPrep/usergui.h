//
// Created by Razvan on 6/13/2022.
//

#ifndef EXAMEN_PENTRU_USERGUI_H
#define EXAMEN_PENTRU_USERGUI_H

#include <QWidget>
#include "Service.h"
#include "Question.h"
#include "Answear.h"
#include "observer.h"
QT_BEGIN_NAMESPACE
namespace Ui { class userGUI; }
QT_END_NAMESPACE

class userGUI : public QWidget, public observer {
Q_OBJECT

public:
    explicit userGUI(Service &service,std::string name,QWidget *parent = nullptr);
    Service& service;
    std::string name;
    void populateQuestions();
    void addQuestion();
    void emitSignals();
    void populateAnswers(int i);
    void addAnswer();
    ~userGUI() override;
    void update() override;

private:
    Ui::userGUI *ui;
};


#endif //EXAMEN_PENTRU_USERGUI_H
