//
// Created by Razvan on 7/4/2022.
//

#include "Modelvw.h"

Modelvw::Modelvw(Service &service) : service(service) {

}

int Modelvw::rowCount(const QModelIndex &parent) const {
    return this->service.getAllIdeas().size();
}

int Modelvw::columnCount(const QModelIndex &parent) const {
    return 4;
}

QVariant Modelvw::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int column = index.column();
    auto idea = this->service.getAllIdeas()[row];

    if (role == Qt::DisplayRole) {
        switch (column) {
            case 0: return QString::fromStdString(idea.getDescriprion());
            case 1: return QString::fromStdString(idea.getStatus());
            case 2: return QString::fromStdString(idea.getName());
            case 3: return QString::number(idea.getAct());
            default: break;
        }
    }

    return QVariant();
}

QVariant Modelvw::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        switch (section) {
            case 0: return QString{ "Description" };
            case 1: return QString{ "Status" };
            case 2: return QString{ "Creator" };
            case 3: return QString{ "Act" };
            default: break;
        }
    }
    return QVariant();
}

void Modelvw::addIdea(Idea& x) {
    auto n=this->service.getAllIdeas().size();
    this->beginInsertRows(QModelIndex{}, n, n);
    this->service.addIdea(x);
    this->endInsertRows();
}

void Modelvw::acceptam(int row) {
    this->beginResetModel();
    this->service.acceptamideea(row);
    //emit dataChanged(createIndex(0, 0), createIndex(this->service.getAllIdeas().size()-1, 3));
    this->endResetModel();
}


/*void Modelvw::clearData() {
    this->beginResetModel();
    //this->service.clear()
    this->endResetModel();
}*/
