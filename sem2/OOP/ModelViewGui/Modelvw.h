//
// Created by Razvan on 7/4/2022.
//

#ifndef EU_MVIEW_MODELVW_H
#define EU_MVIEW_MODELVW_H
#include <QAbstractTableModel>
#include "Service.h"
class Modelvw : public QAbstractTableModel{
private:
    Service& service;
public:
    Modelvw(Service& service);
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    void addIdea(Idea& x);
    void acceptam(int row);
    //void clearData();
};


#endif //EU_MVIEW_MODELVW_H
