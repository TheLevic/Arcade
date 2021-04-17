#include <iostream>
#include "connect4.h"

using namespace std;

int main()
{
    int answer = 0;
    
    cout << "Welcome to the Classic Arcade by PF1GANG Studios!" << endl
         << "Which game would you like to play?" << endl
         << "1. Hangman" << endl
         << "2. Connect 4" << endl
         << "3. Tic-Tac-Toe" << endl
         << "4. Checkers" << endl
         << "5. Battleship" << endl;
    cin >> answer;
    
    while (answer != 1 && answer != 2 && answer != 3 && answer != 4 && answer != 5)
    {
        cout << "Error... Please input a proper integer 1-5" << endl
             << "1. Hangman" << endl
             << "2. Connect 4" << endl
             << "3. Tic-Tac-Toe" << endl
             << "4. Checkers" << endl
             << "5. Battleship" << endl;
        cin >> answer;
    }
    
    switch (answer)
    {
        case 1: cout << "Hangman"; break;
        case 2:
        {
            //Initialize Variables
            connect4 game;
            char board[SIZE_ROW][SIZE_COL];
            char avatar = ' ';

            //False when wanting to play, true when won/not wanting to play
            bool connectFour = false;

            //start at the bottom of the row and work upwards to find an empty location to play
            int playerRow = SIZE_ROW-1;
            //this will be user input
            int playerCol = 0;
            char winner;

            //clear the console area and seed the random number generator appropriately
            system("clear");
            srand (time(NULL));

            //print out directions
            game.intro();

            //populate Board
            game.initBoard(board);

            //Print Board
            game.printBoard(board);

            //Choose who goes first by calling a function that will set the avatar to the appropriate character
            avatar = game.firstMove();

            //loop the game to play
            while(!connectFour)
            {
                        //call the function that handles the player's moves
                        game.playerMove(board, playerRow, playerCol, avatar);

                        //print the board again
                        game.printBoard(board);

                        //check to see if is a winning combo
                        connectFour = game.winGame(board, playerRow, playerCol, avatar);


                                    //if there is a win, change connectFour variable
                                    if (connectFour == true){

                            
                            
                                                //Assign winner's name to winner variable
                                                winner = avatar;

                                                //...and print out a celebratory statement!
                                                if (winner == PLAYER1_AV){
                                                            cout << "Congragulations Player1! You have won!" << endl;
                                                }
                                                if (winner == PLAYER2_AV){
                                                            cout << "Congragulations Player2! You have won!" << endl;
                                                }


                                                //check if players want to continue playing
                                                //if yes, reset and print board, and reset the connectFour variable to false
                                                if (game.keepPlaying() == true){
                                                            connectFour = false;
                                                            game.initBoard(board);
                                                            game.printBoard(board);
                                                }
                                    }
                        //Call function to switch player avatars
                        game.switchPlayer(avatar);
            }
            cout << "Thanks for playing, goodbye!" << endl;

        break;
        }
        case 3: cout << "Tic-Tac-Toe"; break;
        case 4: cout << "Checkers"; break;
        case 5: cout << "Battleship"; break;
    }
    
    return(0);
}
