#include<stdio.h>
#include<stdlib.h>

typedef struct Etat{
    int id;
    int etat_final;
}Etat;
typedef struct Transition{
    int etat_dep;
    int etat_arriv;
    char lettre;
}Transition;
typedef struct Automate{
    Etat etats[10];
    Transition transitions[20];
    char Alphabet[10];
    int etat_initial;
}Automate;
