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
{
    ui->setupUi(this);
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
    databaseSignup.player.player(usernamesignup.toStdString(),passwordsignup.toStdString());

    // Create the message to be displayed
    notrepeated=databaseSignup.Sign_Up();
    if(notrepeated)
    {
        hide();
        databaseSignup.Add_To_Score_Table(usernamesignup.toStdString(),0,0,0);
        QString message = "Username: " + usernamesignup + "\nPassword: " + passwordsignup;
        QMessageBox::information(this, "User Info", message);
        if(isAIMode==true)
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
        QMessageBox::information(this, "User Info", QString("User Name already exist"));

    }


}


void signupscreen::on_quitsignuppushbutton_clicked()
{
    close();
}


void signupscreen::on_signupMainwindowbutton_clicked()
{
    MainWindow* titlemainmenu1 = new MainWindow(this); // Create a new instance of MainWindow
    titlemainmenu1->show(); // Show the main window
    this->close(); // Optionally close the current dialog if you want to switch to main window
}

