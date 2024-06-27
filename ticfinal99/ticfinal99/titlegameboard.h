#ifndef TITLEGAMEBOARD_H
#define TITLEGAMEBOARD_H

#include <QDialog>
#include <QPushButton>
#include <vector>
#include "Database.h"

namespace Ui {
class titlegameboard;
}

class titlegameboard : public QDialog
{
    Q_OBJECT

public:
    explicit titlegameboard(QWidget *parent = nullptr);
    ~titlegameboard();

private slots:
    void handleButtonClick();
    void on_startNewGame_clicked();

    void on_titleMainwindowbutton_clicked();

private:
    Ui::titlegameboard *ui;
    std::vector<QPushButton*> buttons;
    bool isPlayerOneTurn;
    QString symbolX;
    QString symbolO;

    void updateTurnLabel();
    void disableButtons();
    QString checkWinner();
    bool checkDraw();
    void makeAIMove();
    void makeEasyMove();
    void makeMediumMove();
    void makeHardMove();
    int minimax(int depth, bool isMaximizing);
    bool isMovesLeft();
};

#endif // TITLEGAMEBOARD_H
