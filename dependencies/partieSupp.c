#include <stdio.h>
#include <stdlib.h>
#include "optimisation.h"
#include "lectureEtAffichage.h"
#include "operations.h"
#include "utilities.h"
#include "verification.h"
#include "structs.h"
#include "creeTableSymbole.h"
void determinerMots(const char* nomFichier)
{
    Automate* auto1 = malloc(sizeof(Automate));
    Automate* autoDet = malloc(sizeof(Automate));
    Automate* autoMin = malloc(sizeof(Automate));
    initAutomate(autoDet);
    initAutomate(autoMin);
    initAutomate(auto1);
    FILE* fptr = fopen(nomFichier, "r");
    checkFile(fptr);
    char* buffer = malloc(sizeof(char) * 200);
    fgets(buffer,200, fptr);
    printf("Lecture de l'expression reguliere est faite avec succes: %s \n",buffer);
    construireAutomateThompson(buffer, auto1);
    trois(auto1);
    creerTableSymboles(autoMin, nomFichier);
    free(auto1);
    free(autoDet);
    free(autoMin);
    free(buffer);
}