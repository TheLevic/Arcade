#include <iostream>
#include "connect4.h"
#include "tictactoe.h"
#include "Hangman.h"
#include "Checkers.h"
using namespace std;

const int QUIT = 6;

int main()
{
    int answer = 0;
    do { //loops entire arcade
    cout << "Welcome to the Classic Arcade by PF1GANG Studios!" << endl
         << "Which game would you like to play?" << endl
         << "1. Hangman" << endl
         << "2. Connect 4" << endl
         << "3. Tic-Tac-Toe" << endl
         << "4. Checkers" << endl
         << "5. Battleship" << endl
         << "6. I'm done playing" << endl;
         
    cin >> answer;
    
    switch (answer)
    {
        case 1: 
        {
            Hangman game;
            game.playGame(); //plays entire hangman game
            break;
        }
        case 2:
        {
            connect4 game; //initialize variables
            char board[SIZE_ROW][SIZE_COL];
            char avatar = ' ';

            bool connectFour = false; //false to play, true to not play
            int playerRow = SIZE_ROW-1; //find an empty location to play
            
            int playerCol = 0; //user input
            char winner;

            system("clear"); //clear the console area
            srand (time(NULL)); //seed random

            game.intro();
            game.initBoard(board); //populates board
            game.printBoard(board);
            avatar = game.firstMove(); //choose/set who goes first

            while(!connectFour) //actually plays game
            {
                game.playerMove(board, playerRow, playerCol, avatar); //player moves
                game.printBoard(board);
                
                connectFour = game.winGame(board, playerRow, playerCol, avatar); //checks for winner
                        
                    if (connectFour == true){ // changes bool if a win

                        winner = avatar; //winner's name = winner variable

                            if (winner == PLAYER1_AV){ //prints congrats
                                cout << "Congragulations Player1! You have won!" << endl;
                                }
                            if (winner == PLAYER2_AV){
                                cout << "Congragulations Player2! You have won!" << endl;
                                }
                           
                            if (game.keepPlaying() == true){ //do you want to play again
                                connectFour = false;
                                game.initBoard(board);
                                game.printBoard(board);
                                }
                        }
                    game.switchPlayer(avatar); //switch player
            }
            cout << "Thanks for playing, goodbye!" << endl;

        break;
        }
        case 3: 
        {
            char playAgain;
            bool anotherRound = true;
            do { //loops tictactoe game
                tictactoe game;
                char board[boardSize][boardSize];
                game.intro();
                game.getInput(board);
                game.printBoard(board);
                game.checkInputs(board);
                game.checkWinner(board);
                cout << "Would you like to play another round? Y or N\n";
                cin >> playAgain;
                playAgain = tolower(playAgain);
                if (playAgain == 'y')
                    anotherRound = true;
                else if (playAgain == 'n')
                    anotherRound = false;
                else {
                    cout << "Seems like you inputted something unexpected." << endl
                         << "We'll just send you back to the arcade!" << endl;
                     }
            }while (anotherRound == true);
        break;
        }
        case 4:
        {
            Checkers game;
            game.Play();
        }
        //case 5: cout << "Battleship"; break;
        case 6: 
        {
            cout << "It was nice seeing you, have a great day!"<< endl
            << "Goodbye" << endl;
            break;
        }
        default:
        {
            cout << "Error... Please input a proper integer 1-5" << endl;
            break;
        }
    }
    } while (answer != 6);
    
    return(0);
}