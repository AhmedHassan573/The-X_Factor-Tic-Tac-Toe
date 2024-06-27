#include "Database.h"

//Initialize Player Number and make it file-scope
static unsigned int player_number = 0;

//Private Methods Definitions
unsigned int database_t::Generate_Random_Number(void){
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    return (std::rand()%1000);
}
void database_t::player_t::player(std::string name,std::string pass){
    username = name;
    password = pass;
    return;
}
void database_t::Create_Players_Table(void){
    const char* sql_code =
      "CREATE TABLE players("
      "Username TEXT NOT NULL PRIMARY KEY, Password TEXT NOT NULL);";
  
  result = sqlite3_open("Data.db", &database);
  
  if (result) {
    std::cerr << "\nUnable to establish a connection to the database: "
              << sqlite3_errmsg(database) << std::endl;
    sqlite3_close(database);
    return;
  } else {
    std::cout << "\nSuccessfully connected to database" << std::endl;
    result = sqlite3_exec(database, sql_code, 0, 0, &error_message);
    
    if (result != SQLITE_OK) {
      std::cerr << "\nUnable to create players table: " << error_message << std::endl;
      if (error_message) {
        sqlite3_free(error_message);
      }
      sqlite3_close(database);
      return;
    } else {
      std::cout << "\nPlayers table created successfully" << std::endl;
    }
    
    if (error_message) {
      sqlite3_free(error_message);
    }
    error_message = nullptr;
    sqlite3_close(database);
  }
}
void database_t::Create_Score_Table(void){
    const char* sql_code =
      "CREATE TABLE score(Username TEXT NOT NULL PRIMARY KEY,"
      "Games_Won INT NOT NULL, Games_Lost INT NOT NULL, Games_Draw INT NOT NULL);";
  
  result = sqlite3_open("Data.db", &database);
  
  if (result) {
    std::cerr << "\nUnable to establish a connection to the database: "
              << sqlite3_errmsg(database) << std::endl;
    sqlite3_close(database);
    return;
  } else {
    std::cout << "\nSuccessfully connected to database" << std::endl;
    result = sqlite3_exec(database, sql_code, 0, 0, &error_message);
    
    if (result != SQLITE_OK) {
      std::cerr << "\nUnable to create score table: " << error_message << std::endl;
      if (error_message) {
        sqlite3_free(error_message);
      }
      sqlite3_close(database);
      return;
    } else {
      std::cout << "\nScore table created successfully" << std::endl;
    }
    
    if (error_message) {
      sqlite3_free(error_message);
    }
    error_message = nullptr;
    sqlite3_close(database);
  }
}
void database_t::Create_Passwords_Table(void){
    const char* sql_code =
      "CREATE TABLE passwords(Player_Number INT NOT NULL PRIMARY KEY,"
      "Password TEXT NOT NULL);";
  
  result = sqlite3_open("Data.db", &database);
  
  if (result) {
    std::cerr << "\nUnable to establish a connection to the database: "
              << sqlite3_errmsg(database) << std::endl;
    sqlite3_close(database);
    return;
  } else {
    std::cout << "\nSuccessfully connected to database" << std::endl;
    result = sqlite3_exec(database, sql_code, 0, 0, &error_message);
    
    if (result != SQLITE_OK) {
      std::cerr << "\nUnable to create passwords table: " << error_message << std::endl;
      if (error_message) {
        sqlite3_free(error_message);
      }
      sqlite3_close(database);
      return;
    } else {
      std::cout << "\nPasswords table created successfully" << std::endl;
    }
    
    if (error_message) {
      sqlite3_free(error_message);
    }
    error_message = nullptr;
    sqlite3_close(database);
  }
}
signed int database_t::Get_Player_Number(std::string name){
    size_t index = 0;
    const char* sql_code = "SELECT * FROM players;";
    result = sqlite3_open("Data.db",&database);
    if(result){
        std::cerr<<"\nUnable to establish a connection to the database : "<<sqlite3_errmsg(database)<<std::endl;
        sqlite3_close(database);
        return -1;
    }
    result = sqlite3_prepare_v2(database,sql_code,-1,&statement,0);
    if(result != SQLITE_OK){
        std::cerr<<"\nCouldn't prepare the statement : "<<sqlite3_errmsg(database)<<std::endl;
        sqlite3_close(database);
        return -1;
    }
    else{/*Do Nothing*/}
    while((result = sqlite3_step(statement))==SQLITE_ROW){
        const unsigned char* string = sqlite3_column_text(statement,0);
        if(string){
            player.username = std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement,0)));
            if(name == player.username){
                break;
            }
            else{
                ++index;
            }
        }
        else{
            ++index;
        }
    }
    if(result == SQLITE_DONE){
        sqlite3_finalize(statement);
        sqlite3_close(database);
        return -1;
    }
    else{
        sqlite3_finalize(statement);
        sqlite3_close(database);
        return index;
    }
    sqlite3_finalize(statement);
    sqlite3_close(database);
}
bool database_t::Player_Score_Exists(std::string name){
    const char* sql_code = "SELECT * FROM score;";
    result = sqlite3_open("Data.db",&database);
    if(result){
        std::cerr<<"\nUnable to connect to database"<<std::endl;
        sqlite3_close(database);
        return true;
    }
    result = sqlite3_prepare_v2(database,sql_code,-1,&statement,0);
    if(result != SQLITE_OK){
        std::cerr<<"\nCouldn't prepare statement : "<<sqlite3_errmsg(database)<<std::endl;
        sqlite3_close(database);
        return true;
    }
    else{/*Do Nothing*/}
    while((result = sqlite3_step(statement))==SQLITE_ROW){
        const unsigned char* string = sqlite3_column_text(statement,0);
        if(string){
            player.username = std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement,0)));
            if(name == player.username){
                break;
            }
        }
        else{/*Do Nothing*/}
    }
    if(result == SQLITE_DONE){
        sqlite3_finalize(statement);
        sqlite3_close(database);
        return false;
    }
    else{
        sqlite3_finalize(statement);
        sqlite3_close(database);
        return true;
    }
    sqlite3_finalize(statement);
    sqlite3_close(database);
    return true;
}
void database_t::Show_Score_Table(void){
    result = sqlite3_open("Data.db",&database);
    if(result){
        std::cerr<<"\nUnable to establish a connection to the database : "<<sqlite3_errmsg(database)<<std::endl;
        sqlite3_close(database);
        return;
    }
    const char* sql_code = "SELECT * FROM score;";
    result = sqlite3_prepare_v2(database,sql_code,-1,&statement,0);
    if(result != SQLITE_OK){
        std::cerr<<"\nCouldn't prepare the statement : "<<sqlite3_errmsg(database)<<std::endl;
        sqlite3_close(database);
        return;
    }
    else{/*Do Nothing*/}
    std::cout<<"\nUsername\t\t\tGames Won\t\t\tGames Lost\t\t\tGames Draw"<<std::endl;
    while((result = sqlite3_step(statement)) == SQLITE_ROW){
        std::cout<<std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement,0)))<<"\t\t\t"<<sqlite3_column_int(statement,1)<<"\t\t\t";
        std::cout<<sqlite3_column_int(statement,2)<<"\t\t\t"<<sqlite3_column_int(statement,3)<<std::endl;
    }
    if(result != SQLITE_DONE){
        std::cerr<<"\nFailed data acquisition : "<<sqlite3_errmsg(database)<<std::endl;
        sqlite3_close(database);
        return;
    }
    else{/*Do Nothing*/}
    sqlite3_finalize(statement);
    sqlite3_close(database);
}
void database_t::Show_Players_Table(void){
    result = sqlite3_open("Data.db",&database);
    if(result){
        std::cerr<<"\nUnable to establish a connection to the database : "<<sqlite3_errmsg(database)<<std::endl;
        sqlite3_close(database);
        return;
    }
    const char* sql_code = "SELECT * FROM players;";
    result = sqlite3_prepare_v2(database,sql_code,-1,&statement,0);
    if(result != SQLITE_OK){
        std::cerr<<"\nCouldn't prepare the statement : "<<sqlite3_errmsg(database)<<std::endl;
        sqlite3_close(database);
        return;
    }
    else{/*Do Nothing*/}
    std::cout<<"\nUsername\t\t\tPassword"<<std::endl;
    while((result = sqlite3_step(statement)) == SQLITE_ROW){
        player.username = std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement,0)));
        player.password = std::string(reinterpret_cast<const char*>(sqlite3_column_text(statement,1)));
        std::cout<<player.username<<"\t\t\t"<<player.password<<std::endl;
    }
    if(result != SQLITE_DONE){
        std::cerr<<"\nFailed data acquisition : "<<sqlite3_errmsg(database)<<std::endl;
        sqlite3_close(database);
        return;
    }
    else{/*Do Nothing*/}
    sqlite3_finalize(statement);
    sqlite3_close(database);
}
void database_t::Show_Game_History_Table(void){
    const char* sql_code = "SELECT * FROM game_history;";
    result = sqlite3_open("Data.db",&database);
    if(result){
        std::cerr<<"\nUnable to connect : "<<sqlite3_errmsg(database)<<std::endl;
        sqlite3_close(database);
        return;
    }
    else{
        std::cout<<"\nConnected Successfully"<<std::endl;
        result = sqlite3_prepare_v2(database,sql_code,-1,&statement,0);
        if(result != SQLITE_OK){
            std::cerr<<"\nCouldn't prepare the statement : "<<sqlite3_errmsg(database)<<std::endl;
            sqlite3_close(database);
            return;
        }
        else{
            std::cout<<std::endl<<player1_name<<"\t\t\t"<<player2_name<<std::endl;
            while((result = sqlite3_step(statement)) == SQLITE_ROW){
                std::cout<<sqlite3_column_int(statement,0)<<"\t\t\t"<<sqlite3_column_int(statement,1)<<std::endl;
            }
            if(result != SQLITE_DONE){
                std::cerr<<"\nError in game history acquisition "<<sqlite3_errmsg(database)<<std::endl;
                sqlite3_close(database);
                return;
            }
            else{/*Do Nothing*/} 
        }
        sqlite3_finalize(statement);
        sqlite3_close(database);
    }
}

