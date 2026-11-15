#include <stdio.h>
#include <unistd.h>
#include "tic-tac-toe.h"

int main(void)
{
    char plateau[9];
    int choix;

    initialiser_plateau(plateau);

    while (1)
    {
        afficher_plateau(plateau);
        choix = demander_case(plateau);
        if (choix == -1)
            return 1;
        plateau[choix] = JOUEUR;

        if (a_gagne(plateau, JOUEUR))
        {
            afficher_plateau(plateau);
            printf("Vous avez gagne, bravo !\n");
            return 0;
        }
        if (plateau_plein(plateau))
        {
            afficher_plateau(plateau);
            printf("Match nul !\n");
            return 0;
        }

        afficher_plateau(plateau);
        printf("L'ordinateur joue...\n");
        sleep(1);
        choix = choisir_case_ordi(plateau);
        plateau[choix] = ORDI;

        if (a_gagne(plateau, ORDI))
        {
            afficher_plateau(plateau);
            printf("L'ordinateur a gagne !\n");
            return 0;
        }
        if (plateau_plein(plateau))
        {
            afficher_plateau(plateau);
            printf("Match nul !\n");
            return 0;
        }
    }
    return 0;
}
