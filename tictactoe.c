#include <stdio.h>
#include <stdint.h>

#include "tiktaktoe.h"

char board[10] = {'0','1','2','3','4','5','6','7','8','9'};

/* A simple tic tac toe game in c 
 */
int main(int argc, char *argv[]) {

    // check the commandline arguments 
    checkArgs(argc, &argv);

    playerChar = (argv[1] == 0) ? 'X' : 'O';

}


/* Checks the validity of the command line arguments 
 */
void checkArgs(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Incorrect number of arguments");
        exit(0);
    }
    if (argv[1] > ! || argv[1] < 0) {
        printf("Incorrect argument");
        exit(0)
    }
}


/* Prints the Game board once the player has moved 
 */
void printBoard(Move_t move)
{
    printf("    |    |    \n");
    printf(" %c | %c | %c \n", board[], board[1], board[2]);
    printf("    |    |    \n");
    printf("----|----|----\n");
    printf("    |    |    \n");
    printf(" %c | %c | %c \n", board[3], board[4], board[5]);
    printf("    |    |    \n");
    printf("----|----|----\n");
    printf("    |    |    \n");
    printf(" %c | %c | %c \n", board[6], board[7], board[8]);
    printf("    |    |    \n");
}

int checkWin()
{
}
    

