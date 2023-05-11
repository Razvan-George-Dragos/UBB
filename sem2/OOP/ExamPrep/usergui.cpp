//
// Created by Razvan on 6/13/2022.
//

// You may need to build the project (run Qt uic code generator) to get "ui_userGUI.h" resolved

#include "usergui.h"
#include "ui_userGUI.h"
#include "sstream"
#include <cstring>
userGUI::userGUI(Service &service,std::string name,QWidget *parent) :
        QWidget(parent), ui(new Ui::userGUI), service(service), name(std::move(name)) {
    ui->setupUi(this);
    this->service.addObserver(this);
    this->setWindowTitle(QCoreApplication::translate("userGUI", this->name.c_str(), nullptr));
    //userGUI->setWindowTitle(QCoreApplication::translate("userGUI", "userGUI", nullptr));
    this->populateQuestions();
    this->emitSignals();
}

userGUI::~userGUI() {
    delete ui;
}

void userGUI::populateQuestions() {
    this->ui->questionListWidget->clear();
    std::vector<Question> vct=this->service.getAllQuestions();
    for(const auto& it : vct){
        this->ui->questionListWidget->addItem(QString::fromStdString(std::to_string(it.getId())+", "+it.getText()+", "+it.getNameOfUser()));
    }
}

void userGUI::addQuestion() {
    std::string text=this->ui->QestionTextlineEdit->text().toStdString();
    if(text.empty()){
        this->populateQuestions();
        return;
    }
    this->service.add_question(Question(this->service.getAllQuestions().size()+1,text,this->name));
    this->populateQuestions();
}

void userGUI::emitSignals() {
    QObject::connect(this->ui->addPushButton, &QPushButton::clicked, this, &userGUI::addQuestion);
    QObject::connect(this->ui->questionListWidget, &QListWidget::itemSelectionChanged, [&](){
        auto sel = this->ui->questionListWidget->selectedItems();
        if(!sel.isEmpty()){
            auto x = sel[0]->text().toStdString();
            std::stringstream str(x);
            std::string id;
            std::getline(str,id,',');
            auto y=std::stoi(id);
            this->populateAnswers(y);
        }
    });
    QObject::connect(this->ui->answerPushButton, &QPushButton::clicked, this, &userGUI::addAnswer);
    QObject::connect(this->ui->answearsListWidget, &QListWidget::itemSelectionChanged,[&](){
        auto sele=this->ui->answearsListWidget->selectedItems();
        if(!sele.isEmpty()){
            auto a = sele[0]->text().toStdString();
            std::stringstream  str(a);
            std::string id;
            std::getline(str,id,',');
            int i=0;
            while(std::getline(str,id,','))
            {
                i++;
            }
            qDebug()<<i;
            this->ui->spinBox->setValue(std::stoi(id));

        }
    });
    QObject::connect(this->ui->spinBox, &QSpinBox::valueChanged, this, [&](){
       auto i=this->ui->spinBox->value();
       //qDebug()<<i;
       auto s=this->ui->answearsListWidget->selectedItems();
       if(!s.isEmpty()){
           auto b=s[0]->text().toStdString();
           std::stringstream str(b);
           std::string id;
           std::getline(str,id,',');
           //qDebug()<<std::stoi(id);
           //std::string idq=id;
           //std::getline(str,id,',');
           this->service.voteAnswer(std::stoi(id),i);
           //this->ui->spinBox->setDisabled(true);
           //this->populateAnswers(std::stoi(idq));
       }
    });
    //QObject::connect(this->ui->QestionTextlineEdit, &QLineEdit::textChanged,this,)
}

void userGUI::populateAnswers(int i) {
    this->ui->answearsListWidget->clear();
    std::vector<Answear> va=this->service.getAnswearsForAQuestion(i);
    if(va.empty())
    {
        this->ui->answearsListWidget->addItem(QString::fromStdString("This question has 0 answers"));
        return;
    }
    for(const auto& it : va)
    {
        this->ui->answearsListWidget->addItem(QString::fromStdString(std::to_string(it.getId())+", "+it.getText()+", "+it.getUserName()+", "+std::to_string(it.getNrVotes())));
    }
    int index=0;
    for(const auto& it : va)
    {
        if(it.getUserName()==this->name)
            this->ui->answearsListWidget->item(index)->setBackground(Qt::blue);
        index++;
    }
}

void userGUI::addAnswer()
{
    auto sel = this->ui->questionListWidget->selectedItems();
    std::string text=this->ui->answearLpineEdit->text().toStdString();
    if(text.empty())
        return;
    if(!sel.isEmpty())
    {
        auto x = sel[0]->text().toStdString();
        std::stringstream str(x);
        std::string id;
        std::getline(str,id,',');
        auto y=std::stoi(id);
        this->service.add_answaer(Answear(this->service.getAllAnswears().size()+1,y,text,this->name,0));
        this->service.sortAnswers();
        this->populateAnswers(y);
    }
}

void userGUI::update()
{
    this->populateQuestions();
}

