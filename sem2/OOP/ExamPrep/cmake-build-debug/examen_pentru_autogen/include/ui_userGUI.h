/********************************************************************************
** Form generated from reading UI file 'usergui.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERGUI_H
#define UI_USERGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userGUI
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *QestionTextlineEdit;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *addPushButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLineEdit *answearLpineEdit;
    QPushButton *answerPushButton;
    QLabel *label_2;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *questionListWidget;
    QListWidget *answearsListWidget;
    QSpinBox *spinBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *userGUI)
    {
        if (userGUI->objectName().isEmpty())
            userGUI->setObjectName(QString::fromUtf8("userGUI"));
        userGUI->resize(990, 619);
        layoutWidget = new QWidget(userGUI);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 470, 291, 127));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        QestionTextlineEdit = new QLineEdit(layoutWidget);
        QestionTextlineEdit->setObjectName(QString::fromUtf8("QestionTextlineEdit"));

        gridLayout->addWidget(QestionTextlineEdit, 0, 0, 1, 1);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 2, 0, 1, 1);

        addPushButton = new QPushButton(layoutWidget);
        addPushButton->setObjectName(QString::fromUtf8("addPushButton"));

        gridLayout->addWidget(addPushButton, 3, 0, 1, 1);

        layoutWidget1 = new QWidget(userGUI);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(510, 450, 391, 101));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        answearLpineEdit = new QLineEdit(layoutWidget1);
        answearLpineEdit->setObjectName(QString::fromUtf8("answearLpineEdit"));

        horizontalLayout->addWidget(answearLpineEdit);

        answerPushButton = new QPushButton(layoutWidget1);
        answerPushButton->setObjectName(QString::fromUtf8("answerPushButton"));

        horizontalLayout->addWidget(answerPushButton);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        layoutWidget2 = new QWidget(userGUI);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(25, 11, 901, 431));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        questionListWidget = new QListWidget(layoutWidget2);
        questionListWidget->setObjectName(QString::fromUtf8("questionListWidget"));

        horizontalLayout_2->addWidget(questionListWidget);

        answearsListWidget = new QListWidget(layoutWidget2);
        answearsListWidget->setObjectName(QString::fromUtf8("answearsListWidget"));

        horizontalLayout_2->addWidget(answearsListWidget);

        spinBox = new QSpinBox(userGUI);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(781, 570, 61, 26));
        widget = new QWidget(userGUI);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(520, 560, 195, 41));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_3->addWidget(pushButton_3);


        retranslateUi(userGUI);

        QMetaObject::connectSlotsByName(userGUI);
    } // setupUi

    void retranslateUi(QWidget *userGUI)
    {
        //userGUI->setWindowTitle(QCoreApplication::translate("userGUI", "userGUI", nullptr));
        label->setText(QCoreApplication::translate("userGUI", "Text", nullptr));
        pushButton->setText(QCoreApplication::translate("userGUI", "search", nullptr));
        addPushButton->setText(QCoreApplication::translate("userGUI", "add Question", nullptr));
        answerPushButton->setText(QCoreApplication::translate("userGUI", "add Answer", nullptr));
        label_2->setText(QCoreApplication::translate("userGUI", "response", nullptr));
        pushButton_2->setText(QCoreApplication::translate("userGUI", "Up Vote", nullptr));
        pushButton_3->setText(QCoreApplication::translate("userGUI", "Down Vote", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userGUI: public Ui_userGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERGUI_H
