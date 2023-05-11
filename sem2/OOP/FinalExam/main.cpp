#include <iostream>
#include <QtWidgets/QApplication>
#include "Service.h"
#include "Domain.h"
#include "gui01.h"
int main(int argc, char* argv[]) {
    QApplication application(argc,argv);
    Service service;
    auto users=service.getUsers();
    for(const auto& u : users)
    {
        auto g=new gui01{service,u};
        g->setWindowTitle(QString::fromStdString(u));
        g->show();
    }
    return QApplication::exec();
}
