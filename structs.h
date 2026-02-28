#include<stdio.h>
#include<stdlib.h>
typedef struct Transition{
    int etat_dep;
    int etat_arriv;
    char lettre;
}Transition;
typedef struct Automate{
    int etats[10];
    Transition transitions[20];
    char Alphabet[10];
    int etat_initial;
    int etat_final;
}Automate;

