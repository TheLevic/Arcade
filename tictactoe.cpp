#include <iostream>
#include <iomanip>
#include "tictactoe.h"

void tictactoe::intro()
{
    cout << "Welcome to PF1GANG's Tic-Tac-Toe.\n";
    cout << "This is a 2 player game, so grab your opponent and let's get started!\n";
}

void tictactoe::printBoard(const char board[9])
{
    cout << "+---+---+---+\n" << "| " << board[0] << " | "
         << board[1] << " | " << board[2] << " |" << endl;
    cout << "+---+---+---+\n" << "| " << board[3] << " | "
         << board[4] << " | " << board[5] << " |" << endl;
    cout << "+---+---+---+\n" << "| " << board[6] << " | "
         << board[7] << " | " << board[8] << " |" << endl;
    cout << "+---+---+---+" << endl;
}

bool tictactoe::checkWinning(char board[9])
{
    if (board[0] == board[1] && board[1] == board[2])
        { 
        if (board[2] == 'o')
            cout << "Congrats Player2, you are the winner!" << endl;
        else
            cout << "Congrats Player1, you are the winner!" << endl;
        return true;
        }
    else if (board[3] == board[4] && board[4] == board[5])
        { 
        if (board[5] == 'o')
            cout << "Congrats Player2, you are the winner!" << endl;
        else
            cout << "Congrats Player1, you are the winner!" << endl;
        return true;
        }
    else if (board[6] == board[7] && board[7] == board[8])
        { 
        if (board[8] == 'o')
            cout << "Congrats Player2, you are the winner!" << endl;
        else
            cout << "Congrats Player1, you are the winner!" << endl;
        return true;
        }
    else if (board[0] == board[3] && board[3] == board[6])
        { 
        if (board[6] == 'o')
            cout << "Congrats Player2, you are the winner!" << endl;
        else
            cout << "Congrats Player1, you are the winner!" << endl;
        return true;
        }
    else if (board[1] == board[4] && board[4] == board[7])
        { 
        if (board[7] == 'o')
            cout << "Congrats Player2, you are the winner!" << endl;
        else
            cout << "Congrats Player1, you are the winner!" << endl;
        return true;
        }
    else if (board[2] == board[5] && board[5] == board[8])
        { 
        if (board[8] == 'o')
            cout << "Congrats Player2, you are the winner!" << endl;
        else
            cout << "Congrats Player1, you are the winner!" << endl;
        return true;
        }
    else if (board[0] == board[4] && board[4] == board[8])
        { 
        if (board[8] == 'o')
            cout << "Congrats Player2, you are the winner!" << endl;
        else
            cout << "Congrats Player1, you are the winner!" << endl;
        return true;
        }
    else if (board[2] == board[4] && board[4] == board[6])
        { 
        if (board[6] == 'o')
            cout << "Congrats Player2, you are the winner!" << endl;
        else
            cout << "Congrats Player1, you are the winner!" << endl;
        return true;
        }
    else if ((board[0]=='o'||board[0]=='x')&&(board[1]=='o'||board[1]=='x')&&(board[2]=='o'||board[2]=='x')&&(board[3]=='o'||board[3]=='x')&&(board[4]=='o'||board[4]=='x')&&(board[5]=='o'||board[5]=='x')&&(board[6]=='o'||board[6]=='x')&&(board[7]=='o'||board[7]=='x')&&(board[8]=='o'||board[8]=='x'))
        {
            cout << "Looks like we have a tie, better luck next time!" << endl;
            return true;
        }
    else 
        return false;
}
void tictactoe::playerMove(char board[9])
{
    int box;
    bool validMove;
    while (!checkWinning(board))
    {
        cout << "Player1, what box would you like to place you piece in?" << endl;
        cin >> box;
        do{
            if (box >= 9 || box <= -1 ) {
                cout << "Sorry that is not an option." << endl;
                validMove = false; }
            else if (board[box] == 'x' || board[box] == 'o'){
                cout << "Sorry that spots alread taken." << endl;
                validMove = false; }
            else {
                board[box] = 'x';
                validMove = true; }
        }while(validMove == false);
        
        printBoard(board);
        
        if (!checkWinning(board))
            {
            do
                {
                cout << "Player2, what box would you like to place you piece in?" << endl;
                cin >> box;
                if (box >= 9 || box <= -1 ) {
                    cout << "Sorry that is not an option." << endl;
                    validMove = false; }
                else if (board[box] == 'x' || board[box] == 'o'){
                    cout << "Sorry that spots alread taken." << endl;
                    validMove = false; }
                else
                    {
                    board[box] = 'o';
                    validMove = true;
                    }
                }while(validMove == false);
            }
        printBoard(board);
    }
}

