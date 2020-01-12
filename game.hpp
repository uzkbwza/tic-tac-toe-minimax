//
// Created by ian on 1/10/20.
//

#ifndef INC_162LAB1_0_GAME_HPP
#define INC_162LAB1_0_GAME_HPP

const int SIZE = 9;

enum Tile {
    Empty,
    Cross,
    Circle,
};

enum Player {
    Human,
    Computer,
};

void displayInstructions();
void showBoard(Tile gameBoard[SIZE]);
void getMove(Player player, Tile gameBoard[SIZE], Tile tileType);
bool checkWin(Tile gb[SIZE]);
Tile checkWinner (Tile gb[SIZE]);
bool checkDraw(Tile gameBoard[SIZE]);

#endif //INC_162LAB1_0_GAME_HPP
