#include "Checkers.h"

Checkers::Checkers()
{
    
    board[0] = "b - b - b - b -";
    board[1] = "- b - b - b - b";
    board[2] = "b - b - b - b -";
    board[3] = "- - - - - - - -";
    board[4] = "- - - - - - - -";
    board[5] = "- r - r - r - r";
    board[6] = "r - r - r - r -";
    board[7] = "- r - r - r - r";
    
    player = 1;
}

Checkers::~Checkers()
{
}

void Checkers::Play()
{
    bool keepPlaying = true;
    while (keepPlaying)
    {
        cout << "  0 1 2 3 4 5 6 7" << endl;
        for (int i = 0; i < 8; i++)
        {
            cout << i << " ";
            cout << board[i] << endl;
        }
        int row;
        int column;
        int direction;
        bool check;
        cout << "Player " << player << ", select which piece to move: type in row then column." << endl;
        cin >> row >> column;
        cout << "Press 1 to move up to the left, 2 to move up to the right, 3 to move down to the left, 4 to move down to the right." << endl;
        cin >> direction;
        check = isValidMove(row, column, direction);
        if (check)
        {
            Move(row, column, direction);
        }
        else 
        {
            while (!check)
            {
                cout << "Invalid move. Try again." << endl;
                cout << "Select which piece to move: type in row then column." << endl;
                cin >> row >> column;
                cout << "Press 1 to move up to the left, 2 to move up to the right, 3 to move down to the left, 4 to move down to the right." << endl;
                cin >> direction;
                check = isValidMove(row, column, direction);
            }
            Move(row, column, direction);
        }
        changeTurn();
        keepPlaying = Winner();
    }
    
    if (player == 1)
    {
        cout << "Congratulations Player 1! You are the winner!" << endl;
    }
    else
    {
        cout << "Congratulations Player 2! You are the winner!" << endl;
    }
    
}

void Checkers::changeTurn()
{
    if (player == 1)
    {
        player = 2;
    }
    
    else if (player == 2)
    {
        player = 1;
    }
}

