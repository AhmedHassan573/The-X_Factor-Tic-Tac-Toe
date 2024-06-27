#include "titlegameboard.h"
#include "ui_titlegameboard.h"
#include "globals.h"
#include <cstdlib> // For random number generation
#include "mainwindow.h"
#include <QMessageBox>
database_t titlegameboarddatabase;

titlegameboard::titlegameboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::titlegameboard)
    , isPlayerOneTurn(true)
    , symbolX("X")
    , symbolO("O")
{
    ui->setupUi(this);
    buttons = {ui->button1, ui->button2, ui->button3, ui->button4, ui->button5, ui->button6, ui->button7, ui->button8, ui->button9};
    for (auto button : buttons) {
        connect(button, &QPushButton::clicked, this, &titlegameboard::handleButtonClick);
    }
    connect(ui->startNewGame, &QPushButton::clicked, this, &titlegameboard::on_startNewGame_clicked);
    updateTurnLabel();
}

titlegameboard::~titlegameboard()
{
    delete ui;
}

void titlegameboard::handleButtonClick()
{
  int gameWon1=0,gameWon2=0,gameDraw1=0,gameDraw2=0,gameLost1=0,gameLost2=0;

    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton && clickedButton->text().isEmpty())  // Only change if the button is not already marked
    {
        if (isPlayerOneTurn)
        {
            clickedButton->setText(currentSymbol == 'X' ? symbolX : symbolO);
            clickedButton->setStyleSheet("font-size: 24px; color: red;");
        }
        else
        {
            clickedButton->setText(currentSymbol == 'X' ? symbolO : symbolX);
            clickedButton->setStyleSheet("font-size: 24px; color: blue;");
        }

        QString winner = checkWinner();

        if (winner == symbolX || winner == symbolO) {
            if(PlayerSymbol1 == winner)
            {
                titlegameboarddatabase.Get_Score(Player1.toStdString(),gameWon1,gameLost1,gameDraw1);
                titlegameboarddatabase.Get_Score(Player2.toStdString(),gameWon2,gameLost2,gameDraw2);
                gameWon1++;
                gameLost2++;
                titlegameboarddatabase.Update_Score_Table(Player1.toStdString(),gameWon1,gameLost1,gameDraw1);
                titlegameboarddatabase.Update_Score_Table(Player2.toStdString(),gameWon2,gameLost2,gameDraw2);
                ui->turnLabel->setText("Winner: " + Player1);
            }
            else
            {
                titlegameboarddatabase.Get_Score(Player1.toStdString(),gameWon1,gameLost1,gameDraw1);
                titlegameboarddatabase.Get_Score(Player2.toStdString(),gameWon2,gameLost2,gameDraw2);
                gameWon2++;
                gameLost1++;
                titlegameboarddatabase.Update_Score_Table(Player1.toStdString(),gameWon1,gameLost1,gameDraw1);
                titlegameboarddatabase.Update_Score_Table(Player2.toStdString(),gameWon2,gameLost2,gameDraw2);
                ui->turnLabel->setText("Winner: " + Player2);
            }

            disableButtons();
        }
        else if (checkDraw()) {
            titlegameboarddatabase.Get_Score(Player1.toStdString(),gameWon1,gameLost1,gameDraw1);
            titlegameboarddatabase.Get_Score(Player2.toStdString(),gameWon2,gameLost2,gameDraw2);
            gameDraw2++;
            gameDraw1++;
            titlegameboarddatabase.Update_Score_Table(Player1.toStdString(),gameWon1,gameLost1,gameDraw1);
            titlegameboarddatabase.Update_Score_Table(Player2.toStdString(),gameWon2,gameLost2,gameDraw2);
            ui->turnLabel->setText("Draw");
            disableButtons();
        }
        else {
            isPlayerOneTurn = !isPlayerOneTurn;  // Toggle the turn
            updateTurnLabel();

            // If in AI mode and it's now AI's turn, make AI move
            if (isAIMode && !isPlayerOneTurn) {
                makeAIMove();
            }
        }
    }
}

