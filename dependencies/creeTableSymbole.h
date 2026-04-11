#include "structs.h"
// Structure pour une entrée dans la table des symboles
typedef struct {
    char mot[100];
    int numero_ligne;
} EntreeTableSymboles;
// Structure pour la table des symboles
typedef struct {
    EntreeTableSymboles entrees[500];
    int nbr_entrees;
} TableSymboles;
TableSymboles creerTableSymboles(Automate *A, const char *nom_fichier) ;
void afficherTableSymboles(TableSymboles *table) ;