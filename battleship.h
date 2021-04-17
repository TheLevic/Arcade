
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Battle
{
        public:
                Battle();
                ~Battle();
                void createboard();
                void printBoard();
                void placeShips();
                bool error(char ship1, int ship2, char VorH, int Size);
                void placement(char ship1, int ship2, char VorH, int Size);
                void getInput();
                void compareBoardtoInp(Battle player);

        private:
          static const int SIZE_COL = 10;
          static const int SIZE_ROW = 10;
          char board[SIZE_ROW][SIZE_COL];


};

