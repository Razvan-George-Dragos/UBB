//
// Created by Razvan on 7/4/2022.
//

#ifndef PRIMA_RESTANTA_GUIU_H
#define PRIMA_RESTANTA_GUIU_H

#include <QWidget>
#include "Service.h"
#include "Domain.h"

QT_BEGIN_NAMESPACE
namespace Ui { class guiu; }
QT_END_NAMESPACE

class guiu : public QWidget , public Observer{
Q_OBJECT

public:
    explicit guiu(Service& service,std::string nam,std::string stat,QWidget *parent = nullptr);
    void populateList();
    void connectSignals();
    void addIdeas();
    void showAccepted();
    void saveIdeas();
    Service& service;
    std::string name;
    std::string stat;
    //std::vector<int> accepted;
    void accepptIdea();
    void update() override;
    ~guiu() override;

private:
    Ui::guiu *ui;
};


#endif //PRIMA_RESTANTA_GUIU_H
