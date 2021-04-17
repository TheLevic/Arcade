#include <iostream>
#include <iomanip>
#include "connect4.h"

using namespace std;

void connect4::intro()
{
    cout << "---------Welcome to Connect-Four!------------\n";
    cout << "To win the game, you must place four of your pieces in a row on the board.\n";
    cout << "This is a 2-player game. Player1 has the avatar 'p' and Player2 has the avatar 'm'\n";
    cout << "You can win by connecting four pieces vertically, horizontally, or diagonally.\n";
    cout << "Good Luck!\n";
}

void connect4::initBoard(char board[SIZE_ROW][SIZE_COL])
{
    // initialize the board to all 'o'
    for(int row=0;row<SIZE_ROW;row++) 
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

bool connect4::isValidMove(const char board[SIZE_ROW][SIZE_COL], int & row, const int col){
    //check if user input is within the bounds of the board
    //We do not need to check the row in this place because we are just checking whether or
    //not the user input for column is valid

    if (col >= 0 && col <= SIZE_COL - 1){ //Checking to make sure that they input within the bounds
        
        for(int i = row; i >= 0; i--){ //Checking to see if the row is full based on the characters
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

void connect4::playerMove(char board[SIZE_ROW][SIZE_COL], int & playerRow, int & playerCol, const char avatar){
    //Declarations
    bool t_or_f; 
    //set the player's row to the bottom of the board to start out
    playerRow = 5;
    
    //print message declaring who's turn it is
    if (avatar == 'p'){
        cout << "It is Player1's turn!" << endl;
    }
    if (avatar == 'm'){
        cout << "It is Player2's turn!" << endl;
    }

    //Ask player for column and check to see if it was a valid move
    cout << "Please enter a column to place your piece: " << endl;
    cin >> playerCol;
    t_or_f = isValidMove(board, playerRow, playerCol);

    //If it is false, make them enter something that works
    while (t_or_f == false){
        //reset the row in case we ran out of room in a previous column
        playerRow = 5;
        cout << "Invalid move, please enter a valid column!" << endl;
        cin >> playerCol;
        t_or_f = isValidMove(board, playerRow, playerCol);
    }

    //once a valid choice has been made, update the board with the player's avatar
    if (t_or_f == true){
        board[playerRow][playerCol] = avatar;
    }

}

bool connect4::checkVertical(char board[SIZE_ROW][SIZE_COL], const int currentRow, const int currentCol, const char avatar)
{
    //Declarations
    bool matchFound = false;
    int numMatches = 0;

    //Starting at row 0 going down to 5
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
    //Declarations
    bool matchFound = false;
    int numMatches = 0;

    //Starting at column 0 and checking to the right
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
        //outside the bounds for looking at diagonal (\)
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
        //outside the bounds for looking at diagonal (/)
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
        //if either diagonal has four avatar pieces in a row, a match has been found
        if(numMatches1 == 4 || numMatches2 == 4)
            matchFound = true;
    }
    return matchFound;
}

bool connect4::winGame(char board[SIZE_ROW][SIZE_COL], const int currentRow, const int currentCol, const char avatar)
{
    
    //Call functions to check for a winning combo
    //return true if player has four pieces in a row
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
    //Declarations
    char yorn = ' ';
    //ask player question, get user input
    //return appropriate true/false based off of user input
    cout << "Would you like to keep playing? Enter Y or N." << endl;
    cin >> yorn;

    while (yorn != 'Y' && yorn != 'N'){
        cout << "You did not enter in a valid value. Would you like to keep playing? Enter Y or N: " << endl;
        cin >> yorn;
    }

    if (yorn == 'Y'){
        return true;
    }
    else if (yorn == 'N'){
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