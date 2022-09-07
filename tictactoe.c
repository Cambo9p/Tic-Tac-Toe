#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "tictactoe.h"

char board[10] = {'0','1','2','3','4','5','6','7','8','9'};
char playerChar;

/* A simple tic tac toe game in c 
 */
int main(int argc, char *argv[]) {

    // check the commandline arguments 
    checkArgs(argc, argv);

    playerChar = (argv[1] == 0) ? 'X' : 'O';
    printBoard();
    playerMove();
    printBoard();

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

/*
int enemyMove()
{
}
*/


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

/*
int checkWin()
{
}
*/
    

