#include "screenlogin.h"
#include "ui_screenlogin.h"
#include <QMessageBox>
#include "globals.h"
#include "titlegameboard.h"
#include "signupscreen.h"
#include "screenlogin.h"
#include "screenloginai.h"
#include "mainwindow.h"
class MainWindow;

database_t screenlogindatabase;

screenlogin::screenlogin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::screenlogin)
{
    ui->setupUi(this);
}

screenlogin::~screenlogin()
{
    delete ui;
}

void screenlogin::on_loginpushButton_clicked()
{
    // Retrieve the text from the QLineEdit widgets
    QString usernamescreenlogin1 = ui->LineEditUserName1->text();
    QString passwordscreenlogin1 = ui->LineEditPassword1->text();
    QString usernamescreenlogin2 = ui->LineEditUserName2->text();
    QString passwordscreenlogin2 = ui->LineEditPassword2->text();

    screenlogindatabase.player.player(usernamescreenlogin1.toStdString(),passwordscreenlogin1.toStdString());
    playerNum=screenlogindatabase.Login();

    if(playerNum!=-1)
    {
        screenlogindatabase.player.player(usernamescreenlogin2.toStdString(),passwordscreenlogin2.toStdString());
        playerNum=screenlogindatabase.Login();
        Player1=usernamescreenlogin1;
        if(playerNum!=-1)
        {
            Player2=usernamescreenlogin2;
            hide();
            QMessageBox::information(this, "User Info", QString("Welcome : "+usernamescreenlogin1+"\n"+"Welcome : "+usernamescreenlogin2));
            titlegameboard databasetitleboard;
            databasetitleboard.setModal(true);
            databasetitleboard.exec();

        }
        else
        {
            QMessageBox::information(this, "User Info", QString("Incorrect username or password for Player2"));

        }




    }
    else
    {
        QMessageBox::information(this, "User Info", QString("Incorrect username or password for Player1"));

    }



}


void screenlogin::on_signuppushButton_clicked()
{
    hide();
    signupscreen gamesignupscreen;
    gamesignupscreen.setModal(true);
    gamesignupscreen.exec();

}


void screenlogin::on_quitpushButton_clicked()
{
    close();

}


\


void screenlogin::on_showscreenbuttonlogin_clicked()
{
    // Retrieve the text from the QLineEdit widgets
    QString usernamescreenlogin1 = ui->LineEditUserName1->text();
    QString passwordscreenlogin1 = ui->LineEditPassword1->text();
    QString usernamescreenlogin2 = ui->LineEditUserName2->text();
    QString passwordscreenlogin2 = ui->LineEditPassword2->text();



    screenlogindatabase.player.player(usernamescreenlogin1.toStdString(),passwordscreenlogin1.toStdString());
    playerNum=screenlogindatabase.Login();

    if(playerNum!=-1)
    {
        screenlogindatabase.player.player(usernamescreenlogin2.toStdString(),passwordscreenlogin2.toStdString());
        playerNum=screenlogindatabase.Login();
        Player1=usernamescreenlogin1;
        if(playerNum!=-1)
        {
            int gameWon1=0,gameWon2=0,gameDraw1=0,gameDraw2=0,gameLost1=0,gameLost2=0;
            screenlogindatabase.Get_Score(usernamescreenlogin1.toStdString(),gameWon1,gameLost1,gameDraw1);
            screenlogindatabase.Get_Score(usernamescreenlogin2.toStdString(),gameWon2,gameLost2,gameDraw2);
            QString wonStr1 = QString::number(gameWon1);
            QString lostStr1 = QString::number(gameLost1);
            QString drawStr1 = QString::number(gameDraw1);
            QString wonStr2 = QString::number(gameWon2);
            QString lostStr2 = QString::number(gameLost2);
            QString drawStr2 = QString::number(gameDraw2);
            Player2=usernamescreenlogin2;
            hide();
            QMessageBox::information(this, "User Info", "Welcome : "+usernamescreenlogin1+"\n"+wonStr1+" "+lostStr1+" "+drawStr1 +"\nWelcome : "+usernamescreenlogin2+"\n"+wonStr2+" "+lostStr2+" "+drawStr2);
            titlegameboard databasetitleboard;
            databasetitleboard.setModal(true);
            databasetitleboard.exec();

        }
        else
        {
            QMessageBox::information(this, "User Info", QString("Incorrect username or password for Player2"));

        }




    }
    else
    {
        QMessageBox::information(this, "User Info", QString("Incorrect username or password for Player1"));

    }


}


void screenlogin::on_screenloginMainwindowbutton_clicked()
{
    this->close();  // Close the login screen
    if (mainWindow) {
        mainWindow->show();  // Show the main window
    }

}

