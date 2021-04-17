#include <iostream>
#include <string>
#include <stdio.h>
#include <iomanip>

using namespace std;

class Checkers
{
    public:
    
        Checkers();
        ~Checkers();
        void Play();
        void changeTurn();
        bool isValidMove(int &row, int &column, int &direction);
        void Move(int &row, int &column, int &direction);
        bool Winner();
        
    private:
    
        string board[8];
        int player;
};

