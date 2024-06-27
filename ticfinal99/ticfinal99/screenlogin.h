#ifndef SCREENLOGIN_H
#define SCREENLOGIN_H

#include <QDialog>
#include <QMessageBox>
#include "mainwindow.h"
#include "titlegameboard.h"
#include "globals.h"
#include "Database.h"
class MainWindow; // Forward declaration



namespace Ui {
class screenlogin;
}

class screenlogin : public QDialog
{
    Q_OBJECT

public:
    explicit screenlogin(QWidget *parent = nullptr);
    ~screenlogin();

private slots:
    void on_loginpushButton_clicked();
    void on_signuppushButton_clicked();
    void on_quitpushButton_clicked();


    void on_showscreenbuttonlogin_clicked();

    void on_screenloginMainwindowbutton_clicked();

private:
    Ui::screenlogin *ui;
    MainWindow *mainWindow;
};

#endif // SCREENLOGIN_H
