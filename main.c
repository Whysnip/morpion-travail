#include <stdio.h>
#include <unistd.h>
#include "tic-tac-toe.h"

int main(void)
{
    char board[BOARD_SIZE];
    int pos;

    init_board(board);
    while (1)
    {
        
        display_board(board);
        pos = ask_player_move(board);
        if (pos == -1)
            return 1;
        board[pos] = PLAYER_SYMBOL;
        if (has_won(board, PLAYER_SYMBOL))
        {
            display_board(board);
            printf("Bravo, vous avez gagne !\n");
            return 0;
        }
        if (is_full(board))
            break;

        
        display_board(board);
        printf("L'ordinateur reflechit...\n");
        sleep(1);
        pos = computer_move(board);
        board[pos] = COMPUTER_SYMBOL;
        if (has_won(board, COMPUTER_SYMBOL))
        {
            display_board(board);
            printf("L'ordinateur a gagne... Dommage !\n");
            return 0;
        }
        if (is_full(board))
            break;
    }
    display_board(board);
    printf("Match nul !\n");
    return 0;
}