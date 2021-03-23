
/**
 * @file Test.cpp
 * @author Afik Peretz
 * @brief tests for the second assignment messageboard
 * @date 2021-03-22
 * @copyright Copyright (c) 2021
 * 
 */

#include <string>
#include "doctest.h"
#include "Direction.hpp"
#include "Board.hpp"
using namespace ariel;
using namespace std;

TEST_CASE("Board changes") {
    Board board;
    CHECK_NOTHROW(board.post(4,5,Direction::Horizontal,"Afik"));
    CHECK_NOTHROW(board.post(4,5,Direction::Vertical,"Afik"));
    CHECK(board.read(4,5,Direction::Horizontal,4) == "Afik");
    CHECK(board.read(4,5,Direction::Vertical,4) == "Afik");
    CHECK_NOTHROW(board.post(4,5,Direction::Horizontal,"Z"));
    CHECK(board.read(4,5,Direction::Horizontal,5) == "Zfik");
    CHECK(board.read(4,5,Direction::Vertical,5) == "Zfik");
    CHECK_NOTHROW(board.post(4,6,Direction::Horizontal,"T"));
    CHECK(board.read(4,5,Direction::Horizontal,5) == "ZTik");
    CHECK(board.read(4,5,Direction::Vertical,5) == "Zfik");
    CHECK_NOTHROW(board.post(4,5,Direction::Horizontal,"shawarma"));
    CHECK_NOTHROW(board.post(4,5,Direction::Vertical,"shawarma"));
    CHECK(board.read(4,5,Direction::Horizontal,8) == "shawarma");
    CHECK(board.read(4,5,Direction::Vertical,8) == "shawarma");
}

TEST_CASE("Exceptions Error") {
    Board board;
    CHECK_THROWS(board.read(0,0,Direction::Horizontal,7));
    CHECK_THROWS(board.read(0,0,Direction::Vertical,8));
    CHECK_NOTHROW(board.post(0,0,Direction::Horizontal,"afik"));
    CHECK_NOTHROW(board.post(0,0,Direction::Vertical,"peretz"));
    CHECK_THROWS(board.read(450,450,Direction::Horizontal,6));
    CHECK_THROWS(board.read(450,450,Direction::Vertical,17));
    CHECK_NOTHROW(board.post(450,450,Direction::Horizontal,"peretz"));
    CHECK_NOTHROW(board.post(450,450,Direction::Vertical,"peretz"));
    CHECK_NOTHROW(board.read(450,450,Direction::Horizontal,6));
    CHECK_NOTHROW(board.read(450,450,Direction::Vertical,6));
}



