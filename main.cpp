#include <iostream>
#include <iomanip>
#include <string>
#include "cpu.hpp"
#include "game.hpp"

using namespace std;

int main()
{
    Tile gameBoard[SIZE];
    Player playerCrosses = Human;
    // we don't know if playerCircles is a human or a cpu yet.
    Player playerCircles;
    bool gameTypeChosen = false;

    displayInstructions();

    // choose game type
    do {
        char gameTypeChoice;
        cout << "Play against (c)pu or another (p)layer?" << endl << "> ";
        cin >> gameTypeChoice;
        gameTypeChoice = tolower(gameTypeChoice);

        if (gameTypeChoice == 'p')
        {
            playerCircles = Human;
            gameTypeChosen = true;
        }
        else if (gameTypeChoice == 'c')
        {
            playerCircles = Computer;
            gameTypeChosen = true;
        }
    } while (!gameTypeChosen);

    int current_turn = 0;

    for (int i = 0; i < SIZE; i++)
    {
        gameBoard[i] = Empty;
    }

    bool game_over = false;

    // main game loop
    do
    {
        Tile tileType;
        Player current_player;
        if (current_turn == 0)
        {
            current_player = playerCrosses;
            tileType = Cross;
        }
        else
        {
            current_player = playerCircles;
            tileType = Circle;
        }

        if (current_player == Human)
            cout << "Player " << current_turn + 1 << " turn." << endl;
        else
            cout << "CPU turn." << endl;

        showBoard(gameBoard);
        getMove(current_player, gameBoard, tileType);

        if (checkWin(gameBoard)) {
            if (current_player == Human)
            {
                cout << "Player " << current_turn + 1 << " wins!" << endl;
            } else
            {
                cout << "CPU wins!" << endl;
            }

            showBoard(gameBoard);
            game_over = true;
        }

        if (checkDraw(gameBoard) && !game_over) {
            cout << "Draw!" << endl;
            showBoard(gameBoard);
            game_over = true;
        }

        // switch player
        if (current_turn == 0)
            current_turn = 1;
        else
            current_turn = 0;

    } while (!game_over);
}