#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#define VIDE ' '
#define JOUEUR 'X'
#define ORDI 'O'

void initialiser_plateau(char plateau[9]);
void afficher_plateau(char plateau[9]);
int demander_case(char plateau[9]);
int choisir_case_ordi(char plateau[9]);
int a_gagne(char plateau[9], char symbole);
int plateau_plein(char plateau[9]);

#endif
