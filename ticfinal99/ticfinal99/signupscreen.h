#ifndef SIGNUPSCREEN_H
#define SIGNUPSCREEN_H
#include <QMessageBox>
#include <QMainWindow>
#include "globals.h"
#include "titlegameboard.h"
#include "signupscreen.h"
#include "screenlogin.h"
#include "screenloginai.h"
#include "Database.h"



#include <QDialog>

namespace Ui {
class signupscreen;
}

class signupscreen : public QDialog
{
    Q_OBJECT

public:
    explicit signupscreen(QWidget *parent = nullptr);
    ~signupscreen();

private slots:
    void on_okpushbuttonsignup_clicked();

    void on_quitsignuppushbutton_clicked();

    void on_signupMainwindowbutton_clicked();

private:
    Ui::signupscreen *ui;
};

#endif // SIGNUPSCREEN_H
