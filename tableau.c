#include <stdio.h>
#include <stdlib.h>
#include "tic-tac-toe.h"

void initialiser_plateau(char plateau[9])
{
    int i;

    for (i = 0; i < 9; i++)
        plateau[i] = VIDE;
}

void afficher_plateau(char plateau[9])
{
    system("clear");
    printf("\n");
    printf("  %c | %c | %c       0 | 1 | 2\n", plateau[0], plateau[1], plateau[2]);
    printf(" ---+---+---     ---+---+---\n");
    printf("  %c | %c | %c       3 | 4 | 5\n", plateau[3], plateau[4], plateau[5]);
    printf(" ---+---+---     ---+---+---\n");
    printf("  %c | %c | %c       6 | 7 | 8\n", plateau[6], plateau[7], plateau[8]);
    printf("\n");
}

int plateau_plein(char plateau[9])
{
    int i;

    for (i = 0; i < 9; i++)
    {
        if (plateau[i] == VIDE)
            return 0;
    }
    return 1;
}