void titlegameboard::updateTurnLabel()
{
    if (isPlayerOneTurn)
    {
        ui->turnLabel->setText("Turn: " + Player1);
        ui->turnLabel->setStyleSheet("font-size: 20px; color: red;");
    }
    else
    {
        ui->turnLabel->setText("Turn: " + Player2);
        ui->turnLabel->setStyleSheet("font-size: 20px; color: blue;");
    }
}

void titlegameboard::disableButtons()
{
    for (auto button : buttons) {
        button->setEnabled(false); // Disable each button
    }
}

QString titlegameboard::checkWinner()
{
    QString winner = "";
    // Check rows, columns, and diagonals for a winner
    for (int i = 0; i < 3; ++i) {
        // Check rows
        if (!buttons[i * 3]->text().isEmpty() &&
            buttons[i * 3]->text() == buttons[i * 3 + 1]->text() &&
            buttons[i * 3]->text() == buttons[i * 3 + 2]->text()) {
            return (winner = buttons[i * 3]->text()); // Return the winning symbol
        }

        // Check columns
        if (!buttons[i]->text().isEmpty() &&
            buttons[i]->text() == buttons[i + 3]->text() &&
            buttons[i]->text() == buttons[i + 6]->text()) {
            return (winner = buttons[i]->text()); // Return the winning symbol
        }
    }

    // Check diagonals
    if (!buttons[0]->text().isEmpty() &&
        buttons[0]->text() == buttons[4]->text() &&
        buttons[0]->text() == buttons[8]->text()) {
        return (winner = buttons[0]->text()); // Return the winning symbol
    }

    if (!buttons[2]->text().isEmpty() &&
        buttons[2]->text() == buttons[4]->text() &&
        buttons[2]->text() == buttons[6]->text()) {
        return (winner = buttons[2]->text()); // Return the winning symbol
    }

    return winner;
}

bool titlegameboard::checkDraw()
{
    for (auto button : buttons) {
        if (button->text().isEmpty()) {
            return false;
        }
    }
    return true;
}

void titlegameboard::on_startNewGame_clicked()
{
    // Reset game state
    for (auto button : buttons) {
        button->setText(""); // Clear text
        button->setEnabled(true); // Enable buttons
    }

    isPlayerOneTurn = true; // Start with player one's turn
    updateTurnLabel(); // Update the turn label to reflect the initial player's turn
}

void titlegameboard::makeAIMove()
{
    int gameWon=0,gameLost=0,gameDraw=0;
    switch (difficultyLevel)
    {
    case 1:
        makeEasyMove();
        break;
    case 2:
        makeMediumMove();
        break;
    case 3:
        makeHardMove();
        break;
    }

    QString winner = checkWinner();

    if (winner == symbolX || winner == symbolO) {
        if(AISymbol==winner)
        {
            ui->turnLabel->setText("Winner:Computer" );
            titlegameboarddatabase.Get_Score(Player1.toStdString(),gameWon,gameLost,gameDraw);
            gameLost++;
            titlegameboarddatabase.Update_Score_Table(Player1.toStdString(),gameWon,gameLost,gameDraw);

        }
        else
        {
            ui->turnLabel->setText("Winner: " + Player1 );
            titlegameboarddatabase.Get_Score(Player1.toStdString(),gameWon,gameLost,gameDraw);
            gameWon++;
            titlegameboarddatabase.Update_Score_Table(Player1.toStdString(),gameWon,gameLost,gameDraw);
        }
        disableButtons();
    }
    else if (checkDraw()) {
        ui->turnLabel->setText("Draw");
        titlegameboarddatabase.Get_Score(Player1.toStdString(),gameWon,gameLost,gameDraw);
        gameDraw++;
        titlegameboarddatabase.Update_Score_Table(Player1.toStdString(),gameWon,gameLost,gameDraw);
        disableButtons();
    }
    else {
        isPlayerOneTurn = !isPlayerOneTurn;  // Toggle the turn
        updateTurnLabel();
    }
}

