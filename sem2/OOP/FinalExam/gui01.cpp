//
// Created by Razvan on 7/6/2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_gui01.h" resolved

#include "gui01.h"
#include "ui_gui01.h"
#include <QMessageBox>
#include <sstream>
gui01::gui01(Service& service,std::string n,QWidget *parent) :
        QWidget(parent), ui(new Ui::gui01), service(service), name(std::move(n)) {
    ui->setupUi(this);
    this->service.addObserver(this);
    this->umpluSubs();
    this->PopulateList();
    this->connectSingals();
}

gui01::~gui01() {
    delete ui;
}

void gui01::PopulateList() {
    this->ui->postsListWidget->clear();
    this->ui->subsListWidget->clear();
    this->ui->feedListWidget->clear();
    this->ui->topicsListWidget->clear();
    auto v=this->service.getAllPosts();
    for(const auto& it : v){
        if(it.getUser()== this->name)
            this->ui->postsListWidget->addItem(QString::fromStdString(std::to_string(it.getId())+","+it.getText()+","+std::to_string(it.getDate())+","+std::to_string(it.getTime())+","+it.getUser()));
    }
    if(!this->subscribed.empty())
    {
        for(const auto& it : this->subscribed)
            this->ui->subsListWidget->addItem(QString::fromStdString(it));
        /*for(const auto& it : v)
        {
            for(const auto& itr : this->subscribed)
            {
                if(it.getText().find("#"+itr))
                    this->ui->feedListWidget->addItem(QString::fromStdString(std::to_string(it.getId())+","+it.getText()+","+std::to_string(it.getDate())+","+std::to_string(it.getTime())+","+it.getUser()));

            }
        }*/
    }
    int i=0;
    for(const auto& it : v){
        std::string a="@"+this->name;

        if(it.getText().find(a)>=0) {
            this->ui->feedListWidget->addItem(QString::fromStdString(
                    std::to_string(it.getId()) + "," + it.getText() + "," + std::to_string(it.getDate()) + "," +
                    std::to_string(it.getTime()) + "," + it.getUser()));
            if(it.getUser()==this->name)
                this->ui->feedListWidget->item(i)->setBackground(Qt::blue);
            i++;
        }

    }
    //int i=0;
    for(auto it : this->service.getTopics())
    {
        this->ui->topicsListWidget->addItem(QString::fromStdString(/*std::to_string(i)+","+*/it.getName()));
        //i++;
    }

}

void gui01::connectSingals() {
    QObject::connect(this->ui->subscribePushButton,&QPushButton::clicked,this,&gui01::subscribe);
    QObject::connect(this->ui->addPushButton,&QPushButton::clicked,this,&gui01::add);
    QObject::connect(this->ui->updatePushButton,&QPushButton::clicked,this,&gui01::updatep);
}

void gui01::subscribe() {
    auto sel=this->ui->topicsListWidget->selectedItems();
    if(!sel.isEmpty())
    {
       // qDebug()<<"intra";
        auto x=sel[0]->text().toStdString();
        this->subscribed.push_back(x);
        this->service.addUserToTopic(x,this->name);
        this->PopulateList();
    }

}

void gui01::add() {
    auto t1=this->ui->textLineEdit->text().toStdString();
    auto t2=this->ui->idLineEdit->text().toInt();
    auto t3=this->ui->dateLineEdit->text().toInt();
    auto t4=this->ui->timeLineEdit->text().toInt();
    if(t1.size()<3)
    {
        QMessageBox::critical(this,"Error","The text must be longer than 3");
        return;
    }
    if(t3<0||t3>31||t4<0||t4>24){
        QMessageBox::critical(this,"Error","Invalid date/time");
        return;
    }

    this->service.addPost(Post(t2,t1,t3,t4,this->name));
    this->PopulateList();
}

void gui01::updatep() {
    auto sel=this->ui->feedListWidget->selectedItems();
    if(!sel.isEmpty())
    {
        auto x=sel[0]->text().toStdString();
        std::stringstream str(x);
        std::string id;
        std::getline(str,id,',');
        auto t1=this->ui->textLineEdit->text().toStdString();
        auto t2=this->ui->idLineEdit->text().toInt();
        auto t3=this->ui->dateLineEdit->text().toInt();
        auto t4=this->ui->timeLineEdit->text().toInt();
        if(t1.size()<3){
            QMessageBox::critical(this,"Error","The text has to be longer than 3");
            return;
        }
        if(t3<0||t3>31||t4<0||t4>24){
            QMessageBox::critical(this,"Error","Invalid date/time");
            return;
        }
        this->service.updatePose(std::stoi(id),t2,t1,t3,t4,this->name);
        this->PopulateList();
    }


}

void gui01::update() {
    this->PopulateList();
}

void gui01::umpluSubs() {
    auto s=this->service.getTopics();
    for(auto it : s)
    {
        for(const auto& n : it.getUsers())
        {
            if(n==this->name)
                this->subscribed.push_back(it.getName());
        }
    }
}

