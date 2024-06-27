#include "signupscreen.h"
#include "ui_signupscreen.h"
#include "titlegameboard.h"
#include "screenlogin.h"
#include "screenloginai.h"
#include "globals.h"
#include "mainwindow.h"

database_t databaseSignup;

signupscreen::signupscreen(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::signupscreen)
    , mainWindow(mainWindow)
{
    ui->setupUi(this);
    ui->lineEditPasswordSignup->setEchoMode(QLineEdit::Password);  // Set password to appear as dots
}

signupscreen::~signupscreen()
{
    delete ui;
}

void signupscreen::on_okpushbuttonsignup_clicked()
{
    // Retrieve the text from the QLineEdit widgets
    QString usernamesignup = ui->lineEditUserNameSignup->text();
    QString passwordsignup = ui->lineEditPasswordSignup->text();
    databaseSignup.player.player(usernamesignup.toStdString(), passwordsignup.toStdString());

    // Create the message to be displayed
    notrepeated = databaseSignup.Sign_Up();
    if(notrepeated)
    {
        hide();
        databaseSignup.Add_To_Score_Table(usernamesignup.toStdString(), 0, 0, 0);
        QString message = "Username: " + usernamesignup + "\nPassword: " + passwordsignup;
        QMessageBox::information(this, "User Info", message);
        if(isAIMode)
        {
            screenloginai gamescreenloginaisignup;
            gamescreenloginaisignup.setModal(true);
            gamescreenloginaisignup.exec();
        }
        else
        {
            screenlogin gamescreenloginsignup;
            gamescreenloginsignup.setModal(true);
            gamescreenloginsignup.exec();
        }
    }
    else
    {
        QMessageBox::information(this, "User Info", QString("User Name already exists"));
    }
}

void signupscreen::on_quitsignuppushbutton_clicked()
{
    close();
}

void signupscreen::on_signupMainwindowbutton_clicked()
{
    this->close();  // Close the sign-up screen
    if (mainWindow) {
        mainWindow->show();  // Show the main window
    }
}
