//
//  main.cpp
//  testDb
//
//  Created by Ahmed Tarek on 26/06/2024.
//


#include <gtest/gtest.h>
#include "testDatabase.h"
#include "test_game.h"

int main(int argc, char **argv) {    
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
