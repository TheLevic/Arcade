#include <iostream>
#include <cstdlib>
#include "tictactoe.h"

int main()
{
    int answer = 0;
    
    cout << "Welcome to the Classic Arcade by PF1GANG Studios!" << endl
         << "Which game would you like to play?" << endl
         << "1. Hangman" << endl
         << "2. Connect 4" << endl
         << "3. Tic-Tac-Toe" << endl
         << "4. Checkers" << endl
         << "5. Battleship" << endl;
    cin >> answer;
    
    while (answer != 1 && answer != 2 && answer != 3 && answer != 4 && answer != 5)
    {
        cout << "Error... Please input a proper integer 1-5" << endl
             << "1. Hangman" << endl
             << "2. Connect 4" << endl
             << "3. Tic-Tac-Toe" << endl
             << "4. Checkers" << endl
             << "5. Battleship" << endl;
        cin >> answer;
    }
    
    switch (answer)
    {
        case 1: cout << "Hangman"; break;
        case 2: cout << "Connect 4"; break;
        case 3: 
        {
        tictactoe game;
        char board[boardSize][boardSize];
        game.intro();
        game.getInput(board);
        game.printBoard(board);
        game.checkInputs(board);
        game.checkWinner(board);
        break;
        }
        case 4: cout << "Checkers"; break;
        case 5: cout << "Battleship"; break;
    }
    if (answer == 3)
        
    
    return(0);
}