bool Checkers::isValidMove(int &row, int &column, int &direction)
{
    column *= 2;
    if (player == 1)
    {
        if ((row > 7)||(row < 0)||(column > 14)||(column < 0))
        {
            return false;
        }
        else if (board[row].at(column) == 'R')
        {
            if (direction == 1)
            {
                if ((board[row-1].at(column-2) == '-')||(board[row-1].at(column-2) == 'b')||(board[row-1].at(column-2) == 'B'))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else if (direction == 2)
            {
                if ((board[row-1].at(column+2) == '-')||(board[row-1].at(column+2) == 'b')||(board[row-1].at(column+2) == 'B'))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else if (direction == 3)
            {
                if ((board[row+1].at(column-2) == '-')||(board[row+1].at(column-2) == 'b')||(board[row+1].at(column-2) == 'B'))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else if (direction == 4)
            {
                if ((board[row+1].at(column+2) == '-')||(board[row+1].at(column+2) == 'b')||(board[row+1].at(column+2) == 'B'))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else 
            {
                return false;
            }
        }
        else if (board[row].at(column) == 'r')
        {
            if (direction == 1)
            {
                if ((board[row-1].at(column-2) == '-')||(board[row-1].at(column-2) == 'b')||(board[row-1].at(column-2) == 'B'))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else if (direction == 2)
            {
                if ((board[row-1].at(column+2) == '-')||(board[row-1].at(column+2) == 'b')||(board[row-1].at(column+2) == 'B'))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else 
        {
            return false;
        }
    }
    
    else if (player == 2)
    {
        if ((row > 7)||(row < 0)||(column > 14)||(column < 0))
        {
            return false;
        }
        else if (board[row].at(column) == 'B')
        {
            if (direction == 1)
            {
                if ((board[row-1].at(column-2) == '-')||(board[row-1].at(column-2) == 'r')||(board[row-1].at(column-2) == 'R'))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else if (direction == 2)
            {
                if ((board[row-1].at(column+2) == '-')||(board[row-1].at(column+2) == 'r')||(board[row-1].at(column+2) == 'R'))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else if (direction == 3)
            {
                if ((board[row+1].at(column-2) == '-')||(board[row+1].at(column-2) == 'r')||(board[row+1].at(column-2) == 'R'))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else if (direction == 4)
            {
                if ((board[row+1].at(column+2) == '-')||(board[row+1].at(column+2) == 'r')||(board[row+1].at(column+2) == 'R'))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else 
            {
                return false;
            }
        }
        else if (board[row].at(column) == 'b')
        {
            if (direction == 3)
            {
                if ((board[row+1].at(column-2) == '-')||(board[row+1].at(column-2) == 'r')||(board[row+1].at(column-2) == 'R'))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else if (direction == 4)
            {
                if ((board[row+1].at(column+2) == '-')||(board[row+1].at(column+2) == 'r')||(board[row+1].at(column+2) == 'R'))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
        else 
        {
            return false;
        }
    }
}

void Checkers::Move(int &row, int &column, int &direction)
{
    
       if (direction == 1)
        {
            if (player == 1)
            {
            if (row-1 == 0)
            {
                board[row-1].at(column-2) = 'R';
            }
            else if ((board[row-1].at(column-2) == 'b')||(board[row-1].at(column-2) == 'B'))
            {
                board[row-2].at(column-4) = board[row].at(column);
                board[row-1].at(column-2) = '-';
                board[row].at(column) = '-';
            }
            else 
            {
                board[row-1].at(column-2) = board[row].at(column);
                board[row].at(column) = '-'; 
            }
            }
            else if (player == 2)
            {
                if ((board[row-1].at(column-2) == 'r')||(board[row-1].at(column-2) == 'R'))
                {
                    board[row-2].at(column-4) = board[row].at(column);
                    board[row-1].at(column-2) = '-';
                    board[row].at(column) = '-';
                }
                else 
                {
                    board[row-1].at(column-2) = board[row].at(column);
                    board[row].at(column) = '-'; 
                }
            }
        }
        else if (direction == 2)
        {
            if (player == 1)
            {
                if (row-1 == 0)
                {
                    board[row-1].at(column+2) = 'R';
                }
                else if ((board[row-1].at(column+2) == 'b')||(board[row-1].at(column+2) == 'B'))
                {
                    board[row-2].at(column+4) = board[row].at(column);
                    board[row-1].at(column+2) = '-';
                    board[row].at(column) = '-';
                }
                else 
                {
                    board[row-1].at(column+2) = board[row].at(column);
                    board[row].at(column) = '-'; 
                }
            }
            else if (player == 2)
            {
                if ((board[row-1].at(column+2) == 'r')||(board[row-1].at(column-2) == 'R'))
                {
                    board[row-2].at(column+4) = board[row].at(column);
                    board[row-1].at(column+2) = '-';
                    board[row].at(column) = '-';
                }
                else 
                {
                board[row-1].at(column+2) = board[row].at(column);
                board[row].at(column) = '-'; 
                }
            }
        }
        else if (direction == 3)
        {
            if (player == 1)
            {
                if ((board[row+1].at(column-2) == 'b')||(board[row+1].at(column-2) == 'B'))
                {
                    board[row+2].at(column-4) = board[row].at(column);
                    board[row+1].at(column-2) = '-';
                    board[row].at(column) = '-';
                }
                else 
                {
                    board[row+1].at(column-2) = board[row].at(column);
                    board[row].at(column) = '-'; 
                }
            }
            else if (player == 2)
            {
                if (row+1 == 7)
                {
                    board[row+1].at(column-2) = 'B';
                }
                else if ((board[row+1].at(column-2) == 'r')||(board[row-1].at(column-2) == 'R'))
                {
                    board[row+2].at(column-4) = board[row].at(column);
                    board[row+1].at(column-2) = '-';
                    board[row].at(column) = '-';
                }
                else 
                {
                    board[row+1].at(column-2) = board[row].at(column);
                    board[row].at(column) = '-'; 
                }
            }
        }
        else if (direction == 4)
        {
            if (player == 1)
            {
                if ((board[row+1].at(column+2) == 'b')||(board[row+1].at(column+2) == 'B'))
                {
                    board[row+2].at(column+4) = board[row].at(column);
                    board[row+1].at(column+2) = '-';
                    board[row].at(column) = '-';
                }
                else 
                {
                    board[row+1].at(column+2) = board[row].at(column);
                    board[row].at(column) = '-'; 
                }
            }
            else if (player == 2)
            {
                
                if (row+1 == 7)
                {
                    board[row+1].at(column+2) = 'B';
                }
                else if ((board[row+1].at(column+2) == 'r')||(board[row+1].at(column+2) == 'R'))
                {
                    board[row+2].at(column+4) = board[row].at(column);
                    board[row+1].at(column+2) = '-';
                    board[row].at(column) = '-';
                }
                else 
                {
                    board[row+1].at(column+2) = board[row].at(column);
                    board[row].at(column) = '-'; 
                }
            }
        } 
        
    
    
}

bool Checkers::Winner()
{
    int totalRed = 0;
    int totalBlack = 0;
    int j = 0;
    for (int i = 0; i < 8; i++)
    {
        if ((board[i].at(j) == 'r')||(board[i].at(j) == 'R'))
        {
            totalRed++;
        }
        else if ((board[i].at(j) == 'b')||(board[i].at(j) == 'B'))
        {
            totalBlack++;
        }
        j +=2;
    }
    if (totalBlack == 0)
    {
        player = 1;
        return false;
    }
    else if (totalRed == 0)
    {
        player = 2;
        return false;
    }
    else 
    {
        return true;
    }
}




