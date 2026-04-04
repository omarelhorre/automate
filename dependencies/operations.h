#ifndef OPERATIONS_H
#define OPERATIONS_H
#include "structs.h"
Automate concatAutomates(Automate *A1, Automate *A2,Automate *C);

void UnionStructure(Automate* auto1, Automate* auto2, Automate* result);

void ajouterOuMajTransition(Automate *A, int dep, int arriv, const char *expr);
void supprimerEtat(Automate *A, int etat_supp);

void genererRegexDepuisAutomate(Automate *A, char *regex);
void obtenirExpression(Automate *A, int dep, int arriv, char *resultat);

void initPileAutomates(PileAutomates *p);
void pushAutomate(PileAutomates *p, Automate A);
Automate popAutomate(PileAutomates *p);
void initPileChar(PileChar *p);
void pushChar(PileChar *p, char c);
char popChar(PileChar *p);
char topChar(PileChar *p);
bool pileCharVide(PileChar *p);
int nouvelEtat();
void ajouterEtatSiAbsent(Automate *A, int e);
void ajouterAlphabetSiAbsent(Automate *A, char c);
void ajouterTransition(Automate *A, int dep, int arriv, char lettre);
Automate automateLettre(char lettre);
Automate concatAutomates(Automate *A1, Automate *A2, Automate *C);
Automate unionAutomates(Automate *A1, Automate *A2, Automate *C);
Automate etoileAutomate(Automate A);
Automate plusAutomate(Automate A);
void appliquerOperateur(PileAutomates *pileA, PileChar *pileC);
void construireAutomateThompson(const char *regex, Automate *A);
void supprimerEpsilons(Automate *A);
void supprimerEtatsInaccessibles(Automate *A);
void calculFermetureEpsilon(Automate *A, int etat, int *fermeture, int *taille);
//void convertirAFD(Automate *AFN, Automate *AFD);
#endif