/********************************************************************************
** Form generated from reading UI file 'screenlogin.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENLOGIN_H
#define UI_SCREENLOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_screenlogin
{
public:
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *UserName1;
    QLineEdit *LineEditUserName1;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Password1;
    QLineEdit *LineEditPassword1;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *loginpushButton;
    QPushButton *showscreenbuttonlogin;
    QPushButton *signuppushButton;
    QPushButton *screenloginMainwindowbutton;
    QPushButton *quitpushButton;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *UserName2;
    QLineEdit *LineEditUserName2;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_5;
    QLabel *Password2;
    QLineEdit *LineEditPassword2;

    void setupUi(QDialog *screenlogin)
    {
        if (screenlogin->objectName().isEmpty())
            screenlogin->setObjectName("screenlogin");
        screenlogin->resize(540, 421);
        label = new QLabel(screenlogin);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 10, 201, 51));
        QFont font;
        font.setPointSize(26);
        font.setBold(true);
        label->setFont(font);
        horizontalLayoutWidget = new QWidget(screenlogin);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(50, 90, 401, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        UserName1 = new QLabel(horizontalLayoutWidget);
        UserName1->setObjectName("UserName1");

        horizontalLayout->addWidget(UserName1);

        LineEditUserName1 = new QLineEdit(horizontalLayoutWidget);
        LineEditUserName1->setObjectName("LineEditUserName1");

        horizontalLayout->addWidget(LineEditUserName1);

        horizontalLayoutWidget_2 = new QWidget(screenlogin);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(50, 140, 401, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        Password1 = new QLabel(horizontalLayoutWidget_2);
        Password1->setObjectName("Password1");

        horizontalLayout_2->addWidget(Password1);

        LineEditPassword1 = new QLineEdit(horizontalLayoutWidget_2);
        LineEditPassword1->setObjectName("LineEditPassword1");

        horizontalLayout_2->addWidget(LineEditPassword1);

        horizontalLayoutWidget_3 = new QWidget(screenlogin);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(20, 320, 481, 41));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        loginpushButton = new QPushButton(horizontalLayoutWidget_3);
        loginpushButton->setObjectName("loginpushButton");

        horizontalLayout_3->addWidget(loginpushButton);

        showscreenbuttonlogin = new QPushButton(horizontalLayoutWidget_3);
        showscreenbuttonlogin->setObjectName("showscreenbuttonlogin");

        horizontalLayout_3->addWidget(showscreenbuttonlogin);

        signuppushButton = new QPushButton(horizontalLayoutWidget_3);
        signuppushButton->setObjectName("signuppushButton");

        horizontalLayout_3->addWidget(signuppushButton);

        screenloginMainwindowbutton = new QPushButton(horizontalLayoutWidget_3);
        screenloginMainwindowbutton->setObjectName("screenloginMainwindowbutton");

        horizontalLayout_3->addWidget(screenloginMainwindowbutton);

        quitpushButton = new QPushButton(horizontalLayoutWidget_3);
        quitpushButton->setObjectName("quitpushButton");

        horizontalLayout_3->addWidget(quitpushButton);

        horizontalLayoutWidget_4 = new QWidget(screenlogin);
        horizontalLayoutWidget_4->setObjectName("horizontalLayoutWidget_4");
        horizontalLayoutWidget_4->setGeometry(QRect(50, 190, 401, 31));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        UserName2 = new QLabel(horizontalLayoutWidget_4);
        UserName2->setObjectName("UserName2");

        horizontalLayout_4->addWidget(UserName2);

        LineEditUserName2 = new QLineEdit(horizontalLayoutWidget_4);
        LineEditUserName2->setObjectName("LineEditUserName2");

        horizontalLayout_4->addWidget(LineEditUserName2);

        horizontalLayoutWidget_5 = new QWidget(screenlogin);
        horizontalLayoutWidget_5->setObjectName("horizontalLayoutWidget_5");
        horizontalLayoutWidget_5->setGeometry(QRect(50, 240, 401, 31));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        Password2 = new QLabel(horizontalLayoutWidget_5);
        Password2->setObjectName("Password2");

        horizontalLayout_5->addWidget(Password2);

        LineEditPassword2 = new QLineEdit(horizontalLayoutWidget_5);
        LineEditPassword2->setObjectName("LineEditPassword2");

        horizontalLayout_5->addWidget(LineEditPassword2);


        retranslateUi(screenlogin);

        QMetaObject::connectSlotsByName(screenlogin);
    } // setupUi

    void retranslateUi(QDialog *screenlogin)
    {
        screenlogin->setWindowTitle(QCoreApplication::translate("screenlogin", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("screenlogin", "TicTacToe", nullptr));
        UserName1->setText(QCoreApplication::translate("screenlogin", "UserName1", nullptr));
        Password1->setText(QCoreApplication::translate("screenlogin", "Password1", nullptr));
        loginpushButton->setText(QCoreApplication::translate("screenlogin", "Login", nullptr));
        showscreenbuttonlogin->setText(QCoreApplication::translate("screenlogin", "ShowScore and Login", nullptr));
        signuppushButton->setText(QCoreApplication::translate("screenlogin", "Signup", nullptr));
        screenloginMainwindowbutton->setText(QCoreApplication::translate("screenlogin", "Back to MainMenu", nullptr));
        quitpushButton->setText(QCoreApplication::translate("screenlogin", "Quit", nullptr));
        UserName2->setText(QCoreApplication::translate("screenlogin", "User Name2", nullptr));
        Password2->setText(QCoreApplication::translate("screenlogin", "Password2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class screenlogin: public Ui_screenlogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENLOGIN_H
