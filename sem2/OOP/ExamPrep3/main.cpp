#include <iostream>
#include <QtWidgets/QApplication>
#include "guiu.h"
#include "Service.h"
#include "Domain.h"
#include <fstream>
int main(int argc, char* argv[]) {
    QApplication application(argc, argv);
    Service service;
    std::ifstream f("oamenii.txt");
    if(!f.is_open())
        return 0;
    std::vector<std::string> v;
    std::string t;
    while(f>>t){
        v.push_back(t);
    }
    for(int i=0; i<v.size()-1; i+=2){
        auto u=new guiu{service,v[i],v[i+1]};
        u->show();
    }
    return QApplication::exec();
}
