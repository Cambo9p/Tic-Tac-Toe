#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#include "tictactoe.h"

char board[10] = {'0','1','2','3','4','5','6','7','8','9'};
char playerChar;

/* A simple tic tac toe game in c 
 */
int main(int argc, char *argv[]) {

    // check the commandline arguments 
    checkArgs(argc, argv);
    int res; // used to store the results from checkWin() 

    playerChar = (argv[1] == 0) ? 'X' : 'O';
    printBoard();

    playerMove();
    res = checkWin();
    printf("Res result is %d\n", res);
    printBoard();
    playerMove();
    res = checkWin();
    printf("Res result is %d\n", res);
    printBoard();
    playerMove();
    res = checkWin();
    printf("Res result is %d\n", res);
     

    return 0;
}


/* Checks the validity of the command line arguments 
 */
void checkArgs(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Incorrect number of arguments");
        exit(0);
    }
    if ((*argv[1] > 1) & (*argv[1] < 0)) {
        printf("Incorrect argument");
        exit(0);
    }
}


void enterMove(Move_t *move)
{
    board[move -> slotNumber] = move -> player;
}


/* Function to allow a player to choose a move and add move to board
 */
void playerMove()
{
    Move_t *move = malloc(1*sizeof(Move_t));
    printf("Enter a slot to move to\n");
    scanf("%d", &move->slotNumber); 
    move-> player = playerChar; 
    enterMove(move);
    free(move);
}


/* makes a random enemy move 
 */
void enemyMove()
{
    printf("enemy is playing\n");
    int r = rand() % 10;

    bool isValid = false;

    while (!isValid) {
        if (isalpha(board[r]) == 1) {
            r = rand() % 10; 
        } else {
            isValid = true;
        }
    }

    Move_t *move = malloc(1*sizeof(Move_t));
    printf("%d\n",r);
    move -> slotNumber = r;
    move -> player = playerChar == 'X' ? 'O' : 'X';
    enterMove(move);
    free(move);
}


/* Prints the Game board once the player has moved 
 */
void printBoard()
{
    printf("    |    |    \n");
    printf(" %c  | %c  | %c \n", board[0], board[1], board[2]);
    printf("    |    |    \n");
    printf("----|----|----\n");
    printf("    |    |    \n");
    printf(" %c  | %c  | %c \n", board[3], board[4], board[5]);
    printf("    |    |    \n");
    printf("----|----|----\n");
    printf("    |    |    \n");
    printf(" %c  | %c  | %c \n", board[6], board[7], board[8]);
    printf("    |    |    \n");
}


/* Checks to see if the game is won 
 * returns 0 if the game is still going, 1 if the player has won, 2 if the
 * enemy has won, 3 if its a draw
 */
int checkWin()
{
    // check horizontal 
    int i = 0;
    while (i < 6) { 
        if ((board[i] == board[i+1]) & (board[i] == board[i+2])) {
            return (board[i] == playerChar) ? 1 : 2;
        }
        i+=3;
    }

    // check vertical 
    i = 0;
    while (i < 4) {
        if ((board[i] == board[i+3]) & (board[i] == board[i+6])) {
            return (board[i] == playerChar) ? 1 : 2;
        }
        i+=1;
    }

    // check horiz 
    if ((board[0] == board[4]) & (board[0] == board[8])) {
            return (board[0] == playerChar) ? 1 : 2;
    } else if ((board[2] == board[4]) & (board[2] == board[6])) { 
            return (board[2] == playerChar) ? 1 : 2;
    }

    // check draw -- when all of the squares are used 
    bool isDraw = true;
    i = 0;
    while ((isDraw == true) & ( i < 10)) {
        if (isalpha(board[i]) == 0) { // number 
            isDraw = false;
        }
        i++;
    }
    return 0; 
}
    

