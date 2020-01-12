#include "cpu.hpp"
#include "game.hpp"
#include <iostream>

using namespace std;

// This uses the minimax algorith to search through all possible gamestates
// and determines the best possible move.
// if i did this right, the AI should be unbeatable.

void cpuMove(Tile gameBoard[SIZE], Tile tileType) {
    // get and display move for computer player
    int move = getBestMove(gameBoard, tileType);
    cout << "> " << move << endl;
    cout << endl;
    gameBoard[move] = tileType;
}

int getBestMove(Tile gameBoard[SIZE], Tile tileType) {
    // check all possible moves and determine the best one
    int best_move = -1000;
    int best_value = -1000;
    // consider all possible moves
    for (int i = 0; i < SIZE; i++) {
        // create new board to test move
        Tile prospectiveGameBoard[SIZE];
        for (int j = 0; j < SIZE; j++)
            prospectiveGameBoard[j] = gameBoard[j];

        // don't try to make move on used tile
        if (prospectiveGameBoard[i] != Empty)
            continue;

        // make move on prospective game board
        prospectiveGameBoard[i] = tileType;

        // get value of move from prospective board
        int value = opponentMin(prospectiveGameBoard, tileType, 0);
        if (value > best_value) {
            best_value = value;
            best_move = i;
        }
        // cout << "Best move: " << i << " with value " << value << endl;
        // showBoard(prospectiveGameBoard);

    }
    return best_move;
}

int cpuMax(Tile gameBoard[SIZE], Tile tileType, int depth) {
    // first half of recursive minimax algorithm
    if (checkWin(gameBoard) || checkDraw(gameBoard) || depth > SIZE) {
        return score_move(gameBoard, tileType);
    }

    int max = -1000;

    // consider all possible moves
    for (int i = 0; i < SIZE; i++) {
        // create new board to test move
        Tile prospectiveGameBoard[SIZE];
        for (int j = 0; j < SIZE; j++)
            prospectiveGameBoard[j] = gameBoard[j];

        // don't try to make move on used tile
        if (prospectiveGameBoard[i] != Empty)
            continue;

        // make move
        prospectiveGameBoard[i] = tileType;

        int x = opponentMin(prospectiveGameBoard, tileType, depth + 1);
        if (x > max)
            max = x;
         // cout << "CPU Depth " << depth << ": " << "Move " << i << ": " << x << endl;
         // showBoard(prospectiveGameBoard);
    }
    return max;
}

int opponentMin(Tile gameBoard[SIZE], Tile tileType, int depth) {
    // second half of recursive minimax algorithm

    if (checkWin(gameBoard) || checkDraw(gameBoard)) {
        return score_move(gameBoard, tileType);
    }

    Tile opponentType;
    if (tileType == Cross)
        opponentType = Circle;
    else
        opponentType = Cross;

    int min = 1000;

    // consider all possible moves
    for (int i = 0; i < SIZE; i++) {

        // create new board to test move
        Tile prospectiveGameBoard[SIZE];
        for (int j = 0; j < SIZE; j++)
            prospectiveGameBoard[j] = gameBoard[j];

        // don't try to make move on used tile
        if (prospectiveGameBoard[i] != Empty)
            continue;

        // make move
        prospectiveGameBoard[i] = opponentType;

        int x = cpuMax(prospectiveGameBoard, tileType, depth + 1);
        if (x < min)
            min = x;
        // cout << "Opponent Depth " << depth << ": " << "Move " << i << ": " << x << endl;
        // showBoard(prospectiveGameBoard);
    }
    return min;
}

int score_move(Tile gameBoard[SIZE], Tile tileType) {
    // determines value of board state
    if (checkWin(gameBoard))
    {
        Tile winner = checkWinner(gameBoard);
        if (winner == tileType)
            return 100;
        else
            return -100;
    }
    else
        return 0;
}