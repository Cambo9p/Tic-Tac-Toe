#ifndef TIKTACTOE.h
#define TIKTACTOE.h

typedef struct {
    int slotNumber;
    char player;
} Move_t;

/* struct to determin the state of the game 
 */
typedef struct {
    char a;
    char b;
    char c

void printBoard(Move_t move);
void checkArgs(int argc, char *argv[]); 
int checkWin();

#endif // TIKTAKTOE.h
