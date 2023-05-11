#include <iostream>
#include <QtWidgets/QApplication>
#include "Service.h"
#include "usergui.h"
#include <fstream>
int main(int argc, char* argv[]) {
    std::ifstream fin("users.txt");
    std::vector<std::string> names;
    std::string name;
    while(fin>>name)
    {
        names.push_back(name);
    }
    QApplication application(argc, argv);
    Service service;
    for(const auto& n : names)
    {
        auto u = new userGUI{service,n};
        u->show();
    }
    /*userGUI gui{service,names[0]};
    userGUI gui2{service,names[1]};
    gui.show();
    gui2.show();*/
    return QApplication::exec();
}
