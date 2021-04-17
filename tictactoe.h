using namespace std;

class tictactoe{
    public:
        void intro();
        void printBoard(const char board[9]);
        bool checkWinning(char board[9]);
        void playerMove(char board[9]);
        
};