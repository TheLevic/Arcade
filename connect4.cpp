#include <iostream>
#include <iomanip>
#include "connect4.h"

using namespace std;

void connect4::intro()
{
    cout << "---------Welcome to PF1GANG's Connect Four!----------\n";
    cout << "A classic game where you if you get four pieces in a row, you win!\n";
    cout << "This is a 2-player game. Player1 has the avatar 'p' and Player2 has the avatar 'm'\n";
    cout << "To win you need to connect four pieces vertically, horizontally, or diagonally.\n";
    cout << "Grab your opponent, and let's get started!\n";
}

void connect4::initBoard(char board[SIZE_ROW][SIZE_COL])
{
    for(int row=0;row<SIZE_ROW;row++) //empty board to just o's
    {
        for(int col=0;col<SIZE_COL;col++) 
        {
            board[row][col] = 'o';
        }
    }
}

void connect4::printBoard(const char board[SIZE_ROW][SIZE_COL])
{
    cout << "           CONNECT FOUR\n      ";
    for(int i = 0; i < SIZE_COL; i++)
        cout << i << "  ";
    cout << endl;
    
    for(int row = 0; row < SIZE_ROW; row++) 
    {
        cout << setw(3) << row << " | ";
        for(int col = 0; col < SIZE_COL; col++) 
        {
           cout << board[row][col] << "  ";
        }
        cout << "|" << endl;
   }
}

char connect4::firstMove()
{
    int num = rand();
    if(num % 2 == 0)
        return PLAYER1_AV; //player 1 will go first for even numbers
    else
        return PLAYER2_AV; //player 2 will go first for odd numbers
}

bool connect4::isValidMove(const char board[SIZE_ROW][SIZE_COL], int & row, const int col)
{
    if (col >= 0 && col <= SIZE_COL - 1){ //Check input is in bounds
        
        for(int i = row; i >= 0; i--){ //Check if row is full
            if (board[i][col] != 'o'){
                continue;
                return false;
            }
            else if (board[i][col] == 'o'){
                row = i;
                return true;
                break;
            }
        }
    }
    else{
        return false;
    } 
    return 0;
}

void connect4::playerMove(char board[SIZE_ROW][SIZE_COL], int & playerRow, int & playerCol, const char avatar)
{
    bool t_or_f; 
    playerRow = 5; //start at bottom
    
    if (avatar == 'p'){ //whose turn it is
        cout << "It is Player1's turn!" << endl;
    }
    if (avatar == 'm'){
        cout << "It is Player2's turn!" << endl;
    }

    cout << "Please enter a column to place your piece: " << endl; //get user input
    cin >> playerCol;
    t_or_f = isValidMove(board, playerRow, playerCol);

    while (t_or_f == false){
        playerRow = 5; //reset row
        cout << "Invalid move, please enter a valid column!" << endl;
        cin >> playerCol;
        t_or_f = isValidMove(board, playerRow, playerCol);
    }

    if (t_or_f == true){ //update board
        board[playerRow][playerCol] = avatar;
    }

}

bool connect4::checkVertical(char board[SIZE_ROW][SIZE_COL], const int currentRow, const int currentCol, const char avatar)
{
    bool matchFound = false;
    int numMatches = 0;

    for (int i = 0; i <= SIZE_ROW - 1; i++){
        if (board[currentRow + i][currentCol] == avatar){
            numMatches++;
        }
        else{
            numMatches = 0;
        }
        if (numMatches == 4){
            matchFound = true;
        }
    }
    return matchFound;
}

bool connect4::checkHorizontal(char board[SIZE_ROW][SIZE_COL], const int currentRow, const int currentCol, const char avatar)
{
    bool matchFound = false;
    int numMatches = 0;

    for (int i = -3; i <= 3; i++){

        if (currentCol + i < 0 || currentCol + i > SIZE_COL - 1){
            numMatches = 0;
        }

        if (board[currentRow][currentCol + i] == avatar){
            numMatches++;
        }
        else{
            numMatches = 0;
        }
        if (numMatches == 4){
            matchFound = true;
        }
    }
    return matchFound;
}

bool connect4::checkDiagonal(char board[SIZE_ROW][SIZE_COL], const int currentRow, const int currentCol, const char avatar)
{
    bool matchFound = false;

    int numMatches1 = 0; //for diagonal (\)
    int numMatches2 = 0; //for diagonal (/)
    for(int i = -3; i <= 3; i++)
    {
        if(currentCol + i < 0 || currentCol + i > SIZE_COL-1 || currentRow + i < 0 || currentRow + i > SIZE_ROW-1)
        {
            numMatches1 = 0;
        }
        else
        {
            if(board[currentRow+i][currentCol+i] == avatar)
                numMatches1++;
            else
                numMatches1 = 0;
        }
        if(currentCol + i < 0 || currentCol + i > SIZE_COL-1 || currentRow - i < 0 || currentRow - i > SIZE_ROW-1)
        {
            numMatches2 = 0;
        }
        else
        {
            if(board[currentRow-i][currentCol+i] == avatar)
                numMatches2++;
            else
                numMatches2 = 0;  
        }
        if(numMatches1 == 4 || numMatches2 == 4)
            matchFound = true;
    }
    return matchFound;
}

bool connect4::winGame(char board[SIZE_ROW][SIZE_COL], const int currentRow, const int currentCol, const char avatar)
{
    if (checkVertical(board, currentRow, currentCol, avatar) == true 
            || checkHorizontal(board, currentRow, currentCol, avatar) == true 
            || checkDiagonal(board, currentRow, currentCol, avatar) == true){
                return true;
            }
    else{
        return false;
    }
    
}

bool connect4::keepPlaying()
{
    char yorn = ' ';
    cout << "Would you like to keep playing? Enter Y or N." << endl;
    cin >> yorn;

    while (yorn != 'y' && yorn != 'n'){
        cout << "You did not enter in a valid value. Would you like to keep playing? Enter Y or N: " << endl;
        cin >> yorn;
        yorn = tolower(yorn);
    }

    if (yorn == 'y'){
        return true;
    }
    else if (yorn == 'n'){
        return false;
    }
    return 0;
}

void connect4::switchPlayer(char & currAvatar)
{
    if (currAvatar == PLAYER1_AV){
        currAvatar = PLAYER2_AV;
    }
    else{
        currAvatar = PLAYER1_AV;
    }
}