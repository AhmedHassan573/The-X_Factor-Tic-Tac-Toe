/********************************************************************************
** Form generated from reading UI file 'screenloginai.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENLOGINAI_H
#define UI_SCREENLOGINAI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_screenloginai
{
public:
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *UsernameAI;
    QLineEdit *lineEditUserNameAI;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *PasswordAI;
    QLineEdit *lineEditPasswordAI;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *loginpushbuttonai;
    QPushButton *signuppushbuttonai;
    QPushButton *screenloginAIMainwindowbutton;
    QPushButton *showscreenbuttonloginai;

    void setupUi(QDialog *screenloginai)
    {
        if (screenloginai->objectName().isEmpty())
            screenloginai->setObjectName("screenloginai");
        screenloginai->resize(561, 402);
        label = new QLabel(screenloginai);
        label->setObjectName("label");
        label->setGeometry(QRect(190, 20, 201, 51));
        QFont font;
        font.setPointSize(26);
        font.setBold(true);
        label->setFont(font);
        horizontalLayoutWidget = new QWidget(screenloginai);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(80, 120, 371, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        UsernameAI = new QLabel(horizontalLayoutWidget);
        UsernameAI->setObjectName("UsernameAI");

        horizontalLayout->addWidget(UsernameAI);

        lineEditUserNameAI = new QLineEdit(horizontalLayoutWidget);
        lineEditUserNameAI->setObjectName("lineEditUserNameAI");

        horizontalLayout->addWidget(lineEditUserNameAI);

        horizontalLayoutWidget_2 = new QWidget(screenloginai);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(80, 180, 371, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        PasswordAI = new QLabel(horizontalLayoutWidget_2);
        PasswordAI->setObjectName("PasswordAI");

        horizontalLayout_2->addWidget(PasswordAI);

        lineEditPasswordAI = new QLineEdit(horizontalLayoutWidget_2);
        lineEditPasswordAI->setObjectName("lineEditPasswordAI");

        horizontalLayout_2->addWidget(lineEditPasswordAI);

        horizontalLayoutWidget_3 = new QWidget(screenloginai);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(70, 270, 400, 41));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        loginpushbuttonai = new QPushButton(horizontalLayoutWidget_3);
        loginpushbuttonai->setObjectName("loginpushbuttonai");

        horizontalLayout_3->addWidget(loginpushbuttonai);

        signuppushbuttonai = new QPushButton(horizontalLayoutWidget_3);
        signuppushbuttonai->setObjectName("signuppushbuttonai");

        horizontalLayout_3->addWidget(signuppushbuttonai);

        screenloginAIMainwindowbutton = new QPushButton(horizontalLayoutWidget_3);
        screenloginAIMainwindowbutton->setObjectName("screenloginAIMainwindowbutton");

        horizontalLayout_3->addWidget(screenloginAIMainwindowbutton);

        showscreenbuttonloginai = new QPushButton(horizontalLayoutWidget_3);
        showscreenbuttonloginai->setObjectName("showscreenbuttonloginai");

        horizontalLayout_3->addWidget(showscreenbuttonloginai);


        retranslateUi(screenloginai);

        QMetaObject::connectSlotsByName(screenloginai);
    } // setupUi

    void retranslateUi(QDialog *screenloginai)
    {
        screenloginai->setWindowTitle(QCoreApplication::translate("screenloginai", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("screenloginai", "TicTacToe", nullptr));
        UsernameAI->setText(QCoreApplication::translate("screenloginai", "User Name", nullptr));
        PasswordAI->setText(QCoreApplication::translate("screenloginai", "Password", nullptr));
        loginpushbuttonai->setText(QCoreApplication::translate("screenloginai", "Login", nullptr));
        signuppushbuttonai->setText(QCoreApplication::translate("screenloginai", "Signup", nullptr));
        screenloginAIMainwindowbutton->setText(QCoreApplication::translate("screenloginai", "Back to MainMenu", nullptr));
        showscreenbuttonloginai->setText(QCoreApplication::translate("screenloginai", "ShowScore and Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class screenloginai: public Ui_screenloginai {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENLOGINAI_H
