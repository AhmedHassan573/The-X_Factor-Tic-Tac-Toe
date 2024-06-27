#ifndef SCREENLOGINAI_H
#define SCREENLOGINAI_H
#include <QMessageBox>
#include <QMainWindow>
#include "globals.h"
#include "titlegameboard.h"
#include "signupscreen.h"
#include "screenlogin.h"
#include "screenloginai.h"


#include <QDialog>
class MainWindow; // Forward declaration

namespace Ui {
class screenloginai;
}

class screenloginai : public QDialog
{
    Q_OBJECT

public:
    explicit screenloginai(QWidget *parent = nullptr);
    ~screenloginai();

private slots:
    void on_loginpushbuttonai_clicked();

    void on_signuppushbuttonai_clicked();


    void on_showscreenbuttonloginai_clicked();

    void on_screenloginAIMainwindowbutton_clicked();

private:
    Ui::screenloginai *ui;
    MainWindow *mainWindow;
};

#endif // SCREENLOGINAI_H
