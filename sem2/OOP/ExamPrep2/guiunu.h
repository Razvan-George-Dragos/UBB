//
// Created by Razvan on 7/2/2022.
//

#ifndef PT_RESTANTA_1_GUIUNU_H
#define PT_RESTANTA_1_GUIUNU_H

#include <QWidget>
#include "Service.h"

QT_BEGIN_NAMESPACE
namespace Ui { class guiunu; }
QT_END_NAMESPACE

class guiunu : public QWidget, public Observer{
Q_OBJECT

public:
    explicit guiunu(Service &service,std::string n,int scr,QWidget *parent = nullptr);
    Service& service;
    std::string name;
    std::vector<int> answered;
    void connectSignals();
    void addQuestion();
    void answerQuestion();
    void updateQuestion();
    int score;
    void populateList();
    void update() override;
    ~guiunu() override;

private:
    Ui::guiunu *ui;
};


#endif //PT_RESTANTA_1_GUIUNU_H
