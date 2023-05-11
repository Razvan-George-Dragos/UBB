#include <iostream>
#include <QtWidgets/QApplication>
#include "Service.h"
#include "Modelvw.h"
#include "guimv.h"
#include "fstream"
#include "Domain.h"
int main(int argc, char* argv[]) {
    QApplication application(argc,argv);
    Service service;
    std::ifstream fin("dada.txt");
    std::vector<std::string> v;
    std::string x;
    while(fin>>x){
        v.push_back(x);
    }
    //auto ideas=service.getAllIdeas();
    auto* model = new Modelvw{service};
    for(int i=0; i<v.size()-1; i+=2){
        auto u= new guimv{service,model,v[i],v[i+1]};
        u->setWindowTitle(QString::fromStdString(v[i]));
        u->show();
    }
    return QApplication::exec();
}
