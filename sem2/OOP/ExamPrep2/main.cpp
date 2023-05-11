#include <iostream>
#include <QtWidgets/QApplication>
#include "guiunu.h"
#include "Service.h"
#include "Domain.h"
#include <fstream>

int main(int argc, char* argv[]) {
    QApplication application(argc, argv);
    Service service;
    std::ifstream f("people.txt");
    std::vector<std::string> names;
    std::string name;
    while(f>>name)
    {
        names.push_back(name);
    }
    for(int i=0; i<names.size()-1; i+=2){
        auto ng=new guiunu{service, names[i], std::stoi(names[i+1])};
        ng->show();
    }

    return QApplication::exec();
}
