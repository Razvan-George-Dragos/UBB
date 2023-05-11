//
// Created by Razvan on 7/2/2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_guiunu.h" resolved

#include "guiunu.h"
#include <cassert>
#include <utility>
#include "ui_guiunu.h"
#include <sstream>

guiunu::guiunu(Service &service,std::string n,int scr,QWidget *parent) :
        QWidget(parent), ui(new Ui::guiunu), service(service),  name(std::move(n)), score(scr){
    this->setWindowTitle(QCoreApplication::translate("guiunu", this->name.c_str(), nullptr));
    ui->setupUi(this);
    this->service.addObserver(this);
    this->populateList();
    this->connectSignals();
}

guiunu::~guiunu() {
    delete ui;
}

void guiunu::populateList() {
    this->ui->listWidget->clear();
    if(this->name=="presenter"){
        this->service.sortbyid();
        auto vec=this->service.getAllQues();
        for(const auto& it : vec){
            this->ui->listWidget->addItem(QString::fromStdString(std::to_string(it.getId())+","+it.getText()+","+it.getCorrectAnswer()+","+std::to_string(it.getScore())));
        }
    }
    else{
        this->service.sortbyscore();
        auto vec=this->service.getAllQues();
        this->ui->listWidget->addItem(QString::fromStdString(" YOUR SCORE is "+std::to_string(this->score)));
        for(const auto& it : vec){
            this->ui->listWidget->addItem(QString::fromStdString(std::to_string(it.getId())+","+it.getText()+","+std::to_string(it.getScore())));
        }
        int index=0;
        for(const auto& it : vec){
            for(auto i : this->answered){
                if(it.getId()==i)
                    this->ui->listWidget->item(index+1)->setBackground(Qt::green);
            }
            index++;
        }
    }

}

void guiunu::connectSignals() {
    QObject::connect(this->ui->addPushButton,&QPushButton::clicked,this,&guiunu::addQuestion);
    QObject::connect(this->ui->pushButton,&QPushButton::clicked,this,&guiunu::answerQuestion);
    QObject::connect(this->ui->updatePushButton_2,&QPushButton::clicked, this,&guiunu::updateQuestion);
}

void guiunu::addQuestion() {
    if(this->name=="presenter")
    {
        auto t1=this->ui->idLineEdit->text().toInt();
        std::string t2=this->ui->textLineEdit->text().toStdString();
        std::string t3=this->ui->answerLineEdit->text().toStdString();
        if(this->service.valid_id(t1) && !t2.empty() && !t3.empty()){
            auto x=this->service.getAllQues().size();
            this->service.add(Question(t1,t2,t3,15));
            assert(this->service.getAllQues().size()==x+1);
            this->populateList();

        }
        else
            this->ui->listWidget->addItem(QString::fromStdString("you cannot add a question like this"));
    }
    else
        this->ui->listWidget->addItem(QString::fromStdString("you can't add questions if you are NOT presenter"));
}

void guiunu::answerQuestion() {
    auto sel=this->ui->listWidget->selectedItems();
    if(!sel.isEmpty()){
        auto x=sel[0]->text().toStdString();
        std::stringstream str(x);
        std::string id;
        std::getline(str,id,',');
        for(auto i : this->answered){
            if(i==std::stoi(id))
                return;
        }
        //qDebug()<<"aici intra";
        //qDebug()<<id.c_str();
        std::string a1=this->ui->answerLineEdit->text().toStdString();

        //qDebug()<<a1.c_str();
        if(this->service.checkAnswer(std::stoi(id),a1)>0)
        {
            //qDebug()<<"intra";
            this->answered.push_back(std::stoi(id));
            //this->score=this->score+this->service.checkAnswer(std::stoi(id),a1);
            this->score+=this->service.checkAnswer(std::stoi(id),a1);
            this->populateList();
        }
        else
            this->populateList();
    }
    else
        this->populateList();
}

void guiunu::update() {
    this->populateList();
}

void guiunu::updateQuestion() {
    auto sel=this->ui->listWidget->selectedItems();
    if(!sel.isEmpty())
    {
        auto x=sel[0]->text().toStdString();
        std::stringstream str(x);
        std::string id;
        std::getline(str,id,',');
        auto t1=this->ui->idLineEdit->text().toInt();
        auto t2=this->ui->textLineEdit->text().toStdString();
        auto t3=this->ui->answerLineEdit->text().toStdString();
        this->service.update(std::stoi(id),t1,t2,t3);
    }
    this->populateList();
}



