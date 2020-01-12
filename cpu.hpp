//
// Created by ian on 1/10/20.
//

#ifndef INC_162LAB1_0_CPU_HPP
#define INC_162LAB1_0_CPU_HPP

#include "game.hpp"

void cpuMove(Tile gameBoard[SIZE], Tile cpu_tile);
int score_move(Tile gameBoard[SIZE], Tile tileType);
int cpuMax(Tile gameBoard[SIZE], Tile tileType, int depth);
int getBestMove(Tile gameBoard[SIZE], Tile tileType);
int opponentMin(Tile gameBoard[SIZE], Tile tileType, int depth);

#endif //INC_162LAB1_0_CPU_HPP
