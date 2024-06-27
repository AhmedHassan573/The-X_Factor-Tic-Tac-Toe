#include "gameLogic.h"
#include <cstdlib>
#include <algorithm>
#include <iostream>

titlegameboard::titlegameboard()
    : isPlayerOneTurn(true)
    , symbolX("X")
    , symbolO("O")
    , isAIMode(false)
    , difficultyLevel(1)
{
    reset();
}

titlegameboard::~titlegameboard() {}

void titlegameboard::reset() {
    board = std::vector<std::vector<int>>(3, std::vector<int>(3, 0));
    isPlayerOneTurn = true;
    updateTurnLabel();
}

bool titlegameboard::makeMove(int player, int x, int y) {
    if (x < 0 || x >= 3 || y < 0 || y >= 3 || board[x][y] != 0) {
        return false;
    }
    board[x][y] = player;
    return true;
}

std::string titlegameboard::checkWinner() const {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0] == 1 ? symbolX : symbolO;
        }
        if (board[0][i] != 0 && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i] == 1 ? symbolX : symbolO;
        }
    }
    if (board[0][0] != 0 && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0] == 1 ? symbolX : symbolO;
    }
    if (board[0][2] != 0 && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2] == 1 ? symbolX : symbolO;
    }
    return "";
}

bool titlegameboard::checkDraw() const {
    for (const auto& row : board) {
        for (int cell : row) {
            if (cell == 0) {
                return false;
            }
        }
    }
    return checkWinner().empty();
}

void titlegameboard::disableButtons() {
    // This method would disable buttons in the GUI. Since we're not using Qt, this is a no-op.
}

void titlegameboard::on_startNewGame() {
    reset();
    std::cout << "New game started. Player one's turn.\n";
}

void titlegameboard::makeAIMove() {
    switch (difficultyLevel) {
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

    std::string winner = checkWinner();
    if (!winner.empty()) {
        std::cout << "Winner: " << winner << "\n";
        disableButtons();
    } else if (checkDraw()) {
        std::cout << "Draw\n";
        disableButtons();
    } else {
        isPlayerOneTurn = !isPlayerOneTurn;
        updateTurnLabel();
    }
}

void titlegameboard::makeEasyMove() {
    std::vector<std::pair<int, int>> emptyCells;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == 0) {
                emptyCells.emplace_back(i, j);
            }
        }
    }
    if (!emptyCells.empty()) {
        auto [x, y] = emptyCells[rand() % emptyCells.size()];
        board[x][y] = 2;
    }
}

void titlegameboard::makeMediumMove() {
    int playerSymbol = 1;
    int aiSymbol = 2;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == 0) {
                board[i][j] = aiSymbol;
                if (checkWinner() == symbolO) {
                    return;
                }
                board[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == 0) {
                board[i][j] = playerSymbol;
                if (checkWinner() == symbolX) {
                    board[i][j] = aiSymbol;
                    return;
                }
                board[i][j] = 0;
            }
        }
    }

    if (board[1][1] == 0) {
        board[1][1] = aiSymbol;
        return;
    }

    std::vector<std::pair<int, int>> corners = {{0, 0}, {0, 2}, {2, 0}, {2, 2}};
    for (auto [x, y] : corners) {
        if (board[x][y] == 0) {
            board[x][y] = aiSymbol;
            return;
        }
    }

    makeEasyMove();
}

void titlegameboard::makeHardMove() {
    int bestVal = -1000;
    std::pair<int, int> bestMove = {-1, -1};

    int aiSymbol = 2;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == 0) {
                board[i][j] = aiSymbol;
                int moveVal = minimax(0, false);
                board[i][j] = 0;

                if (moveVal > bestVal) {
                    bestMove = {i, j};
                    bestVal = moveVal;
                }
            }
        }
    }

    if (bestMove.first != -1) {
        board[bestMove.first][bestMove.second] = aiSymbol;
    }
}

int titlegameboard::minimax(int depth, bool isMaximizing) {
    std::string winner = checkWinner();
    int aiSymbol = 2;
    int playerSymbol = 1;

    if (winner == symbolO) return 10 - depth;
    if (winner == symbolX) return depth - 10;
    if (checkDraw()) return 0;

    if (isMaximizing) {
        int best = -1000;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 0) {
                    board[i][j] = aiSymbol;
                    best = std::max(best, minimax(depth + 1, false));
                    board[i][j] = 0;
                }
            }
        }
        return best;
    } else {
        int best = 1000;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 0) {
                    board[i][j] = playerSymbol;
                    best = std::min(best, minimax(depth + 1, true));
                    board[i][j] = 0;
                }
            }
        }
        return best;
    }
}

void titlegameboard::updateTurnLabel() {
    std::string currentPlayer = isPlayerOneTurn ? symbolX : symbolO;
    std::cout << "Turn: " << currentPlayer << "\n";
}

// Helper function to set the board state
void setBoard(titlegameboard &board, const std::vector<std::vector<int>> &state) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board.makeMove(state[i][j], i, j);
        }
    }
}
