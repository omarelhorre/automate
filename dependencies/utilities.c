#include "structs.h"
//fct fusion des etats a un seul etat initial et un seul etat final
void FusionneEtatsInitialsFinals(Automate *A) {
    int initial = 21;
    int final = 22;
    A->etats[A->nbr_etat++] = initial;
    A->etats[A->nbr_etat++] = final;

    //relier l'etat initial aux anciens états initiaux
    for (int i = 0; i < A->inic; i++) {
        ajouterOuMajTransition(A, initial, A->etat_initiaux[i], "E");
    }
    A->etat_initiaux[0] = initial;
    A->inic = 1;

    //relier les anciens états finaux au super-final
    for (int i = 0; i < A->finc; i++) {
        ajouterOuMajTransition(A, A->etat_finaux[i], final, "E");
    }
    A->etat_finaux[0] = final;
    A->finc = 1;
}
void fromAtoEps(Automate* result,Automate* a1)
{
    result->etat_finaux[0] = 200;
    result->finc = 1;

        for(int i = 0; i< a1->finc ; i++)
    {
        result->transitions[result->nbr_trans].etat_dep = a1->etat_finaux[i];
        result->transitions[result->nbr_trans].etat_arriv = 200;
        strcpy(result->transitions[result->nbr_trans].lettre, "E");
        result->nbr_trans++;
    }
}
void fromEpsToA(Automate* result,Automate* a1)
{
    result->etat_initiaux[0] = 100;
        result->inic = 1;
    for(int i = 0; i< a1->inic ; i++)
    {
        result->transitions[result->nbr_trans].etat_dep = 100;
        result->transitions[result->nbr_trans].etat_arriv = a1->etat_initiaux[i];
        strcpy(result->transitions[result->nbr_trans].lettre, "E");
        result->nbr_trans++;
    }

}
void changeState(Automate* auto1, Automate* auto2)
    {
        int current;
    for(int i = 0 ; i<auto1->nbr_etat ; i++)
    {
        current = auto1->etats[i];
        for(int j = 0 ; j<auto2->nbr_etat ; j++)
        {
            if(current == auto2->etats[j])
            {
                auto1->etats[i]-= auto1->nbr_etat;
                 for(int k = 0; k< auto1->nbr_trans ; k++ )
                        {
                            if(auto1->transitions[k].etat_dep == current)
                            auto1->transitions[k].etat_dep = auto1->etats[i];
                            if(auto1->transitions[k].etat_arriv == current)
                            auto1->transitions[k].etat_arriv = auto1->etats[i];
                        }
                 for(int l = 0 ; l<auto1->inic ; l++)

                 {
                     if(auto1->etat_initiaux[l] == current)
                     auto1->etat_initiaux[l] = auto1->etats[i];
                
                }

                for(int l = 0 ; l<auto1->finc ; l++)

                 {
                     if(auto1->etat_finaux[l] == current)
                     auto1->etat_finaux[l] = auto1->etats[i];
                
                     }
            }
        }


    }
}
void copy(Automate* auto1, Automate* result)
{
    for(int i= 0; i<auto1->inic ; i++)
    {
        result->etat_initiaux[result->inic++] = auto1->etat_initiaux[i] ;
        
    }

    for(int i= 0; i<auto1->finc ; i++)
    {
        result->etat_finaux[result->finc++] = auto1->etat_finaux[i] ;
    }


    for(int i= 0; i<auto1->nbr_trans ; i++)
    {
        result->transitions[result->nbr_trans++] = auto1->transitions[i];
    }
}
