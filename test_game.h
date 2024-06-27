#ifndef TEST_GAME_H
#define TEST_GAME_H

#include <gtest/gtest.h>
#include "titlegameboard.h"

class TestTitleGameBoard : public ::testing::Test {
protected:
    void SetUp() override {
        game.reset();
    }

    titlegameboard game;
};

TEST_F(TestTitleGameBoard, ResetGame) {
    game.reset();
    for (const auto& row : game.board) {
        for (int cell : row) {
            ASSERT_EQ(cell, 0);
        }
    }
    ASSERT_TRUE(game.isPlayerOneTurn);
}

TEST_F(TestTitleGameBoard, MakeMoveValid) {
    ASSERT_TRUE(game.makeMove(1, 0, 0));
    ASSERT_EQ(game.board[0][0], 1);
    ASSERT_FALSE(game.makeMove(1, 0, 0));
}

TEST_F(TestTitleGameBoard, MakeMoveInvalid) {
    ASSERT_FALSE(game.makeMove(1, 3, 0)); // Out of bounds
    ASSERT_FALSE(game.makeMove(1, 0, 3)); // Out of bounds
    ASSERT_FALSE(game.makeMove(1, -1, 0)); // Out of bounds
    ASSERT_FALSE(game.makeMove(1, 0, -1)); // Out of bounds
}

//check Winner tests
TEST_F(TestTitleGameBoard, CheckWinnerRow) {
    game.makeMove(1, 0, 0);
    game.makeMove(1, 0, 1);
    game.makeMove(1, 0, 2);
    ASSERT_EQ(game.checkWinner(), game.symbolX);
}

TEST_F(TestTitleGameBoard, CheckWinnerColumn) {
    game.makeMove(1, 0, 0);
    game.makeMove(1, 1, 0);
    game.makeMove(1, 2, 0);
    ASSERT_EQ(game.checkWinner(), game.symbolX);
}

TEST_F(TestTitleGameBoard, CheckWinnerDiagonal) {
    game.makeMove(1, 0, 0);
    game.makeMove(1, 1, 1);
    game.makeMove(1, 2, 2);
    ASSERT_EQ(game.checkWinner(), game.symbolX);

    game.reset();
    game.makeMove(1, 0, 2);
    game.makeMove(1, 1, 1);
    game.makeMove(1, 2, 0);
    ASSERT_EQ(game.checkWinner(), game.symbolX);
}

TEST_F(TestTitleGameBoard, CheckDraw) {
    game.makeMove(1, 0, 0);
    game.makeMove(2, 0, 1);
    game.makeMove(1, 0, 2);
    game.makeMove(1, 1, 0);
    game.makeMove(1, 1, 1);
    game.makeMove(2, 1, 2);
    game.makeMove(2, 2, 0);
    game.makeMove(1, 2, 1);
    game.makeMove(2, 2, 2);
    ASSERT_TRUE(game.checkDraw());
    ASSERT_EQ(game.checkWinner(), "");
}


TEST_F(TestTitleGameBoard, MakeAIMove) {
    game.isAIMode = true;
    game.difficultyLevel = 1;
    game.makeAIMove();
    bool moveMade = false;
    for (const auto& row : game.board) {
        for (int cell : row) {
            if (cell == 2) {
                moveMade = true;
                break;
            }
        }
        if (moveMade) break;
    }
    ASSERT_TRUE(moveMade);
}

TEST_F(TestTitleGameBoard, MakeEasyMove) {
    game.makeEasyMove();
    bool moveMade = false;
    for (const auto& row : game.board) {
        for (int cell : row) {
            if (cell == 2) {
                moveMade = true;
                break;
            }
        }
        if (moveMade) break;
    }
    ASSERT_TRUE(moveMade);
}

TEST_F(TestTitleGameBoard, MakeMediumMove) {
    game.makeMove(1, 0, 0);
    game.makeMove(1, 0, 1);
    game.makeMediumMove();
    ASSERT_EQ(game.board[0][2], 2); // AI blocks the winning move
}

TEST_F(TestTitleGameBoard, MakeHardMove) {
    game.makeMove(1, 0, 0);
    game.makeMove(1, 0, 1);
    game.makeMove(2, 1, 1);
    game.makeHardMove();
    ASSERT_EQ(game.board[0][2], 2); // AI blocks the winning move
}


//Tests for Medium moves
TEST_F(TestTitleGameBoard, MakeMediumMove_WinningMove) {
    // Set up a winning scenario for Player 1
    game.makeMove(1, 0, 0);
    game.makeMove(1, 0, 1);
    game.makeMediumMove(); // AI should make a winning move
    ASSERT_EQ(game.board[0][2], 2); // AI should complete the winning line
}

TEST_F(TestTitleGameBoard, MakeMediumMove_BlockingMove) {
    // Set up a scenario where Player 1 is about to win
    game.makeMove(1, 0, 0);
    game.makeMove(1, 2, 2);
    game.makeMediumMove(); // AI should block Player 1's winning move
    ASSERT_EQ(game.board[1][1], 2); // AI should block in the second row
}

TEST_F(TestTitleGameBoard, MakeMediumMove_ChooseCenter) {
    // Set up a scenario where the center is available
    game.makeMove(1, 0, 0);
    game.makeMove(1, 2, 2);
    game.makeMediumMove(); // AI should choose the center
    ASSERT_EQ(game.board[1][1], 2); // AI should choose the center cell
}

TEST_F(TestTitleGameBoard, MakeMediumMove_PickCorner) {
    // Set up a scenario where corners are available
    game.makeMove(1, 0, 0);
    game.makeMove(2, 2, 2);
    game.makeMediumMove(); // AI should choose a corner
    ASSERT_TRUE(game.board[0][2] == 2 || game.board[2][0] == 2 || game.board[2][2] == 2);
}

TEST_F(TestTitleGameBoard, MakeMediumMove_RandomMove) {
    // Set up a scenario where the AI has multiple possible moves
    game.makeMove(1, 0, 0);
    game.makeMove(2, 1, 1);
    game.makeMediumMove(); // AI should make a random move
    bool moveMade = false;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (game.board[i][j] == 2) {
                moveMade = true;
                break;
            }
        }
        if (moveMade) break;
    }
    ASSERT_TRUE(moveMade);
}



//Test Hard Mode
TEST_F(TestTitleGameBoard, MakeHardMove_BlockingMove) {
    // Set up a scenario where Player 2 is about to win
    game.makeMove(1, 0, 0);
    game.makeMove(1, 1, 1);
    game.makeHardMove(); // AI should block Player 2's winning move
    ASSERT_EQ(game.board[2][2], 2); // AI should block in the second row
}

TEST_F(TestTitleGameBoard, MakeHardMove_WinningMove) {
    // Set up a scenario where the AI is about to win
    game.makeMove(2, 0, 0);
    game.makeMove(2, 0, 1);
    game.makeMove(1, 1, 1);
    game.makeHardMove(); // AI should complete the winning line
    ASSERT_EQ(game.board[0][2], 2); // AI should complete the winning line
}



TEST_F(TestTitleGameBoard, MakeHardMove_PickCorner) {
    // Set up a scenario where corners are available
    game.makeMove(1, 0, 0);
    game.makeMove(2, 1, 1);
    game.makeMove(1, 0, 1);
    game.makeHardMove(); // AI should choose a corner and also prevent his loss
    ASSERT_TRUE(game.board[0][2] == 2 || game.board[2][0] == 2 || game.board[2][2] == 2);
}





#endif // TEST_GAME_H
