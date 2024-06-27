#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include "globals.h"
#include "titlegameboard.h"
#include "signupscreen.h"
#include "screenlogin.h"
#include "screenloginai.h"
#include "Database.h"

database_t mainwindowdatabase;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->startpushbutton->setEnabled(false);

    // Connect the radio buttons' toggled signal to the enableStartButton slot
    connect(ui->radiox, &QRadioButton::toggled, this, &MainWindow::enableStartButton);
    connect(ui->radioO, &QRadioButton::toggled, this, &MainWindow::enableStartButton);
    connect(ui->radioAI, &QRadioButton::toggled, this, &MainWindow::enableStartButton);
    connect(ui->radio1v1, &QRadioButton::toggled, this, &MainWindow::enableStartButton);
    connect(ui->radioEasy, &QRadioButton::toggled, this, &MainWindow::enableStartButton);
    connect(ui->radioMedium, &QRadioButton::toggled, this, &MainWindow::enableStartButton);
    connect(ui->radioHard, &QRadioButton::toggled, this, &MainWindow::enableStartButton);
    connect(ui->radioAI, &QRadioButton::toggled, this, &MainWindow::updateDifficultyButtonsState);
    connect(ui->radio1v1, &QRadioButton::toggled, this, &MainWindow::updateDifficultyButtonsState);

    // Initialize the difficulty buttons state
    updateDifficultyButtonsState();

    mainwindowdatabase.Initialize_Database();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startpushbutton_clicked()
{
    hide();

    if (ui->radiox->isChecked())
    {
        currentSymbol = 'X';
        PlayerSymbol1 = 'X';
        PlayerSymbol2='O';

    }
    else if (ui->radioO->isChecked())
    {
        currentSymbol = 'O';
        PlayerSymbol1 = 'O';
        PlayerSymbol2='X';
    }
    else
    {
        QMessageBox::warning(this, "Warning", "Please select a symbol.");
        return;
    }

    // Display the chosen settings
    QString mode = ui->radioAI->isChecked() ? "AI" : "1v1";
    QString difficulty;
    if (ui->radioEasy->isChecked())
        difficulty = "Easy";
    else if (ui->radioMedium->isChecked())
        difficulty = "Medium";
    else if (ui->radioHard->isChecked())
        difficulty = "Hard";

    QMessageBox::information(this, "Game Settings", QString("Symbol: %1\nMode: %2\nDifficulty: %3")
                                                        .arg(currentSymbol)
                                                        .arg(mode)
                                                        .arg(difficulty));

    if (isAIMode == false)
    {
        screenlogin gamelogin;
        gamelogin.setModal(true);
        gamelogin.exec();
    }
    else
    {
        if(PlayerSymbol1=='X')
        {
            AISymbol='O';

        }
        else
        {
            AISymbol='X';

        }
        screenloginai gameloginai;
        gameloginai.setModal(true);
        gameloginai.exec();
    }
}

void MainWindow::on_quitpushbutton_clicked()
{
    close();
}

void MainWindow::enableStartButton()
{
    bool symbolSelected = ui->radiox->isChecked() || ui->radioO->isChecked();
    bool modeSelected = ui->radioAI->isChecked() || ui->radio1v1->isChecked();
    bool difficultySelected = ui->radioEasy->isChecked() || ui->radioMedium->isChecked() || ui->radioHard->isChecked();
    if(ui->radio1v1->isChecked())
    {
        ui->startpushbutton->setEnabled(symbolSelected && modeSelected);
    }
    else
    {
        ui->startpushbutton->setEnabled(symbolSelected && modeSelected&&difficultySelected);

    }



    // Update global variables based on the radio button selections
    if (ui->radioEasy->isChecked())
    {
        difficultyLevel = 1;
    }
    else if (ui->radioMedium->isChecked())
    {
        difficultyLevel = 2;
    }
    else if (ui->radioHard->isChecked())
    {
        difficultyLevel = 3;
    }

    if (ui->radioAI->isChecked())
    {
        isAIMode = true;
    }
    else
    {
        isAIMode = false;
    }
}

void MainWindow::updateDifficultyButtonsState()
{
    bool isAISelected = ui->radioAI->isChecked();
    ui->radioEasy->setEnabled(isAISelected);
    ui->radioMedium->setEnabled(isAISelected);
    ui->radioHard->setEnabled(isAISelected);

    if (!isAISelected)
    {
        // If AI mode is not selected, deselect any difficulty radio button
        ui->radioEasy->setAutoExclusive(false);
        ui->radioMedium->setAutoExclusive(false);
        ui->radioHard->setAutoExclusive(false);

        ui->radioEasy->setChecked(false);
        ui->radioMedium->setChecked(false);
        ui->radioHard->setChecked(false);

        ui->radioEasy->setAutoExclusive(true);
        ui->radioMedium->setAutoExclusive(true);
        ui->radioHard->setAutoExclusive(true);
    }
}
