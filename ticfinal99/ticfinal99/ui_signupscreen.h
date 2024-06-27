/********************************************************************************
** Form generated from reading UI file 'signupscreen.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPSCREEN_H
#define UI_SIGNUPSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_signupscreen
{
public:
    QLabel *label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *UserNamesignup;
    QLineEdit *lineEditUserNameSignup;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Passwordsignup;
    QLineEdit *lineEditPasswordSignup;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *okpushbuttonsignup;
    QPushButton *signupMainwindowbutton;
    QPushButton *quitsignuppushbutton;

    void setupUi(QDialog *signupscreen)
    {
        if (signupscreen->objectName().isEmpty())
            signupscreen->setObjectName("signupscreen");
        signupscreen->resize(462, 344);
        label = new QLabel(signupscreen);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 20, 201, 51));
        QFont font;
        font.setPointSize(26);
        font.setBold(true);
        label->setFont(font);
        horizontalLayoutWidget = new QWidget(signupscreen);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(40, 100, 391, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        UserNamesignup = new QLabel(horizontalLayoutWidget);
        UserNamesignup->setObjectName("UserNamesignup");

        horizontalLayout->addWidget(UserNamesignup);

        lineEditUserNameSignup = new QLineEdit(horizontalLayoutWidget);
        lineEditUserNameSignup->setObjectName("lineEditUserNameSignup");

        horizontalLayout->addWidget(lineEditUserNameSignup);

        horizontalLayoutWidget_2 = new QWidget(signupscreen);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(40, 150, 391, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        Passwordsignup = new QLabel(horizontalLayoutWidget_2);
        Passwordsignup->setObjectName("Passwordsignup");

        horizontalLayout_2->addWidget(Passwordsignup);

        lineEditPasswordSignup = new QLineEdit(horizontalLayoutWidget_2);
        lineEditPasswordSignup->setObjectName("lineEditPasswordSignup");

        horizontalLayout_2->addWidget(lineEditPasswordSignup);

        horizontalLayoutWidget_3 = new QWidget(signupscreen);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(60, 220, 341, 80));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        okpushbuttonsignup = new QPushButton(horizontalLayoutWidget_3);
        okpushbuttonsignup->setObjectName("okpushbuttonsignup");

        horizontalLayout_3->addWidget(okpushbuttonsignup);

        signupMainwindowbutton = new QPushButton(horizontalLayoutWidget_3);
        signupMainwindowbutton->setObjectName("signupMainwindowbutton");

        horizontalLayout_3->addWidget(signupMainwindowbutton);

        quitsignuppushbutton = new QPushButton(horizontalLayoutWidget_3);
        quitsignuppushbutton->setObjectName("quitsignuppushbutton");

        horizontalLayout_3->addWidget(quitsignuppushbutton);


        retranslateUi(signupscreen);

        QMetaObject::connectSlotsByName(signupscreen);
    } // setupUi

    void retranslateUi(QDialog *signupscreen)
    {
        signupscreen->setWindowTitle(QCoreApplication::translate("signupscreen", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("signupscreen", "TicTacToe", nullptr));
        UserNamesignup->setText(QCoreApplication::translate("signupscreen", "User Name", nullptr));
        Passwordsignup->setText(QCoreApplication::translate("signupscreen", "Password", nullptr));
        okpushbuttonsignup->setText(QCoreApplication::translate("signupscreen", "OK", nullptr));
        signupMainwindowbutton->setText(QCoreApplication::translate("signupscreen", "Back to MainMenu", nullptr));
        quitsignuppushbutton->setText(QCoreApplication::translate("signupscreen", "Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class signupscreen: public Ui_signupscreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPSCREEN_H
