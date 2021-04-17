#include <iostream>
#include <cstdlib>
using namespace std;

void tictactoeGame()
{
   const int boardSize = 3;
   char board[boardSize][boardSize];

   cout << "Welcome to PF1GANG's Tic-Tac-Toe.\n";
   cout << "This is a 2 player game, grab your oponent and let's get started!\n";
   
   cout << "Enter your x's and o's on the board (Left to right, top to bottom): "; //get user input
   for (int row = 0; row < boardSize; row++)
      for (int col = 0; col < boardSize; col++)
            cin >> board[row][col];
        
   cout << "\n|---|---|---|\n"; // print out the board
   for (int row = 0; row < boardSize; row++)
   {
      cout << "| ";
      for (int col = 0; col < boardSize; col++)
         cout << board[row][col] << " | ";
      cout << "\n|---|---|---|\n";
   }

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
        case 3: cout << "Tic-Tac-Toe"; break;
        case 4: cout << "Checkers"; break;
        case 5: cout << "Battleship"; break;
    }
    if (answer == 3)
        tictactoeGame();
    
    return(0);
}
