#include <stdio.h>
#include <stdlib.h>
#include "tic-tac-toe.h"

void init_board(char board[BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
        board[i] = EMPTY;
}

void display_board(const char board[BOARD_SIZE])
{
    system("clear");
    printf("\n  === TIC-TAC-TOE ===\n\n");
    printf("  Vous : %c    Ordinateur : %c\n\n", PLAYER_SYMBOL, COMPUTER_SYMBOL);
    for (int row = 0; row < 3; row++)
    {
        printf("     %c | %c | %c        %d | %d | %d\n",
               board[row * 3], board[row * 3 + 1], board[row * 3 + 2],
               row * 3, row * 3 + 1, row * 3 + 2);
        if (row < 2)
            printf("    ---+---+---      ---+---+---\n");
    }
    printf("\n");
}

int is_full(const char board[BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i] == EMPTY)
            return 0;
    }
    return 1;
}