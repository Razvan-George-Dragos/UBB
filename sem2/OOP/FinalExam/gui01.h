//
// Created by Razvan on 7/6/2022.
//

#ifndef RESTANTA_OOP_GUI01_H
#define RESTANTA_OOP_GUI01_H

#include <QWidget>
#include "Service.h"
#include "Domain.h"
#include "Observer.h"
QT_BEGIN_NAMESPACE
namespace Ui { class gui01; }
QT_END_NAMESPACE

class gui01 : public QWidget, public Observer {
Q_OBJECT

public:
    explicit gui01(Service& service,std::string n,QWidget *parent = nullptr);
    Service& service;
    std::string name;
    void PopulateList();
    void connectSingals();
    void subscribe();
    void add();
    void update() override;
    void umpluSubs();
    void updatep();
    std::vector<std::string> subscribed;
    ~gui01() override;

private:
    Ui::gui01 *ui;
};


#endif //RESTANTA_OOP_GUI01_H
