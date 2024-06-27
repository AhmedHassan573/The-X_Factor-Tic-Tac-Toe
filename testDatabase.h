//  testDatabase.h
//  testDb
//
//  Created by Ahmed Tarek on 26/06/2024.
//

#ifndef testDatabase_h
#define testDatabase_h

#include <gtest/gtest.h>
#include "Database.h"  // Include library's header

class DatabaseTest : public ::testing::Test {
protected:
    //Arrangements to be made for every test
    
    // Create database
    database_t db;
    
    // When starting test initialize database
    void SetUp() override {
        // Initialize database
        db.Initialize_Database();
    }
    
    // When ending test delete all databases created
    void TearDown() override {
        db.Delete_Players_Table();
        db.Delete_Score_Table();
        db.Delete_Game_History_Table();
        db.Delete_Passwords_Table();
    }
};

// Test if the database is created correctly
TEST_F(DatabaseTest, InitializationTest) {
    EXPECT_NO_THROW(db.Initialize_Database());
}

// Sign up a new user test
TEST_F(DatabaseTest, SignUpNewUserTest) {
    db.player.username = "testuser";
    db.player.password = "testpass";
    
    ::testing::internal::CaptureStderr();
    
    db.Sign_Up();
    
    std::string message = ::testing::internal::GetCapturedStderr();
    EXPECT_EQ(message, "");
}

// Sign up an existing user test
TEST_F(DatabaseTest, SignUpExistingUserTest) {
    db.player.username = "testuser";
    db.player.password = "testpass";
    db.Sign_Up();
    
    db.player.username = "testuser";
    db.player.password = "testpass";
    
    ::testing::internal::CaptureStderr();
    
    db.Sign_Up();
    
    std::string message = ::testing::internal::GetCapturedStderr();
    
    EXPECT_NE(message, "");
}

TEST_F(DatabaseTest, LoginSuccessTest) {
    db.player.username = "testuser";
    db.player.password = "testpass";
    db.Sign_Up();
    db.player.username = "testuser";
    db.player.password = "testpass";
    EXPECT_NE(db.Login(), -1);
}

TEST_F(DatabaseTest, LoginFailureTest) {
    db.player.username = "testuser";
    db.player.password = "wrongpass";
    db.Sign_Up();
    db.player.username = "testuser";
    db.player.password = "testpass";
    EXPECT_EQ(db.Login(), -1);
}

// Try to show empty score table
TEST_F(DatabaseTest, ShowScoreTableTest) {
    EXPECT_NO_THROW(db.Show_Score_Table());
}

// Try to show empty players table
TEST_F(DatabaseTest, ShowPlayersTableTest) {
    EXPECT_NO_THROW(db.Show_Players_Table());
}

// Adding a new player to the score table and showing their stats after
TEST_F(DatabaseTest, GetScoreTest) {
    db.player.username = "testuser";
    db.player.password = "testpass";
    db.Sign_Up();
    db.Add_To_Score_Table("testuser", 1, 0, 0);
    unsigned int won, lost, draw;
    db.Get_Score("testuser", won, lost, draw);
    EXPECT_EQ(won, 1);
    EXPECT_EQ(lost, 0);
    EXPECT_EQ(draw, 0);
}

// Testing adding the same player to the score table
TEST_F(DatabaseTest, AddPlayerToScoreTableFail) {
    db.player.username = "testuser";
    db.player.password = "testpass";
    db.Sign_Up();
    db.Add_To_Score_Table("testuser", 1, 0, 0);
    EXPECT_EQ(db.Add_To_Score_Table("testuser", 1, 0, 0), -1);
}

// Testing updating the values of the player in the score table
TEST_F(DatabaseTest, UpdateScoreTest) {
    db.player.username = "testuser";
    db.player.password = "testpass";
    db.Sign_Up();
    db.Add_To_Score_Table("testuser", 1, 0, 0);
    unsigned int won, lost, draw;
    db.Update_Score_Table("testuser", 4, 5, 1);
    db.Get_Score("testuser", won, lost, draw);
    
    EXPECT_EQ(won, 4);
    EXPECT_EQ(lost, 5);
    EXPECT_EQ(draw, 1);
}

// Test creating game history table
TEST_F(DatabaseTest, CreateGameHistoryTableTest) {
    EXPECT_NO_THROW(db.Create_Game_History_Table("player1name", "player2name", true));
}

// Test updating game history table not throwing any exceptions
TEST_F(DatabaseTest, UpdateGameHistoryTableTest) {
    db.Create_Game_History_Table("player1", "player2", true);
    
    ::testing::internal::CaptureStderr();
    
    db.Update_Game_History_Table(1, 2, 0, 0);
    db.Update_Game_History_Table(3, 4, 0, 0);
    db.Update_Game_History_Table(9, -1, 1, 0);
    
    std::string message = ::testing::internal::GetCapturedStderr();
    
    EXPECT_EQ(message, "");
}

// Test showing game history table correctly for 1v1
TEST_F(DatabaseTest, UpdateGameHistoryTableAndShowTest) {
    // 1v1
    db.Create_Game_History_Table("player1", "player2", true);
    
    // Player 1 wins
    db.Update_Game_History_Table(1, 5, 0, 0);
    db.Update_Game_History_Table(3, 4, 0, 0);
    db.Update_Game_History_Table(2, -1, 1, 0);
    
    int player1moves[] = {1, 3, 2};
    int player2moves[] = {5, 4, -1};
    moves_t moves_array[MOVES_CAPACITY];
    int number_of_moves = db.Get_Game_History_Table(moves_array);
    
    for(int i = 0; i < number_of_moves; i++){
        EXPECT_EQ(moves_array[i].playerx_move, player1moves[i]);
        EXPECT_EQ(moves_array[i].playery_move, player2moves[i]);
    }
}

// Test showing game history table correctly for 1vAI
TEST_F(DatabaseTest, UpdateGameHistoryTableAndShowAITest) {
    // 1vAI
    db.Create_Game_History_Table("player1", "player2", false);
    
    // Player 1 wins
    db.Update_Game_History_Table(1, 5, 0, 0);
    db.Update_Game_History_Table(3, 4, 0, 0);
    db.Update_Game_History_Table(2, -1, 1, 0);
    
    int player1moves[] = {1, 3, 2};
    int player2moves[] = {5, 4, -1};
    moves_t moves_array[MOVES_CAPACITY];
    int number_of_moves = db.Get_Game_History_Table(moves_array);
    
    for(int i = 0; i < number_of_moves; i++){
        EXPECT_EQ(moves_array[i].playerx_move, player1moves[i]);
        EXPECT_EQ(moves_array[i].playery_move, player2moves[i]);
    }
}

// Additional tests for boundary conditions, negative scenarios, concurrency, and resource management
TEST_F(DatabaseTest, SignUpWithLongUsernameAndPassword) {
    db.player.username = std::string(1000, 'a'); // Very long username
    db.player.password = std::string(1000, 'b'); // Very long password
    EXPECT_NO_THROW(db.Sign_Up());
}

TEST_F(DatabaseTest, UpdateScoreWithEdgeValues) {
    db.player.username = "testuser";
    db.player.password = "testpass";
    db.Sign_Up();
    db.Add_To_Score_Table("testuser", UINT_MAX, UINT_MAX, UINT_MAX); // Edge values
    unsigned int won, lost, draw;
    db.Get_Score("testuser", won, lost, draw);
    EXPECT_EQ(won, UINT_MAX);
    EXPECT_EQ(lost, UINT_MAX);
    EXPECT_EQ(draw, UINT_MAX);
}

#endif /* testDatabase_h */
