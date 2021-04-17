#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include "/home/thelevic/code/Arcade/battleship.h"
using namespace std;


//---------------------------------------------------------------------------
// Name: Battle
// Parameters: none
// Returns: none
// Purpose: Constructor.
//---------------------------------------------------------------------------
Battle::Battle()
{
}
//---------------------------------------------------------------------------
// Name: Battle
// Parameters: none
// Returns: none
// Purpose: Destructor.
//---------------------------------------------------------------------------

Battle::~Battle()
{
}

//----------------------------------------------------------------
// Name:        createboard
// Parameters:  none
// Returns:     none
// Purpose:     Initialize the board with 'o' characters
//----------------------------------------------------------------
void Battle::createboard()
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
//----------------------------------------------------------------
// Name:        printBoard
// Parameters:  none
// Returns:     none
// Purpose:     Prints the current board to the screen
//----------------------------------------------------------------
void Battle::printBoard()
{
    char c = 'a';
    cout << "           BATTLESHIPS \n      ";
    for(int i = 0; i < SIZE_COL; i++)
        cout << i << "  ";
    cout << endl;

    for(int row = 0; row < SIZE_ROW; row++)
    {
        cout << setw(3) << c  << " | ";
        for(int col = 0; col < SIZE_COL; col++)
        {
           cout << board[row][col] << "  ";
        }
        cout << "|" << endl;
        c = c + 1;
   }
}

//----------------------------------------------------------------
// Name:        placeShips
// Parameters:  none
// Returns:     none
// Purpose:     Allows the user to put their ships on the board
//----------------------------------------------------------------
void Battle::placeShips()
{
        char carrier1;
        int carrier2;
        int carrierSize = 5;
        char VorH;

        cout << endl << "Where would you like to place your Aircaft Carrier ship?" << endl;
        cout << "This ship is 5 long. " << endl;

cout << "                           _" << endl;
cout << "                              (_)" << endl;
cout << "               --""-------   0/      ^^" << endl;
cout << "     .___.....// //__| |__/\\ /\\_/H__,      ^^"<< endl;
cout << "      \\                             /" << endl;
cout << "    #####^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~" << endl;

        cout << endl << "Would you like to place this ship horizontally or vertically?" << endl;
        cout << "Please enter a \'h\' for horizontally and a \'v\' for vertically." << endl;
        cin >> VorH;
        VorH = tolower(VorH);
        while(VorH != 'v' &&  VorH != 'h'){
                cout <<  "Please enter a \'h\' for horizontally and a \'v\' for vertically.";
                cin >> VorH;
                VorH = tolower(VorH);
        }

        //error checking
        cout <<  "Please enter a space from A0 to J9:" << endl;
        cin >> carrier1 >> carrier2;
        carrier1 = tolower(carrier1);

        while (error(carrier1, carrier2, VorH, carrierSize) != true){
                cout << endl << "Please enter a space from A0 to J9:" << endl;
                cin >> carrier1 >> carrier2;
                carrier1 = tolower(carrier1);
                error(carrier1, carrier2, VorH, carrierSize);
        }

        placement(carrier1, carrier2, VorH, carrierSize);
}
//----------------------------------------------------------------
// Name:        placement
// Parameters:  the letter and the number for a ship
// Returns:     none
// Purpose:     placing ships on board.  The switch statment is looking to see what letter the user put and if they want to put the ship vertically or horizontally and then creating a for loop that adds X's to that area.
//----------------------------------------------------------------
void Battle::placement(const char ship1,const int ship2,const char VorH,const int Size)
{
int i;
switch(ship1){
                case 'a':
                        if(VorH == 'v'){
                                for(i=0; i < Size; i++){
                                        cout << "ZZZZZZZZZZZZZZZZZZZZZZZZZZZ" << endl;   //this is testing to see if the program is reaching this loop
                                        board[i][0] = 'X'; // FIX - this is not   chaning the board
                                                          
                                        board[i][0+ship2] = 'X';
                                }
                        }
                        
                        if(VorH == 'v'){
                                for(i=0; i < Size; i++){
                                        board[i][1+ship2] = 'X';
                                }
                        }
                        else{
                                for(i=0; i < Size; i++){
                                        board[1][i+ship2] = 'X';
                                }

                        }
                        break;
                case 'c':
                         if(VorH == 'v'){
                                for(i=0; i < Size; i++){
                                        board[i][2+ship2] = 'X';
                                }
                        }
                        else{
                                for(i=0; i < Size; i++){
                                        board[2][i+ship2] = 'X';
                                }

                        }
                        break;
                case 'd':
                          if(VorH == 'v'){
                                for(i=0; i < Size; i++){
                                        board[i][3+ship2] = 'X';
                                }
                        }
                        else{
                                for(i=0; i < Size; i++){
                                        board[3][i+ship2] = 'X';
                                }

                        }
                        break;
                case 'e':
                           if(VorH == 'v'){
                                for(i=0; i < Size; i++){
                                        board[i][4+ship2] = 'X';
                                }
                        }
                        else{
                                for(i=0; i < Size; i++){
                                        board[4][i+ship2] = 'X';
                                }

                        }
                        break;
                case 'f':
                           if(VorH == 'v'){
                                for(i=0; i < Size; i++){
                                        board[i][5+ship2] = 'X';
                                }
                        }
                        else{
                                for(i=0; i < Size; i++){
                                        board[5][i+ship2] = 'X';
                                        
                                }
                        }
                        break;
                case 'g':         
                        if(VorH == 'v'){
                                for(i=0; i < Size; i++){
                                        board[i][6+ship2] = 'X';
                                }
                        }
                        else{
                                for(i=0; i < Size; i++){
                                        board[6][i+ship2] = 'X';
                                        
                                }
                        }
                        break;
                case 'h':
                        if(VorH == 'v'){
                                for(i=0; i < Size; i++){
                                        board[i][7+ship2] = 'X';
                                }
                        }
                        else{
                                for(i=0; i < Size; i++){
                                        board[7][i+ship2] = 'X';
                                }

                        }
                        break;
                case 'i':
                        if(VorH == 'v'){
                                for(i=0; i < Size; i++){
                                        board[i][8+ship2] = 'X';
                                }
                        }
                        else{
                                for(i=0; i < Size; i++){
                                        board[8][i+ship2] = 'X';
                                }

                        }
                        break;
                case 'j':
                        if(VorH == 'v'){
                                for(i=0; i < Size; i++){
                                        board[i][9+ship2] = 'X';
                                }
                        }
                        else{
                                for(i=0; i < Size; i++){
                                        board[9][i+ship2] = 'X';
                                }

                        }
                        break;


        }
printBoard();
}


