/*Documentation:
  This is the database library for the C++ Tic-Tac-Toe project
  An Explanation for the included methods and members is as follows:
  
  1. player_t player: the player which can be intialized in main
  2. Create_Database(void): Function used to establish a connection with a .db(database) file and create a table
  3. Sign_Up(void): Function used to INSERT the initialized "player" object INTO the database (Adds a new row)
  4. Get_Player_Info(unsigned int ID): given a certain player_number the function returns into the "player" object the corresponding info
  5. Show_Database(void): Simply prints the database onto the screen
  6. Delete_Database(void): deletes the table that was initially created by Create_Database() function.

  Some Notes:
  Note1: It is good to think of the "player" object as a box in which a single player's info enters to be sent to the database
        When calling "Sign_Up()" or a single player's info is taken from when calling "Get_Player_Info()"
  Note2: Use the "." operator when accessing the "player" object
  Note3: Don't forget to "Delete_Database()" at the end of your code if it is no longer needed
  Note4: Number your players starting from 0 please

  To compile these files, please follow these steps carefully (You will have to use Command Prompt):
  First get the machine code of the sqlite3.c source file (If you already have it skip this step):
        gcc -c -o sqlite3.o sqlite3.c
  Then compile the files including all .cpp source files and also the sqlite3.o file:
        g++ -o Main.exe Main.cpp Database.cpp sqlite3.o
        
****************************************************************************************************************************************************/


//File Guard
#ifndef _DATABASE_H_
#define _DATABASE_H_

//Includes

extern "C" {
#include "sqlite3.h"
}
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <QMainWindow>

//Macros
#define PLAYER_CAPACITY (50)
#define MOVES_CAPACITY  (10)

//User_Defined Types
struct moves_t{
        signed int playerx_move;
        signed int playery_move;
        moves_t(void);
    };

class database_t{
private:
    //Player Data
    struct player_t{
        std::string username;
        std::string password;
        void player(std::string name,std::string pass);
    };
    std::string player1_name;
    std::string player2_name;

    //SQLite3 Data
    sqlite3* database;
    char* error_message;
    sqlite3_stmt* statement;
    signed int result;
    
    //Private Methods
    void Create_Players_Table(void);
    void Create_Score_Table(void);
    void Create_Passwords_Table(void);
    signed int Get_Player_Number(std::string name);
    bool Player_Score_Exists(std::string name);
    unsigned int Generate_Random_Number(void);
public:
    //Player Box
    player_t player;

    //Constructor and Initializer
    database_t(void);
    void Initialize_Database(void);

    //Sign-up and Login
    bool Sign_Up(void);
    signed int Login(void);

    //Game History Table
    void Create_Game_History_Table(std::string player1,std::string player2,bool pvp);
    void Update_Game_History_Table(unsigned int player1_move,unsigned int player2_move,bool player1_win,bool player2_win);
    signed int Get_Game_History_Table(moves_t moves[MOVES_CAPACITY]);
    void Show_Game_History_Table(void);
    void Delete_Game_History_Table(void);

    //Score Table
    signed int Add_To_Score_Table(std::string player_name,unsigned int games_won,unsigned int games_lost,unsigned int games_draw);
    void Update_Score_Table(std::string player_name, int games_won,int games_lost, int games_draw);
    void Get_Score(std::string name,int& won,int& lost,int& draw);
    void Show_Score_Table(void);
    void Delete_Score_Table(void);

    //Delete and Show Players table
    void Delete_Players_Table(void);
    void Show_Players_Table(void);

    //Delete passwords table
    void Delete_Passwords_Table(void);
};

#endif
