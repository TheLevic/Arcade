#include <iostream>
#include <iomanip>
#include "tictactoe.h"

void tictactoe::intro()
{
    cout << "Welcome to PF1GANG's Tic-Tac-Toe.\n";
    cout << "This is a 2 player game, grab your oponent and let's get started!\n";
}

void tictactoe::getInput(char board[boardSize][boardSize])
{
    cout << "Enter your x's and o's on the board (Left to right, top to bottom): "; //get user input
   for (int row = 0; row < boardSize; row++)
      for (int col = 0; col < boardSize; col++)
            cin >> board[row][col];
}

void tictactoe::printBoard(const char board[boardSize][boardSize])
{
    cout << "\n|---|---|---|\n"; 
   for (int row = 0; row < boardSize; row++)
   {
      cout << "| ";
      for (int col = 0; col < boardSize; col++)
         cout << board[row][col] << " | ";
      cout << "\n|---|---|---|\n";
   }
}

void tictactoe::checkInputs(char board[boardSize][boardSize])
{
   bool checkInput = true;
   for (int row = 0; row < boardSize; row++) // check user input for only x's and o's
      for (int col = 0; col < boardSize; col++)
      {
   if (board[row][col] == 'x' || board[row][col] == 'o')
        checkInput = true;
   else
        checkInput = false;
      }
        
   if (!checkInput)
   {
      cout << "Sorry, you can only enter x's and o's\n";
      exit(1);
   }
}

void tictactoe::checkWinner(char board[boardSize][boardSize])
{
    char winner = ' '; // check top left to bottom right diagonal
   if ((board[0][0] == board[1][1]) &&
       (board[1][1] == board[2][2]))
      winner = board[0][0];
      
   if ((board[0][2] == board[1][1]) && // check bottom left to top right diagonal
       (board[1][1] == board[2][0]))
      winner = board[0][0];

   for (int row = 0; row < boardSize; row++) // check the rows for a winner
      if ((board[row][0] == board[row][1]) &&
          (board[row][1] == board[row][2]))
         winner = board[row][0];

   for (int row = 0; row < boardSize; row++) // check the columns for a winner
      if ((board[0][row] == board[1][row]) &&
          (board[1][row] == board[2][row]))
         winner = board[0][row];
         
   if (winner != ' ')
      cout << "Congratulations to whichever oponent is " << winner << ", you are the winner!\n";
   else
      cout << "Oof looks like its a tie, better luck next time!\n";
}
