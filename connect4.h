using namespace std;

//Global Variables for connect 4
//Global Constants
const int SIZE_COL = 7; //number of columns on our game board
const int SIZE_ROW = 6; //number of rows on our game board
const char PLAYER1_AV = 'p'; //Player 1 avatar
const char PLAYER2_AV = 'm'; //Player 2 avatar


class connect4{
    public:
        void intro();
        void initBoard(char board[SIZE_ROW][SIZE_COL]);
        void printBoard(const char board[SIZE_ROW][SIZE_COL]);
        char firstMove();
        bool isValidMove(const char board[SIZE_ROW][SIZE_COL], int & row, const int col);
        void playerMove(char board[SIZE_ROW][SIZE_COL], int & playerRow, int & playerCol, const char avatar);
        bool checkVertical(char board[SIZE_ROW][SIZE_COL], const int currentRow, const int currentCol, const char avatar);
        bool checkHorizontal(char board[SIZE_ROW][SIZE_COL], const int currentRow, const int currentCol, const char avatar);
        bool checkDiagonal(char board[SIZE_ROW][SIZE_COL], const int currentRow, const int currentCol, const char avatar);
        bool winGame(char board[SIZE_ROW][SIZE_COL], const int currentRow, const int currentCol, const char avatar);
        bool keepPlaying();
        void switchPlayer(char & currAvatar);
};