//Public Methods Definitions
moves_t::moves_t(void){
    playerx_move = 0;
    playery_move = 0;
}
database_t::database_t(void){
    result = 0;
    error_message = nullptr;
}
signed int database_t::Login(void) {
    unsigned int number = Get_Player_Number(player.username);
    std::string password;
    std::string sql_code = "SELECT Password FROM passwords WHERE Player_Number = ?;";

    if (number == static_cast<unsigned int>(-1)) {
        std::cerr << "\nIncorrect username\n";
        return number;
    }

    result = sqlite3_open("Data.db", &database);
    if (result) {
        std::cerr << "\nUnable to connect to database: " << sqlite3_errmsg(database) << std::endl;
        sqlite3_close(database);
        return -1;
    }

    sqlite3_stmt* stmt;
    result = sqlite3_prepare_v2(database, sql_code.c_str(), -1, &stmt, 0);
    if (result != SQLITE_OK) {
        std::cerr << "\nCouldn't prepare statement: " << sqlite3_errmsg(database) << std::endl;
        sqlite3_close(database);
        return -1;
    }

    // Bind the player number to the SQL statement
    sqlite3_bind_int(stmt, 1, number);

    if ((result = sqlite3_step(stmt)) == SQLITE_ROW) {
        const unsigned char* string = sqlite3_column_text(stmt, 0);
        if (string) {
            password = std::string(reinterpret_cast<const char*>(string));
            if (player.password == password) {
                std::cout << "\nLogin Successful\n";
                sqlite3_finalize(stmt);
                sqlite3_close(database);
                return number;
            } else {
                std::cerr << "\nIncorrect Password\n";
                sqlite3_finalize(stmt);
                sqlite3_close(database);
                return -1;
            }
        } else {
            std::cerr << "\nIncorrect Password\n";
            sqlite3_finalize(stmt);
            sqlite3_close(database);
            return -1;
        }
    } else {
        std::cerr << "\nIncorrect Password\n";
        sqlite3_finalize(stmt);
        sqlite3_close(database);
        return -1;
    }

    sqlite3_finalize(stmt);
    sqlite3_close(database);
    return -1;
}
void database_t::Initialize_Database(void){
    Create_Players_Table();
    Create_Score_Table();
    Create_Passwords_Table();
}
bool database_t::Sign_Up(void){
    std::string sql_code1 = "INSERT INTO players(Username, Password) VALUES (?, ?);";
    std::string sql_code2 = "INSERT INTO passwords(Player_Number, Password) VALUES (?, ?);";

    result = sqlite3_open("Data.db", &database);
    if (result) {
        std::cerr << "\nUnable to establish a connection to the database: " << sqlite3_errmsg(database) << std::endl;
        sqlite3_close(database);
        return false;
    }

    sqlite3_stmt* stmt1;
    sqlite3_stmt* stmt2;

    // Prepare and execute the first statement
    result = sqlite3_prepare_v2(database, sql_code1.c_str(), -1, &stmt1, 0);
    if (result == SQLITE_OK) {
        sqlite3_bind_text(stmt1, 1, player.username.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt1, 2, "**", -1, SQLITE_STATIC);
        result = sqlite3_step(stmt1);
        sqlite3_finalize(stmt1);
    }

    if (result != SQLITE_DONE) {
        std::cerr << "\nRepeated Username Error!\n";
        std::cerr << "\nUnable to Sign-Up player: " << sqlite3_errmsg(database) << std::endl;
        sqlite3_close(database);
        return false;
    }

    // Prepare and execute the second statement
    result = sqlite3_prepare_v2(database, sql_code2.c_str(), -1, &stmt2, 0);
    if (result == SQLITE_OK) {
        unsigned int number = Get_Player_Number(player.username);
        sqlite3_bind_int(stmt2, 1, number);
        sqlite3_bind_text(stmt2, 2, player.password.c_str(), -1, SQLITE_STATIC);
        result = sqlite3_step(stmt2);
        sqlite3_finalize(stmt2);
    }

    if (result != SQLITE_DONE) {
        std::cerr << "\nUnable to store password: " << sqlite3_errmsg(database) << std::endl;
        sqlite3_close(database);
        return false;
    }

    std::cout << "\nPlayer Sign-Up successful" << std::endl;
    sqlite3_close(database);
    return true;
}
void database_t::Create_Game_History_Table(std::string player1,std::string player2,bool pvp){
    //Initializing The two players
    std::string sql_code;

    //Creating Game History table
    if(pvp){
        player1_name = player1;
        player2_name = player2;
        sql_code = "CREATE TABLE game_history('"+(player1_name)+"' INT NOT NULL,'"+(player2_name)+"' INT NOT NULL);";
    }
    else{
        unsigned int bot_id = Generate_Random_Number();
        player1_name = player1;
        player2_name = "Bot"+std::to_string(bot_id);
        sql_code = "CREATE TABLE game_history('"+(player1_name)+"' INT NOT NULL,'"+(player2_name)+"' INT NOT NULL);";
    }
    result = sqlite3_open("Data.db",&database);
    if(result){
        std::cerr<<"\nUnable to connect : "<<sqlite3_errmsg(database)<<std::endl;
        sqlite3_close(database);
        return;
    }
    else{
        std::cout<<"\nSuccessfully connected"<<std::endl;
        result = sqlite3_exec(database,sql_code.c_str(),0,0,&error_message);
        if(result != SQLITE_OK){
            std::cerr<<"\nUnable to create Game history table : "<<error_message;
            if(error_message){
                sqlite3_free(error_message);
                error_message = nullptr;
            }
            sqlite3_close(database);
            return;
        }
        else{
            std::cout<<"\nGame History Table created successfully"<<std::endl;
        }
        if(error_message){
            sqlite3_free(error_message);
            error_message = nullptr;
        }
        sqlite3_close(database);
    }
}
void database_t::Update_Game_History_Table(unsigned int player1_move,unsigned int player2_move,bool player1_win,bool player2_win){
    std::string sql_code;
    if(player1_win){
        sql_code = "INSERT INTO game_history('"+player1_name+"','"+player2_name+"')"\
                   "VALUES("+std::to_string(player1_move)+","+std::to_string(-1)+");";
    }
    else if(player2_win){
        sql_code = "INSERT INTO game_history('"+player1_name+"','"+player2_name+"')"\
                   "VALUES("+std::to_string(-1)+","+std::to_string(player2_move)+");";
    }
    else{
        sql_code = "INSERT INTO game_history('"+player1_name+"','"+player2_name+"')"\
                   "VALUES("+std::to_string(player1_move)+","+std::to_string(player2_move)+");";
    }
    result = sqlite3_open("Data.db",&database);
    if(result){
        std::cerr<<"\nUnable to connect : "<<sqlite3_errmsg(database)<<std::endl;
        sqlite3_close(database);
        return;
    }
    else{
        std::cout<<"\nConnected successfully"<<std::endl;
        result = sqlite3_exec(database,sql_code.c_str(),0,0,&error_message);
        if(result != SQLITE_OK){
            std::cerr<<"\nUnable to update game history"<<error_message<<std::endl;
            if(error_message){
                sqlite3_free(error_message);
                error_message = nullptr;
            }
            sqlite3_close(database);
            return;
        }
        else{
            std::cout<<"\nUpdated game history successfully"<<std::endl;
            if(error_message){
                sqlite3_free(error_message);
                error_message = nullptr;
            }
            sqlite3_close(database);
        }
    }
}
signed int database_t::Add_To_Score_Table(std::string player_name,unsigned int games_won,unsigned int games_lost,unsigned int games_draw){
    bool check_player = Player_Score_Exists(player_name);
    if(check_player == false){
        std::string sql_code = "INSERT INTO score(Username,Games_Won,Games_Lost,Games_Draw)"\
                               "VALUES('"+player_name+"',"+std::to_string(games_won)+","+std::to_string(games_lost)+","+std::to_string(games_draw)+");";
        result = sqlite3_open("Data.db",&database);
        if(result){
            sqlite3_close(database);
            return -1;
        }
        else{
            result = sqlite3_exec(database,sql_code.c_str(),0,0,&error_message);
            if(result != SQLITE_OK){
                std::cerr<<"\nUnable to add to score table : "<<error_message<<std::endl;
                if(error_message){
                    sqlite3_free(error_message);
                    error_message = nullptr;
                }
                sqlite3_close(database);
                return -1;
            }
            else{
                std::cout<<"\nSuccessfully added to score table"<<std::endl;
                if(error_message){
                    sqlite3_free(error_message);
                    error_message = nullptr;
                }
                sqlite3_close(database);
                return check_player;
            }
        }
    }
    else{
        std::cerr<<"\nPlayer "<<player_name<<" already exsists"<<std::endl;
        return -1;
    }
}
void database_t::Update_Score_Table(std::string player_name, int games_won,int games_lost,int games_draw){
    std::string sql_code = "UPDATE score SET Games_Won = "+std::to_string(games_won)+",Games_Lost = "+std::to_string(games_lost)+",Games_Draw = "\
                           +std::to_string(games_draw)+" WHERE Username = '"+player_name+"';";
    result = sqlite3_open("Data.db",&database);
    if(result){
        sqlite3_close(database);
        return;
    }
    else{
        result = sqlite3_exec(database,sql_code.c_str(),0,0,&error_message);
        if(result != SQLITE_OK){
            std::cerr<<"\nUnable to update score table : "<<error_message<<std::endl;
            if(error_message){
                sqlite3_free(error_message);
                error_message = nullptr;
            }
            sqlite3_close(database);
            return;
        }
        else{
            std::cout<<"\nSuccessfully updated score table"<<std::endl;
            if(error_message){
                sqlite3_free(error_message);
                error_message = nullptr;
            }
        }
        sqlite3_close(database);
    }
}
void database_t::Delete_Game_History_Table(void){
    result = sqlite3_open("Data.db",&database);
    if(result){
        std::cerr<<"\nUnable to establish a connection to the database : "<<sqlite3_errmsg(database)<<std::endl;
        sqlite3_close(database);
        return;
    }
    const char* sql_code = "DROP TABLE game_history;";
    result = sqlite3_exec(database,sql_code,0,0,&error_message);
    if(result != SQLITE_OK){
        std::cerr<<"\nError in deleting the table : "<<error_message<<std::endl;
        if(error_message){
            sqlite3_free(error_message);
            error_message = nullptr;
        }
        sqlite3_close(database);
        return;
    }
    else{
        std::cout<<"\nSuccessful deletion\n"<<std::endl;
    }
    if(error_message){
        sqlite3_free(error_message);
        error_message = nullptr;
    }
    sqlite3_close(database);
}
void database_t::Delete_Players_Table(void){
    result = sqlite3_open("Data.db",&database);
    if(result){
        std::cerr<<"\nUnable to establish a connection to the database : "<<sqlite3_errmsg(database)<<std::endl;
        sqlite3_close(database);
        return;
    }
    const char* sql_code = "DROP TABLE players;";
    result = sqlite3_exec(database,sql_code,0,0,&error_message);
    if(result != SQLITE_OK){
        std::cerr<<"\nError in deleting the table : "<<error_message<<std::endl;
        if(error_message){
            sqlite3_free(error_message);
            error_message = nullptr;
        }
        sqlite3_close(database);
        return;
    }
    else{
        std::cout<<"\nSuccessful deletion\n"<<std::endl;
    }
    if(error_message){
        sqlite3_free(error_message);
        error_message = nullptr;
    }
    sqlite3_close(database);
}
void database_t::Delete_Score_Table(void){
    result = sqlite3_open("Data.db",&database);
    if(result){
        std::cerr<<"\nUnable to establish a connection to the database : "<<sqlite3_errmsg(database)<<std::endl;
        sqlite3_close(database);
        return;
    }
    const char* sql_code = "DROP TABLE score;";
    result = sqlite3_exec(database,sql_code,0,0,&error_message);
    if(result != SQLITE_OK){
        std::cerr<<"\nError in deleting the table : "<<error_message<<std::endl;
        if(error_message){
            sqlite3_free(error_message);
            error_message = nullptr;
        }
        sqlite3_close(database);
        return;
    }
    else{
        std::cout<<"\nSuccessful deletion\n"<<std::endl;
    }
    if(error_message){
        sqlite3_free(error_message);
        error_message = nullptr;
    }
    sqlite3_close(database);
}
void database_t::Delete_Passwords_Table(void){
    result = sqlite3_open("Data.db",&database);
    if(result){
        std::cerr<<"\nUnable to connect to database : "<<sqlite3_errmsg(database)<<std::endl;
        sqlite3_close(database);
        return;
    }
    const char* sql_code = "DROP TABLE passwords;";
    result = sqlite3_exec(database,sql_code,0,0,&error_message);
    if(result != SQLITE_OK){
        std::cerr<<"\nError in deleting the table : "<<error_message<<std::endl;
        if(error_message){
            sqlite3_free(error_message);
            error_message = nullptr;
        }
        sqlite3_close(database);
        return;
    }
    else{
        std::cout<<"\nSuccessfull deletion\n"<<std::endl;
    }
    if(error_message){
        sqlite3_free(error_message);
        error_message = nullptr;
    }
    sqlite3_close(database);
}
void database_t::Get_Score(std::string name,int& won,int& lost,int& draw){
    std::string sql_code = "SELECT Games_Won,Games_Lost,Games_Draw FROM score WHERE "\
                           "Username = '"+name+"';";
    result = sqlite3_open("Data.db",&database);
    if(result){
        std::cerr<<"\nCouldn't connect to database : "<<sqlite3_errmsg(database)<<std::endl;
        sqlite3_close(database);
        return;
    }
    result = sqlite3_prepare_v2(database,sql_code.c_str(),-1,&statement,0);
    if(result != SQLITE_OK){
        std::cerr<<"\nCouldn't prepare statement : "<<sqlite3_errmsg(database)<<std::endl;
        sqlite3_finalize(statement);
        sqlite3_close(database);
        return;
    }
    if((result = sqlite3_step(statement))==SQLITE_ROW){
        won = sqlite3_column_int(statement,0);
        lost = sqlite3_column_int(statement,1);
        draw = sqlite3_column_int(statement,2);
        sqlite3_finalize(statement);
        sqlite3_close(database);
        return;
    }
    else{
        std::cerr<<"\nIncorrect username"<<std::endl;
        sqlite3_finalize(statement);
        sqlite3_close(database);
        return;
    }
    sqlite3_finalize(statement);
    sqlite3_close(database);
    return;
}
signed int database_t::Get_Game_History_Table(moves_t moves[MOVES_CAPACITY]){
    unsigned int index = 0;
    const char* sql_code = "SELECT * FROM game_history";
    result = sqlite3_open("Data.db",&database);
    if(result){
        std::cerr<<"\nCouldn't connect to database : "<<sqlite3_errmsg(database)<<std::endl;
        sqlite3_close(database);
        return -1;
    }
    result = sqlite3_prepare_v2(database,sql_code,-1,&statement,0);
    if(result != SQLITE_OK){
        std::cerr<<"\nUnable to prepare statement"<<std::endl;
        sqlite3_finalize(statement);
        sqlite3_close(database);
        return -1;
    }
    while((result = sqlite3_step(statement))==SQLITE_ROW){
        moves[index].playerx_move = sqlite3_column_int(statement,0);
        moves[index].playery_move = sqlite3_column_int(statement,1);
        ++index;
    }
    if(result == SQLITE_DONE){
        sqlite3_finalize(statement);
        sqlite3_close(database);
        return index;
    }
    sqlite3_finalize(statement);
    sqlite3_close(database);
    return index;
}
