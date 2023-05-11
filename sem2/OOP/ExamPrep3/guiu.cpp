//
// Created by Razvan on 7/4/2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_guiu.h" resolved

#include "guiu.h"
#include <QMessageBox>
#include <utility>
#include "ui_guiu.h"
#include <sstream>

guiu::guiu(Service& service,std::string nam,std::string stat,QWidget *parent) :
        QWidget(parent), ui(new Ui::guiu), service(service), name(std::move(nam)), stat(std::move(stat)) {
    this->setWindowTitle(QCoreApplication::translate("guiu", this->name.c_str(), nullptr));
    ui->setupUi(this);
    this->service.addObserver(this);
    this->populateList();
    this->connectSignals();
}

guiu::~guiu() {
    delete ui;
}

void guiu::populateList() {
    this->ui->firstListWidget->clear();
    auto v=this->service.getAllIdeas();
    for(const auto& it : v){
        this->ui->firstListWidget->addItem(QString::fromStdString(it.getName()+","+it.getDescriprion()+","+it.getStatus()+","+std::to_string(it.getAct())));
    }
}

void guiu::connectSignals() {
    QObject::connect(this->ui->addPushButton,&QPushButton::clicked,this,&guiu::addIdeas);
    QObject::connect(this->ui->acceptPushButton,&QPushButton::clicked, this,&guiu::accepptIdea);
    QObject::connect(this->ui->developPushButton,&QPushButton::clicked,this,&guiu::showAccepted);
    QObject::connect(this->ui->savePushButton,&QPushButton::clicked,this,&guiu::saveIdeas);
}

void guiu::addIdeas() {
    auto t1=this->ui->descLineEdit->text().toStdString();
    auto t2=this->ui->actLineEdit->text().toInt();
    if(!this->service.checkIdea(t1,t2)){
        this->populateList();
        return;
    }
    this->service.addIdea(Idea(t1,"proposed",this->name,t2));
    this->populateList();
}

void guiu::accepptIdea() {
    auto sel=this->ui->firstListWidget->selectedItems();
    if(this->stat!="senior"){
        QMessageBox::critical(this, "Error", "You are not senior");
        this->populateList();
        return;
    }
    if(!sel.isEmpty())
    {
        auto a=sel[0]->text().toStdString();
        std::stringstream  str(a);
        std::string id;
        std::getline(str,id,',');
        std::getline(str,id,',');
        auto des=id;
        while(std::getline(str,id,','))
        {

        }
        this->service.acceptIdea(des,std::stoi(id));
        //this->accepted.push_back()
    }
    this->populateList();
}

void guiu::showAccepted() {
    auto v=this->service.getAcceptedIdeas();
    this->ui->secondlabListWidget->clear();
    for(const auto& it : v){
        this->ui->secondlabListWidget->addItem(QString::fromStdString(it.getName()+","+it.getDescriprion()+","+it.getStatus()+","+std::to_string(it.getAct())));
    }
}

void guiu::saveIdeas() {
    auto sel=this->ui->secondlabListWidget->selectedItems();
    if(!sel.isEmpty()){
        auto a=sel[0]->text().toStdString();
        std::stringstream  str(a);
        std::string id;
        std::getline(str,id,',');
        std::getline(str,id,',');
        auto des=id;
        while(std::getline(str,id,','))
        {

        }
        this->service.saveToFile(des,std::stoi(id));
    }
}

void guiu::update() {
    this->populateList();
}

