/********************************************************************************
** Form generated from reading UI file 'guiu.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIU_H
#define UI_GUIU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_guiu
{
public:
    QListWidget *firstListWidget;
    QListWidget *secondlabListWidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *descLineEdit;
    QLineEdit *actLineEdit;
    QPushButton *addPushButton;
    QPushButton *acceptPushButton;
    QPushButton *savePushButton;
    QPushButton *developPushButton;
    QPushButton *pushButton;

    void setupUi(QWidget *guiu)
    {
        if (guiu->objectName().isEmpty())
            guiu->setObjectName(QString::fromUtf8("guiu"));
        guiu->resize(610, 512);
        firstListWidget = new QListWidget(guiu);
        firstListWidget->setObjectName(QString::fromUtf8("firstListWidget"));
        firstListWidget->setGeometry(QRect(10, 20, 281, 271));
        secondlabListWidget = new QListWidget(guiu);
        secondlabListWidget->setObjectName(QString::fromUtf8("secondlabListWidget"));
        secondlabListWidget->setGeometry(QRect(320, 20, 251, 271));
        label = new QLabel(guiu);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 320, 81, 20));
        label_2 = new QLabel(guiu);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 370, 63, 20));
        descLineEdit = new QLineEdit(guiu);
        descLineEdit->setObjectName(QString::fromUtf8("descLineEdit"));
        descLineEdit->setGeometry(QRect(110, 320, 171, 26));
        actLineEdit = new QLineEdit(guiu);
        actLineEdit->setObjectName(QString::fromUtf8("actLineEdit"));
        actLineEdit->setGeometry(QRect(110, 370, 171, 26));
        addPushButton = new QPushButton(guiu);
        addPushButton->setObjectName(QString::fromUtf8("addPushButton"));
        addPushButton->setGeometry(QRect(30, 440, 93, 29));
        acceptPushButton = new QPushButton(guiu);
        acceptPushButton->setObjectName(QString::fromUtf8("acceptPushButton"));
        acceptPushButton->setGeometry(QRect(150, 440, 93, 29));
        savePushButton = new QPushButton(guiu);
        savePushButton->setObjectName(QString::fromUtf8("savePushButton"));
        savePushButton->setGeometry(QRect(280, 440, 93, 29));
        developPushButton = new QPushButton(guiu);
        developPushButton->setObjectName(QString::fromUtf8("developPushButton"));
        developPushButton->setGeometry(QRect(390, 330, 93, 29));
        pushButton = new QPushButton(guiu);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(440, 440, 93, 29));

        retranslateUi(guiu);

        QMetaObject::connectSlotsByName(guiu);
    } // setupUi

    void retranslateUi(QWidget *guiu)
    {
        //guiu->setWindowTitle(QCoreApplication::translate("guiu", "guiu", nullptr));
        label->setText(QCoreApplication::translate("guiu", "description", nullptr));
        label_2->setText(QCoreApplication::translate("guiu", "actl", nullptr));
        addPushButton->setText(QCoreApplication::translate("guiu", "add", nullptr));
        acceptPushButton->setText(QCoreApplication::translate("guiu", "accept", nullptr));
        savePushButton->setText(QCoreApplication::translate("guiu", "save", nullptr));
        developPushButton->setText(QCoreApplication::translate("guiu", "develop", nullptr));
        pushButton->setText(QCoreApplication::translate("guiu", "save plot", nullptr));
    } // retranslateUi

};

namespace Ui {
    class guiu: public Ui_guiu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIU_H
