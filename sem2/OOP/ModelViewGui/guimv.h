//
// Created by Razvan on 7/4/2022.
//

#ifndef EU_MVIEW_GUIMV_H
#define EU_MVIEW_GUIMV_H

#include <QWidget>
#include <QStandardItemModel>
#include "Service.h"
#include "Modelvw.h"

QT_BEGIN_NAMESPACE
namespace Ui { class guimv; }
QT_END_NAMESPACE

class guimv : public QWidget {
Q_OBJECT

public:
    explicit guimv(Service& service,Modelvw* modelvw,std::string nam, std::string stat,QWidget *parent = nullptr);
    void connectSignals();
    void addI();
    void accept();
    void develop();
    void save();
    ~guimv() override;

private:
    Ui::guimv *ui;
    Service& service;
    Modelvw* model;
    std::string name;
    std::string stat;
    QStandardItemModel* secondModel;
};


#endif //EU_MVIEW_GUIMV_H
