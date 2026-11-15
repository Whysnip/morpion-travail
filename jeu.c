#include <stdio.h>
#include "tic-tac-toe.h"

static void vider_buffer(void)
{
    int c;

    c = getchar();
    while (c != '\n' && c != EOF)
        c = getchar();
}

int demander_case(char plateau[9])
{
    int choix;
    int resultat;

    while (1)
    {
        printf("Quelle case ? (0 a 8) : ");
        resultat = scanf("%d", &choix);
        if (resultat == EOF)
            return -1;
        vider_buffer();
        if (resultat != 1)
            printf("Il faut taper un nombre.\n");
        else if (choix < 0 || choix > 8)
            printf("La case doit etre entre 0 et 8.\n");
        else if (plateau[choix] != VIDE)
            printf("Cette case est deja prise.\n");
        else
            return choix;
    }
}

int choisir_case_ordi(char plateau[9])
{
    int i;

    for (i = 0; i < 9; i++)
    {
        if (plateau[i] == VIDE)
            return i;
    }
    return -1;
}

int a_gagne(char plateau[9], char symbole)
{
    int combinaisons[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };
    int i;

    for (i = 0; i < 8; i++)
    {
        if (plateau[combinaisons[i][0]] == symbole
            && plateau[combinaisons[i][1]] == symbole
            && plateau[combinaisons[i][2]] == symbole)
            return 1;
    }
    return 0;
}
