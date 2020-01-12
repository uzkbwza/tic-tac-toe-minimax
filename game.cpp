//
// Created by ian on 1/10/20.
//

#include "game.hpp"
#include "cpu.hpp"
#include <iostream>

using namespace std;

void displayInstructions()
// shows rules and layout of board.
{
    cout << "Welcome to Tic-Tac-Toe. Enter numbers 0 through 8 to place your" <<
         " piece on the board (you are X). The board is laid out like so: " <<
         endl <<
         "[0] [1] [2]" << endl <<
         "[3] [4] [5]" << endl <<
         "[6] [7] [8]" << endl <<
         "Your goal is to get 3 consecutive pieces in a row, " <<
         "from top to bottom, left to right, or corner to corner." << endl <<
         "-----------" << endl;
}

void showBoard(Tile gameBoard[SIZE])
// displays current board contents
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << '[';
        switch(gameBoard[i]) {
            case Cross:
                cout << 'X';
                break;
            case Circle:
                cout << 'O';
                break;
            default:
                cout << ' ';
                break;
        }
        cout << ']' << ' ';

        if ((i + 1) % 3 == 0) {
            cout << '\n';
        }
    }
}

void getMove(Player player, Tile gameBoard[SIZE], Tile tileType) {
    string playerString;

    int move;
    bool valid_move = false;
    cout << "Make your move." << endl;

    // depending on the player type, get moves using their respective process
    if (player == Computer) {
        cpuMove(gameBoard, tileType);
        return;
    } else {
        do
        {
            cout << "Enter number from 0 to " << SIZE - 1
                 << " which isn't already taken on the board." << endl;
            cout << "> ";
            cin.clear();
            cin >> move;
            cout << endl;

            if (cin.fail())
                continue;

            if (move >= 0 && move < SIZE && gameBoard[move] == Empty)
            {
                valid_move = true;
            }

        } while (!valid_move);

    }
    gameBoard[move] = tileType;
}

bool checkWin(Tile gb[SIZE]) {
    return (
            // horizontal, top row
            (gb[0] == gb[1] && gb[1] == gb[2] && gb[0] != Empty) ||

            // horizontal, middle row
            (gb[3] == gb[4] && gb[4] == gb[5] && gb[3] != Empty) ||

            // horizontal, bottom row
            (gb[6] == gb[7] && gb[7] == gb[8] && gb[6] != Empty) ||

            // vertical, left column
            (gb[0] == gb[3] && gb[3] == gb[6] && gb[0] != Empty) ||

            // vertical, middle column
            (gb[1] == gb[4] && gb[4] == gb[7] && gb[1] != Empty) ||

            // vertical, right column
            (gb[2] == gb[5] && gb[5] == gb[8] && gb[2] != Empty) ||

            // diagonal, northwest to southeast
            (gb[0] == gb[4] && gb[4] == gb[8] && gb[0] != Empty) ||

            // diagonal, southwest to northeast
            (gb[6] == gb[4] && gb[4] == gb[2] && gb[6] != Empty)
    );
}


// currently used for the CPU algorithm
Tile checkWinner (Tile gb[SIZE]) {
    if (!checkWin(gb))
        return Empty;

    // horizontal, top row, vertical, left column,
    // and diagonal, northwest to southeast
    if ((gb[0] == gb[1] && gb[1] == gb[2] && gb[0] != Empty) ||
        (gb[0] == gb[3] && gb[3] == gb[6] && gb[0] != Empty) ||
        (gb[0] == gb[4] && gb[4] == gb[8] && gb[0] != Empty))
        return gb[0];

    // horizontal, middle row
    if (gb[3] == gb[4] && gb[4] == gb[5] && gb[3] != Empty)
        return gb[3];

    // horizontal, bottom row and diagonal, southwest to northeast
    if ((gb[6] == gb[7] && gb[7] == gb[8] && gb[6] != Empty) ||
        (gb[6] == gb[4] && gb[4] == gb[2] && gb[6] != Empty))
        return gb[6];

    // vertical, middle column
    if (gb[1] == gb[4] && gb[4] == gb[7] && gb[1] != Empty)
        return gb[1];

    // vertical, right column
    if (gb[2] == gb[5] && gb[5] == gb[8] && gb[2] != Empty)
        return gb[2];
};

bool checkDraw(Tile gameBoard[SIZE]) {
    // if the board is full, that is a game over state.
    bool board_full = true;
    for (int i = 0; i < SIZE; i++) {
        if (gameBoard[i] == Empty)
            board_full = false;
    }

    return board_full && !checkWin(gameBoard);
}