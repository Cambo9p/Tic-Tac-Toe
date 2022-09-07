#ifndef TIKTACTOE_h
#define TIKTACTOE_h

typedef struct {
    int slotNumber;
    char player;
} Move_t;

void enterMove(Move_t *move);
void playerMove();
void enemyMove();
void printBoard();
void checkArgs(int argc, char *argv[]); 
int checkWin();

#endif // TIKTAKTOE.h
