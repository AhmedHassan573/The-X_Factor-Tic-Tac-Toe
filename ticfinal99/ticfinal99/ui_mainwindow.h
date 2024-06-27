/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QRadioButton *radio1v1;
    QRadioButton *radioAI;
    QPushButton *startpushbutton;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QRadioButton *radioEasy;
    QRadioButton *radioMedium;
    QRadioButton *radioHard;
    QLabel *label;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QRadioButton *radiox;
    QRadioButton *radioO;
    QPushButton *quitpushbutton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(614, 426);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(96, 100, 441, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        radio1v1 = new QRadioButton(horizontalLayoutWidget);
        radio1v1->setObjectName("radio1v1");

        horizontalLayout->addWidget(radio1v1);

        radioAI = new QRadioButton(horizontalLayoutWidget);
        radioAI->setObjectName("radioAI");

        horizontalLayout->addWidget(radioAI);

        startpushbutton = new QPushButton(centralwidget);
        startpushbutton->setObjectName("startpushbutton");
        startpushbutton->setGeometry(QRect(116, 310, 161, 24));
        horizontalLayoutWidget_3 = new QWidget(centralwidget);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(96, 200, 461, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(horizontalLayoutWidget_3);
        label_4->setObjectName("label_4");

        horizontalLayout_3->addWidget(label_4);

        radioEasy = new QRadioButton(horizontalLayoutWidget_3);
        radioEasy->setObjectName("radioEasy");

        horizontalLayout_3->addWidget(radioEasy);

        radioMedium = new QRadioButton(horizontalLayoutWidget_3);
        radioMedium->setObjectName("radioMedium");

        horizontalLayout_3->addWidget(radioMedium);

        radioHard = new QRadioButton(horizontalLayoutWidget_3);
        radioHard->setObjectName("radioHard");

        horizontalLayout_3->addWidget(radioHard);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(236, 30, 201, 51));
        QFont font;
        font.setPointSize(26);
        font.setBold(true);
        label->setFont(font);
        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(96, 150, 441, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_2);
        label_3->setObjectName("label_3");

        horizontalLayout_2->addWidget(label_3);

        radiox = new QRadioButton(horizontalLayoutWidget_2);
        radiox->setObjectName("radiox");

        horizontalLayout_2->addWidget(radiox);

        radioO = new QRadioButton(horizontalLayoutWidget_2);
        radioO->setObjectName("radioO");

        horizontalLayout_2->addWidget(radioO);

        quitpushbutton = new QPushButton(centralwidget);
        quitpushbutton->setObjectName("quitpushbutton");
        quitpushbutton->setGeometry(QRect(320, 310, 161, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 614, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Players", nullptr));
        radio1v1->setText(QCoreApplication::translate("MainWindow", "Player vs Player", nullptr));
        radioAI->setText(QCoreApplication::translate("MainWindow", "Player vs AI", nullptr));
        startpushbutton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Level", nullptr));
        radioEasy->setText(QCoreApplication::translate("MainWindow", "Easy", nullptr));
        radioMedium->setText(QCoreApplication::translate("MainWindow", "Medium", nullptr));
        radioHard->setText(QCoreApplication::translate("MainWindow", "Hard", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TicTacToe", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Symbol", nullptr));
        radiox->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        radioO->setText(QCoreApplication::translate("MainWindow", "O", nullptr));
        quitpushbutton->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