//----------------------------------------------------------------
// Name:        error
// Parameters:  the letter and the number for a ship
// Returns:     true or false
// Purpose:     Error checking for placeShips
//----------------------------------------------------------------
bool Battle::error(char ship1, int ship2, char VorH, int Size)
{
        bool TorF = false;

        if(ship1 >= 'a' &&  ship1 <= 'j'){
           if (ship2 >= 0 && ship2 <= 9){
                TorF = true;
           }
        }

        if(VorH == 'h'){
                switch(Size){
                        case 1:
                                break;
                        case 2:
                                if(ship2 == 9){
                                        cout << "That is not a valid move." << endl;
                                        TorF = false;
                                }
                                break;
                        case 3:
                                if(ship2 >= 8){
                                        cout << "That is not a valid move." << endl;
                                        TorF = false;
                                }
                                break;
                        case 4:
                                if(ship2 >= 7){
                                        cout << "That is not a valid move." << endl;
                                        TorF = false;
                                }
                                break;
                        case 5:
                                if(ship2 >= 6){
                                        cout << "That is not a valid move." << endl;
                                        TorF = false;
                                }
                                break;

                }

        }

        if(VorH == 'v'){
                switch(Size){
                        case 1:
                                break;
                        case 2:
                                if(ship1 >= 'j'){
                                        cout << "That is not a valid move." << endl;
                                        TorF = false;
                                }
                                break;
                        case 3:
                                if(ship1 >= 'i'){
                                        cout << "That is not a valid move." << endl;
                                        TorF = false;
                                }
                                break;
                        case 4:
                                if(ship1 >= 'h'){
                                        cout << "That is not a valid move." << endl;
                                        TorF = false;
                                }
                                break;
                        case 5:
                                if(ship1 >= 'g'){
                                        cout << "That is not a valid move." << endl;
                                        TorF = false;
                                }
                                break;

                }


        }


return TorF;
}

//