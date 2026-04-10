#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "dependencies/structs.h"
#include "dependencies/verification.h"
#include "dependencies/lectureEtAffichage.h"
#include "dependencies/utilities.h"
#include "dependencies/manipulation.h"
#include "dependencies/operations.h"
#include "dependencies/optimisation.h"
#include "dependencies/partieSupp.h"
int menu(void){
		int choice;
        printf("\n-----------AUTOMATE--------\n");
        printf("1. Lire l'automate depuis demo.dot .  \n2. Afficher l'automate.  \n");
        printf("3. Generer un fichier.dot dans \"automate_utilisateur.dot\"  .  \n4. Afficher l'etat avec le plus grand nombre des transitions(sortantes, entrantes).  \n");
        printf("5. Afficher les etats avec transition etiquete à partir d'une lettre entré par l'utilisateur .  \n6. Tester un mot si il appartient au langage engendré  \n7. extraire tous les mots accepter dans un fichier.\n");
        printf("8. supprimer les epsilons transitions dans la structure automate.\n");
        printf("9. union de 2 automates.\n");
        printf("10. Generer un automate a partir d'une expression reguliere.\n");
        printf("11. Concatenation de 2 automates.\n");
        printf("12. Generer une expression reguliere a partir d'un automate.\n");
        printf("13. determinisation de l'automate\n");
        printf("14. Generer automate minimaliste.\n");
        printf("15. Produit de deux automates.\n");       
        printf("16. Mots engendre par un automate.\n");
        printf("17. Generer les trois fichiers de la structure a (automate initial, deterministe, minimaliste).\n");
        printf("18. Generer automate d'une reg exp canonique, thompson, deterministe et generer la table ");
        printf("0. Quitter le programme.\nEffectuer un choix: ");
        scanf("%d",&choice);
		return choice;
}

int main(){
	Automate a;  
	int output;
	do{
	    output = menu();
	    switch(output){
            case 1 : {
                readDot(&a,"demo.dot");
                printf("lecture du fichier avec succes.\n");
                break; 
            }
            case 2 : {
                automateShow(a);
                break;}
            case 3 :{
                sauvgarder(a,"automate_utilisateur.dot");
                break;
                }
            case 4 : {
                MaxTransitions(&a);
                break;}
            case 5 : {
                char c;
                printf("entrer la lettre : ");
                scanf(" %c",&c);
                afficherEtatsAvecTransition(&a,c);
                break;
            }
            case 6 :{
                char mot[20];
                printf("Entrer le mot a lire: ");
                scanf("%s",mot);
                while(getchar() != '\n');
                if(testerMot(&a,mot))
                {
                    printf("Le mot est accepte.\n");
                }
                else {
                    printf("Le mot n'est pas accepte.\n");
                }
                break;
            }
            case 7 : {
                SaveAcceptedWords(&a);
                printf("Les mots acceptes ont ete enregistres dans le fichier MotsAccepter.txt\n");
                break;
            }
            case 8 : {
                supprimerEpsilons(&a);
                supprimerEtatsInaccessibles(&a);
                automateShow(a);
                break;
            }
            case 9:{

                Automate* a4 = malloc(sizeof(Automate));
                Automate* a3 = malloc(sizeof(Automate)) ;
                Automate* resultant = malloc(sizeof(Automate));
                initAutomate(resultant);
                initAutomate(a3);
                initAutomate(a4);              
                readDot(a4,"src/automate1.dot");
                readDot(a3,"src/automate2.dot");
                UnionStructure(a3,a4,resultant);
                a = *resultant;
                printf("Union faite avec succes\n");
                sauvgarder(a,"src/resultat.dot");
                free(a3);
                free(a4);
                free(resultant);
                break;
            }
            
            case 10: {
                Automate* regexA = malloc(sizeof(Automate));
                char regex[100]; 
                printf("Veuillez entrer votre expression reguliere (sans espaces) : ");
                scanf(" %s", regex); 
                initAutomate(regexA);
                printf("\nConstruction de l'automate pour l'expression : %s\n", regex);
                construireAutomateThompson(regex, regexA);
                automateShow(*regexA);
                a = *regexA;
                free(regexA);
                break;
            }
            case 11: {
                Automate a1, a2;
                readDot(&a1, "src/automate1.dot");
                readDot(&a2, "src/automate2.dot");
                if(a1.nbr_etat == 0 || a2.nbr_etat == 0){
                    printf("Erreur : un des automates est vide ou mal charge !\n");
                    break;
                }
                a = concatAutomates(&a1,&a2,&a);
                automateShow(a);
                break;
            }
            case 12:{
                if(a.nbr_trans == 0){
                    printf("Erreur : l'automate est vide ou mal charge !\n");
                    break;
                }
                char regex[200] = "";
                Automate d = a;
                genererRegexDepuisAutomate(&d, regex);
                printf("voici l'expression reguliere du l'automate:\n");
                printf("%s\n\n", regex);
                break;
            }
            case 13:{
                Automate D;
                printf("Automate determinise :\n");
                determiniserAutomate(&a,&D);
                automateShow(D);
                a = D;
                break;
            }
            case 14:{
                Automate M;
                initAutomate(&M);
                M = minimiserMoore(&a);
                printf("Automate minimaliste :\n");
                automateShow(M);
                a = M;
                break;
            }
            case 17:{
            if(a.nbr_etat == 0){
                    printf("Erreur : l'automate est vide ou mal charge !\n");
                    break;
                }
            trois(&a);
            break;
            }
            case 16:{
                printf("Minimisation de l'automate...\n");
                const char *nomFichier = "mots_reconnus.txt";
                ecrireMotsAutomateMinimal(&a, nomFichier);
                break;
            }
            case 15:
            {
                printf("Produit de deux automates...\n");   
                Automate* A1 = malloc(sizeof(Automate));
                Automate* A2 = malloc(sizeof(Automate));
                Automate* C = malloc(sizeof(Automate));
                readDot(A1,"src/automate1.dot");
                readDot(A2,"src/automate2.dot");
                produitAutomates(A1,A2,C);
                if(C->finc == 0)
                representerEnsembleVide("src/resultat.dot");
                else{
                sauvgarder(*C,"src/resultat.dot");
                a = *C;}
                break;
            }
            case 18:
            {
                determinerMots("test/fichier.txt");
                break;
            }
            case 0 : printf("Fin du programme\n"); break;
            default : printf("Entrer un choix valide s'il vous plait!\n");
        }
	}while(output !=0);
	return 0;
}