void titlegameboard::makeEasyMove()
{
    // Easy AI: Random move
    std::vector<QPushButton*> emptyButtons;
    for (auto button : buttons) {
        if (button->text().isEmpty()) {
            emptyButtons.push_back(button);
        }
    }
    if (!emptyButtons.empty()) {
        int randomIndex = rand() % emptyButtons.size();
        QPushButton* randomButton = emptyButtons[randomIndex];
        randomButton->setText(currentSymbol == 'X' ? symbolO : symbolX);
        randomButton->setStyleSheet("font-size: 24px; color: blue;");
    }
}

void titlegameboard::makeMediumMove()
{
    QString aiSymbol = currentSymbol == 'X' ? symbolO : symbolX;
    QString playerSymbol = currentSymbol == 'X' ? symbolX : symbolO;

    // Check if AI can win in the next move
    for (auto button : buttons) {
        if (button->text().isEmpty()) {
            button->setText(aiSymbol);
            if (checkWinner() == aiSymbol) {
                button->setStyleSheet("font-size: 24px; color: blue;");
                return;
            }
            button->setText("");
        }
    }

    // Block the opponent's winning move
    for (auto button : buttons) {
        if (button->text().isEmpty()) {
            button->setText(playerSymbol);
            if (checkWinner() == playerSymbol) {
                button->setText(aiSymbol);
                button->setStyleSheet("font-size: 24px; color: blue;");
                return;
            }
            button->setText("");
        }
    }

    // Pick center if available
    if (buttons[4]->text().isEmpty()) {
        buttons[4]->setText(aiSymbol);
        buttons[4]->setStyleSheet("font-size: 24px; color: blue;");
        return;
    }

    // Pick a corner if available
    std::vector<int> corners = {0, 2, 6, 8};
    for (int i : corners) {
        if (buttons[i]->text().isEmpty()) {
            buttons[i]->setText(aiSymbol);
            buttons[i]->setStyleSheet("font-size: 24px; color: blue;");
            return;
        }
    }

    // Otherwise, make a random move
    makeEasyMove();
}

void titlegameboard::makeHardMove()
{
    int bestVal = -1000;
    int bestMove = -1;

    QString aiSymbol = currentSymbol == 'X' ? symbolO : symbolX;

    for (int i = 0; i < buttons.size(); ++i) {
        if (buttons[i]->text().isEmpty()) {
            buttons[i]->setText(aiSymbol);
            int moveVal = minimax(0, false);
            buttons[i]->setText("");

            if (moveVal > bestVal) {
                bestMove = i;
                bestVal = moveVal;
            }
        }
    }

    if (bestMove != -1) {
        buttons[bestMove]->setText(aiSymbol);
        buttons[bestMove]->setStyleSheet("font-size: 24px; color: blue;");
    }
}

int titlegameboard::minimax(int depth, bool isMaximizing)
{
    QString winner = checkWinner();
    QString aiSymbol = currentSymbol == 'X' ? symbolO : symbolX;
    QString playerSymbol = currentSymbol == 'X' ? symbolX : symbolO;

    if (winner == aiSymbol) {
        return 10 - depth;
    }
    else if (winner == playerSymbol) {
        return depth - 10;
    }
    else if (checkDraw()) {
        return 0;
    }

    if (isMaximizing) {
        int best = -1000;

        for (int i = 0; i < buttons.size(); ++i) {
            if (buttons[i]->text().isEmpty()) {
                buttons[i]->setText(aiSymbol);
                best = std::max(best, minimax(depth + 1, !isMaximizing));
                buttons[i]->setText("");
            }
        }
        return best;
    }
    else {
        int best = 1000;

        for (int i = 0; i < buttons.size(); ++i) {
            if (buttons[i]->text().isEmpty()) {
                buttons[i]->setText(playerSymbol);
                best = std::min(best, minimax(depth + 1, !isMaximizing));
                buttons[i]->setText("");
            }
        }
        return best;
    }
}

void titlegameboard::on_titleMainwindowbutton_clicked()
{
    MainWindow* titlemainmenu = new MainWindow(this); // Create a new instance of MainWindow
    titlemainmenu->show(); // Show the main window
    this->close(); // Optionally close the current dialog if you want to switch to main window
}


