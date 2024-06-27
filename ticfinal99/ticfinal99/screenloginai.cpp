#include "screenloginai.h"
#include "ui_screenloginai.h"
#include "Database.h"
#include "titlegameboard.h"
#include "mainwindow.h"
database_t screenlogindatabaseai;

screenloginai::screenloginai(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::screenloginai)
{
    ui->setupUi(this);
}

screenloginai::~screenloginai()
{
    delete ui;
}

void screenloginai::on_loginpushbuttonai_clicked()
{
    // Retrieve the text from the QLineEdit widgets
    QString usernameloginai = ui->lineEditUserNameAI->text();
    QString passwordloginai = ui->lineEditPasswordAI->text();
    screenlogindatabaseai.player.player(usernameloginai.toStdString(),passwordloginai.toStdString());

    playerNum=screenlogindatabaseai.Login();
    if(playerNum!=-1)
    {
        Player1=usernameloginai;
        hide();
        QString message = "Welcome " + usernameloginai ;
        QMessageBox::information(this, "User Info", message);
        titlegameboard databasetitleboard;
        databasetitleboard.setModal(true);
        databasetitleboard.exec();


    }
    else
    {
        QMessageBox::information(this, "User Info", QString("User Name doesn't exist"));

    }

}


void screenloginai::on_signuppushbuttonai_clicked()
{
    hide();
    signupscreen gamesignupscreen;
    gamesignupscreen.setModal(true);
    gamesignupscreen.exec();

}

void screenloginai::on_showscreenbuttonloginai_clicked()
{
    // Retrieve the text from the QLineEdit widgets

    int gameWon=0,gameLost=0,gameDraw=0;
    QString usernameloginai = ui->lineEditUserNameAI->text();
    QString passwordloginai = ui->lineEditPasswordAI->text();
    screenlogindatabaseai.player.player(usernameloginai.toStdString(),passwordloginai.toStdString());
    playerNum=screenlogindatabaseai.Login();
    if(playerNum!=-1)
    {
        screenlogindatabaseai.Get_Score(usernameloginai.toStdString(),gameWon,gameLost,gameDraw);
        Player1=usernameloginai;
        hide();
        QString message = "Welcome " + usernameloginai + "\nYou Won : " + QString::number(gameWon) + "\nYou Lost : " + QString::number(gameLost) + "\nYou Draw : " + QString::number(gameDraw);
        QMessageBox::information(this, "User Info", message);
        titlegameboard databasetitleboard;
        databasetitleboard.setModal(true);
        databasetitleboard.exec();


    }
    else
    {
        QMessageBox::information(this, "User Info", QString("Incorrect User Name or Password"));

    }






}


void screenloginai::on_screenloginAIMainwindowbutton_clicked()
{
    this->close();  // Close the login screen
    if (mainWindow) {
        mainWindow->show();  // Show the main window
    }
}

