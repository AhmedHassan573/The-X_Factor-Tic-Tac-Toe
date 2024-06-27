/********************************************************************************
** Form generated from reading UI file 'titlegameboard.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLEGAMEBOARD_H
#define UI_TITLEGAMEBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_titlegameboard
{
public:
    QLabel *label;
    QPushButton *button1;
    QPushButton *button2;
    QPushButton *button3;
    QPushButton *button4;
    QPushButton *button5;
    QPushButton *button6;
    QPushButton *button7;
    QPushButton *button8;
    QPushButton *button9;
    QLabel *winner;
    QLabel *turnLabel;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *startNewGame;
    QPushButton *titleMainwindowbutton;

    void setupUi(QDialog *titlegameboard)
    {
        if (titlegameboard->objectName().isEmpty())
            titlegameboard->setObjectName("titlegameboard");
        titlegameboard->resize(607, 491);
        label = new QLabel(titlegameboard);
        label->setObjectName("label");
        label->setGeometry(QRect(200, 20, 201, 51));
        QFont font;
        font.setPointSize(26);
        font.setBold(true);
        label->setFont(font);
        button1 = new QPushButton(titlegameboard);
        button1->setObjectName("button1");
        button1->setGeometry(QRect(120, 120, 111, 81));
        button2 = new QPushButton(titlegameboard);
        button2->setObjectName("button2");
        button2->setGeometry(QRect(230, 120, 111, 81));
        button3 = new QPushButton(titlegameboard);
        button3->setObjectName("button3");
        button3->setGeometry(QRect(340, 120, 111, 81));
        button4 = new QPushButton(titlegameboard);
        button4->setObjectName("button4");
        button4->setGeometry(QRect(120, 200, 111, 81));
        button5 = new QPushButton(titlegameboard);
        button5->setObjectName("button5");
        button5->setGeometry(QRect(230, 200, 111, 81));
        button6 = new QPushButton(titlegameboard);
        button6->setObjectName("button6");
        button6->setGeometry(QRect(340, 200, 111, 81));
        button7 = new QPushButton(titlegameboard);
        button7->setObjectName("button7");
        button7->setGeometry(QRect(120, 280, 111, 81));
        button8 = new QPushButton(titlegameboard);
        button8->setObjectName("button8");
        button8->setGeometry(QRect(230, 280, 111, 81));
        button9 = new QPushButton(titlegameboard);
        button9->setObjectName("button9");
        button9->setGeometry(QRect(340, 280, 111, 81));
        winner = new QLabel(titlegameboard);
        winner->setObjectName("winner");
        winner->setGeometry(QRect(60, 80, 111, 20));
        turnLabel = new QLabel(titlegameboard);
        turnLabel->setObjectName("turnLabel");
        turnLabel->setGeometry(QRect(90, 80, 281, 21));
        horizontalLayoutWidget = new QWidget(titlegameboard);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(90, 400, 381, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        startNewGame = new QPushButton(horizontalLayoutWidget);
        startNewGame->setObjectName("startNewGame");

        horizontalLayout->addWidget(startNewGame);

        titleMainwindowbutton = new QPushButton(horizontalLayoutWidget);
        titleMainwindowbutton->setObjectName("titleMainwindowbutton");

        horizontalLayout->addWidget(titleMainwindowbutton);


        retranslateUi(titlegameboard);

        QMetaObject::connectSlotsByName(titlegameboard);
    } // setupUi

    void retranslateUi(QDialog *titlegameboard)
    {
        titlegameboard->setWindowTitle(QCoreApplication::translate("titlegameboard", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("titlegameboard", "TicTacToe", nullptr));
        button1->setText(QString());
        button2->setText(QString());
        button3->setText(QString());
        button4->setText(QString());
        button5->setText(QString());
        button6->setText(QString());
        button7->setText(QString());
        button8->setText(QString());
        button9->setText(QString());
        winner->setText(QString());
        turnLabel->setText(QCoreApplication::translate("titlegameboard", "TextLabel", nullptr));
        startNewGame->setText(QCoreApplication::translate("titlegameboard", "New Game", nullptr));
        titleMainwindowbutton->setText(QCoreApplication::translate("titlegameboard", "Back to MainMenu", nullptr));
    } // retranslateUi

};

namespace Ui {
    class titlegameboard: public Ui_titlegameboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLEGAMEBOARD_H
