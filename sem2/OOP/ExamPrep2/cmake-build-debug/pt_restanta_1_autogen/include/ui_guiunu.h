/********************************************************************************
** Form generated from reading UI file 'guiunu.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIUNU_H
#define UI_GUIUNU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_guiunu
{
public:
    QListWidget *listWidget;
    QLabel *label;
    QLineEdit *idLineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *textLineEdit;
    QLineEdit *answerLineEdit;
    QPushButton *addPushButton;
    QPushButton *pushButton;
    QPushButton *updatePushButton_2;

    void setupUi(QWidget *guiunu)
    {
        if (guiunu->objectName().isEmpty())
            guiunu->setObjectName(QString::fromUtf8("guiunu"));
        guiunu->resize(604, 493);
        listWidget = new QListWidget(guiunu);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(20, 10, 311, 251));
        label = new QLabel(guiunu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 290, 63, 20));
        idLineEdit = new QLineEdit(guiunu);
        idLineEdit->setObjectName(QString::fromUtf8("idLineEdit"));
        idLineEdit->setGeometry(QRect(82, 290, 171, 26));
        label_2 = new QLabel(guiunu);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 340, 63, 20));
        label_3 = new QLabel(guiunu);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 380, 63, 20));
        textLineEdit = new QLineEdit(guiunu);
        textLineEdit->setObjectName(QString::fromUtf8("textLineEdit"));
        textLineEdit->setGeometry(QRect(80, 340, 171, 26));
        answerLineEdit = new QLineEdit(guiunu);
        answerLineEdit->setObjectName(QString::fromUtf8("answerLineEdit"));
        answerLineEdit->setGeometry(QRect(80, 380, 171, 26));
        addPushButton = new QPushButton(guiunu);
        addPushButton->setObjectName(QString::fromUtf8("addPushButton"));
        addPushButton->setGeometry(QRect(20, 440, 93, 29));
        pushButton = new QPushButton(guiunu);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(160, 440, 93, 29));
        updatePushButton_2 = new QPushButton(guiunu);
        updatePushButton_2->setObjectName(QString::fromUtf8("updatePushButton_2"));
        updatePushButton_2->setGeometry(QRect(300, 440, 93, 29));

        retranslateUi(guiunu);

        QMetaObject::connectSlotsByName(guiunu);
    } // setupUi

    void retranslateUi(QWidget *guiunu)
    {
        //guiunu->setWindowTitle(QCoreApplication::translate("guiunu", "guiunu", nullptr));
        label->setText(QCoreApplication::translate("guiunu", "id", nullptr));
        label_2->setText(QCoreApplication::translate("guiunu", "text", nullptr));
        label_3->setText(QCoreApplication::translate("guiunu", "answer", nullptr));
        addPushButton->setText(QCoreApplication::translate("guiunu", "Add", nullptr));
        pushButton->setText(QCoreApplication::translate("guiunu", "Answer", nullptr));
        updatePushButton_2->setText(QCoreApplication::translate("guiunu", "Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class guiunu: public Ui_guiunu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIUNU_H
