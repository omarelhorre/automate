#include "structs.h"
#include <stdbool.h>
void MaxTransitions(Automate *protocol){

    int sorties[20] = {0};
    int entrees[20] = {0};
    int i,j;

    // compter les transitions POUR CHAQUE ETAT
    for(j = 0; j < protocol->nbr_trans; j++){

        for(i = 0; i < protocol->nbr_etat; i++){

            if(protocol->transitions[j].etat_dep == protocol->etats[i])
                sorties[i]++;

            if(protocol->transitions[j].etat_arriv == protocol->etats[i])
                entrees[i]++;
        }
    }

    int maxSort = 0, maxEntr = 0;

    for(i = 0; i < protocol->nbr_etat; i++){
        if(sorties[i] > maxSort)
            maxSort = sorties[i];

        if(entrees[i] > maxEntr)
            maxEntr = entrees[i];
    }

    printf("Etats avec max transitions sortantes (%d): ", maxSort);
    for(i = 0; i < protocol->nbr_etat; i++){
        if(sorties[i] == maxSort)
            printf("%d ", protocol->etats[i]);
    }

    printf("\nEtats avec max transitions entrantes (%d): ", maxEntr);
    for(i = 0; i < protocol->nbr_etat; i++){
        if(entrees[i] == maxEntr)
            printf("%d ", protocol->etats[i]);
    }

    printf("\n");
}
void afficherEtatsAvecTransition(Automate *protocol, char lettre) {

    printf("Transitions etiquetees par '%c' :\n", lettre);
    bool found  =false;
    for (int i = 0; i < protocol->nbr_etat; i++) {

        bool aTransition = false;

        for (int j = 0; j < protocol->nbr_trans; j++) {

            if (protocol->transitions[j].etat_dep == protocol->etats[i] &&
                protocol->transitions[j].lettre[0] == lettre) {

                if (!aTransition) {
                    printf("Etat [%d] -> ", protocol->etats[i]);
                    aTransition = true;
                    found = true;
                }
                printf("[%d] ", protocol->transitions[j].etat_arriv);
            }
        }
        if (aTransition) {
            printf("\n");
        }
    }
    if (!found) {
            printf("n'existe pas\n");
        }
}