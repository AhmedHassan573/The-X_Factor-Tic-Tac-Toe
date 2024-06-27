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
    QLabel *label_3;
    QLineEdit *LineEditUserName;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *LineEditPassword;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *loginpushButton;
    QPushButton *signuppushButton;
    QPushButton *quitpushButton;

    void setupUi(QDialog *screenlogin)
    {
        if (screenlogin->objectName().isEmpty())
            screenlogin->setObjectName("screenlogin");
        screenlogin->resize(443, 320);
        label = new QLabel(screenlogin);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 10, 201, 51));
        QFont font;
        font.setPointSize(26);
        font.setBold(true);
        label->setFont(font);
        horizontalLayoutWidget = new QWidget(screenlogin);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(20, 90, 401, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout->addWidget(label_3);

        LineEditUserName = new QLineEdit(horizontalLayoutWidget);
        LineEditUserName->setObjectName("LineEditUserName");

        horizontalLayout->addWidget(LineEditUserName);

        horizontalLayoutWidget_2 = new QWidget(screenlogin);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(20, 140, 401, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        LineEditPassword = new QLineEdit(horizontalLayoutWidget_2);
        LineEditPassword->setObjectName("LineEditPassword");

        horizontalLayout_2->addWidget(LineEditPassword);

        horizontalLayoutWidget_3 = new QWidget(screenlogin);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(80, 220, 291, 41));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        loginpushButton = new QPushButton(horizontalLayoutWidget_3);
        loginpushButton->setObjectName("loginpushButton");

        horizontalLayout_3->addWidget(loginpushButton);

        signuppushButton = new QPushButton(horizontalLayoutWidget_3);
        signuppushButton->setObjectName("signuppushButton");

        horizontalLayout_3->addWidget(signuppushButton);

        quitpushButton = new QPushButton(horizontalLayoutWidget_3);
        quitpushButton->setObjectName("quitpushButton");

        horizontalLayout_3->addWidget(quitpushButton);


        retranslateUi(screenlogin);

        QMetaObject::connectSlotsByName(screenlogin);
    } // setupUi

    void retranslateUi(QDialog *screenlogin)
    {
        screenlogin->setWindowTitle(QCoreApplication::translate("screenlogin", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("screenlogin", "TicTacToe", nullptr));
        label_3->setText(QCoreApplication::translate("screenlogin", "User Name", nullptr));
        label_2->setText(QCoreApplication::translate("screenlogin", "Password", nullptr));
        loginpushButton->setText(QCoreApplication::translate("screenlogin", "Login", nullptr));
        signuppushButton->setText(QCoreApplication::translate("screenlogin", "Signup", nullptr));
        quitpushButton->setText(QCoreApplication::translate("screenlogin", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class screenlogin: public Ui_screenlogin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENLOGIN_H
