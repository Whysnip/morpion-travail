#include <stdio.h>
#include "tic-tac-toe.h"

static void clear_input(void)
{
    int c;

    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int ask_player_move(const char board[BOARD_SIZE])
{
    int pos;
    int ret;

    while (1)
    {
        printf("En quelle case voulez-vous jouer (0-8) ? ");
        ret = scanf("%d", &pos);
        if (ret == EOF)
            return -1;
        if (ret != 1)
        {
            clear_input();
            printf("Entree invalide : tapez un nombre entre 0 et 8.\n");
            continue;
        }
        clear_input();
        if (pos < 0 || pos >= BOARD_SIZE)
            printf("Cette case n'existe pas : choisissez entre 0 et 8.\n");
        else if (board[pos] != EMPTY)
            printf("Cette case est deja prise, choisissez-en une autre.\n");
        else
            return pos;
    }
}

int computer_move(const char board[BOARD_SIZE])
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        if (board[i] == EMPTY)
            return i;
    }
    return -1;
}

int has_won(const char board[BOARD_SIZE], char symbol)
{
    
    for (int i = 0; i < 3; i++)
    {
        if (board[i * 3] == symbol && board[i * 3 + 1] == symbol
            && board[i * 3 + 2] == symbol)
            return 1;
        if (board[i] == symbol && board[i + 3] == symbol
            && board[i + 6] == symbol)
            return 1;
    }
    
    if (board[0] == symbol && board[4] == symbol && board[8] == symbol)
        return 1;
    if (board[2] == symbol && board[4] == symbol && board[6] == symbol)
        return 1;
    return 0;
}