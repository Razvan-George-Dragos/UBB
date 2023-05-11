//
// Created by Razvan on 7/4/2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_guimv.h" resolved

#include "guimv.h"
#include "ui_guimv.h"
#include <QMessageBox>

guimv::guimv(Service& service,Modelvw* modelvw,std::string nam, std::string stat,QWidget *parent) :
        QWidget(parent), ui(new Ui::guimv), service(service), model(modelvw), name(std::move(nam)), stat(std::move(stat)) {
    ui->setupUi(this);
    this->ui->firstTableView->setModel(model);
    this->connectSignals();
}

guimv::~guimv() {
    delete ui;
}

void guimv::connectSignals() {
    QObject::connect(this->ui->addpushButton,&QPushButton::clicked,this,&guimv::addI);
    QObject::connect(this->ui->acceptpushButton,&QPushButton::clicked,this,&guimv::accept);
    QObject::connect(this->ui->developpushButton,&QPushButton::clicked,this,&guimv::develop);
    QObject::connect(this->ui->savepushButton,&QPushButton::clicked,this,&guimv::save);
}

void guimv::addI() {
    auto d=this->ui->descLineEdit->text().toStdString();
    auto a=this->ui->actLineEdit->text().toInt();
    if(d.empty() || a<1 || a>3)
    {
        QMessageBox::critical(this,"Error","This idea is NOT valid");
        return;
    }
    else if(!this->service.checkIdea(d,a))
    {
        QMessageBox::critical(this,"Error","This idea already exists");
        return;
    }
    Idea idea{d,"proposed",this->name,a};
    this->model->addIdea(idea);
}

void guimv::accept() {
    auto row=this->ui->firstTableView->currentIndex().row();
    if(row==-1)
        return;
    auto idea=this->service.getAllIdeas()[row];
    if(idea.getStatus()=="proposed" && this->stat=="senior")
    {
        this->model->acceptam(row);
    }
    else if(idea.getStatus()=="proposed")
        QMessageBox::critical(this,"Error","You are NOT senior");
    else
        QMessageBox::critical(this,"Error","This idea is already accepted");
}

void guimv::develop() {
    this->secondModel=new QStandardItemModel(0,0, this);
    this->ui->secondTableView->setModel(this->secondModel);
    auto vv=this->service.getAcceptedIdeas();
    int i=0;
    for(const auto& it : vv){
        auto* t1=new QStandardItem(QString::fromStdString(it.getDescriprion()));
        auto* t2=new QStandardItem(QString::fromStdString(it.getStatus()));
        auto* t3=new QStandardItem(QString::fromStdString(it.getName()));
        auto* t4=new QStandardItem(QString::fromStdString(std::to_string(it.getAct())));
        this->secondModel->setItem(i,0,t1);
        this->secondModel->setItem(i,1,t2);
        this->secondModel->setItem(i,2,t3);
        this->secondModel->setItem(i,3,t4);
        ++i;
    }
}

void guimv::save() {
    auto row=this->ui->secondTableView->currentIndex().row();
    this->service.saveToFile(row);
}

