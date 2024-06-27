#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "screenlogin.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startpushbutton_clicked();
    void enableStartButton(); // Slot to enable the start button
    void on_quitpushbutton_clicked();

private:
    Ui::MainWindow *ui;
    void checkConditions(); // Method to check if both conditions are met
    void updateDifficultyButtonsState();
};
#endif // MAINWINDOW_H
