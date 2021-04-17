using namespace std;

//Global constants
const int boardSize = 3;

class tictactoe{
    public:
        void intro();
        void getInput(char board[boardSize][boardSize]);
        void printBoard(const char board[boardSize][boardSize]);
        void checkInputs(char board[boardSize][boardSize]);
        void checkWinner(char board[boardSize][boardSize]);
        
};