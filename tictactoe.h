#ifndef TIKTACTOE.h
#define TIKTACTOE.h

typedef struct {
    int slotNumber;
    char player;
} Move_t;

void printBoard(Move_t move);
void checkArgs(int argc, char *argv[]); 

#endif // TIKTAKTOE.h
