#include "structs.h"
#include <stdbool.h>
void initAutomate(Automate* a1);
void recopieEtats(Automate *A, int Etats[], int taille);
void recopieEtatsInitiale(Automate *A, int Etats[], int taille);
void recopieEtatsFinaux(Automate *A, int Etats[], int taille);
void recopieTransition(Automate *A, Transition trans[], int taille);
bool rechercherAlphabet(Automate *protocol, char etatChar);
bool rechercherEtatFinale(Automate *protocol, int etatChar);
bool transitionExiste(Transition *tab, int nbr, int dep, int arriv, char lettre);