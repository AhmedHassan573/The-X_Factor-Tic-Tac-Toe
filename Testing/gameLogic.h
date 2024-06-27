#ifndef TITLEGAMEBOARD_H
#define TITLEGAMEBOARD_H

#include <vector>
#include <string>

class titlegameboard {
public:
    titlegameboard();
    ~titlegameboard();

    void reset();
    bool makeMove(int player, int x, int y);
    std::string checkWinner() const;
    bool checkDraw() const;
    void disableButtons();
    void on_startNewGame();
    void makeAIMove();
    void makeEasyMove();
    void makeMediumMove();
    void makeHardMove();
    int minimax(int depth, bool isMaximizing);
    void setBoard(titlegameboard &board, const std::vector<std::vector<int>> &state);

    std::vector<std::vector<int>> board;
    bool isPlayerOneTurn;
    char currentSymbol;
    std::string symbolX;
    std::string symbolO;
    bool isAIMode;
    int difficultyLevel;

private:
    void updateTurnLabel();
};

#endif // TITLEGAMEBOARD_H
