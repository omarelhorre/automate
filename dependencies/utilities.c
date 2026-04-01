#include "structs.h"
#include <stdbool.h>
void initAutomate(Automate* a1)
{
    a1->finc = 0;
    a1->inic = 0;
    a1->nbr_alph = 0;
    a1->nbr_etat = 0;
    a1->nbr_trans = 0;
    //fonction copie des valeurs
}
void recopieEtats(Automate *A, int Etats[], int taille){
    for(int i =0;i<taille; i++){
        A->etats[i]= Etats[i];
    }
    A->nbr_etat = taille;
}
void recopieEtatsInitiale(Automate *A, int Etats[], int taille){
    for(int i =0;i<taille; i++){
        A->etat_initiaux[i]= Etats[i];
    }
    A->inic = taille;
}
void recopieEtatsFinaux(Automate *A, int Etats[], int taille){
    for(int i =0;i<taille; i++){
        A->etat_finaux[i]= Etats[i];
    }
    A->finc = taille;
}
void recopieTransition(Automate *A, Transition trans[], int taille){
    for(int i =0;i<taille; i++){
        // A->transitions[i].etat_dep= trans[i].etat_dep;
        // A->transitions[i].etat_arriv= trans[i].etat_arriv;
        // strncpy(A->transitions[i].lettre,trans[i].lettre,sizeof(trans[i].lettre));
        A->transitions[i]=trans[i];
    }
    A->nbr_trans = taille;
}
bool rechercherEtat(Automate *protocol, int etatChar){
	for(int i = 0 ; i< protocol->nbr_etat;i++){
		if(protocol->etats[i] == etatChar ){
			return true;
		}
	}
	return false;
}

bool rechercherAlphabet(Automate *protocol, char etatChar){
	for(int i = 0 ; i< protocol->nbr_alph;i++){
		if(protocol->Alphabet[i] == etatChar ){
			return true;
		}
	}
	return false;
}
bool rechercherEtatFinale(Automate *protocol, int etatChar){
	for(int i = 0 ; i< protocol->finc; i++){
		if(protocol->etat_finaux[i] == etatChar ){
			return true;
		}
	}
		return false;

}
//fct verifier qu'un transition n'existe deja dans le tableau des transition
bool transitionExiste(Transition *tab, int nbr, int dep, int arriv, char lettre) {
    for (int i = 0; i < nbr; i++) {
        if (tab[i].etat_dep == dep && tab[i].etat_arriv == arriv && tab[i].lettre[0] == lettre) {
            return true;
        }
    }
    return false;
}