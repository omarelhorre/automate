#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct Transition{
    char etat_dep;
    char etat_arriv;
    char lettre;
}Transition;

typedef struct Automate{
    char etats[10];
	int nbr_etat;
    Transition transitions[20];
	int nbr_trans;
    char Alphabet[8];
	int nbr_alph;
    char etat_initiaux[5];
	int inic;//nbr des etats initial
    char etat_finaux[5];
	int finc;//nbr des etats finaux
}Automate;

bool rechercherEtat(Automate *protocol, char etatChar){
	for(int i = 0 ; i<= protocol->nbr_etat;i++){
		if(protocol->etats[i] == etatChar ){
			return true;
		}
	}
	return false;
}

bool rechercherAlphabet(Automate *protocol, char etatChar){
	for(int i = 0 ; i<= protocol->nbr_alph;i++){
		if(protocol->Alphabet[i] == etatChar ){
			return true;
		}
	}
	return false;
}

void readDot(Automate *protocol,char *fichier){
	int i=0,inic,finc;
	char src,dest,val,ligne[100], buff[20];
	protocol->nbr_etat = 0;
    protocol->nbr_trans = 0;
    protocol->nbr_alph = 0;
	protocol->inic=0;
	protocol->finc=0;
	FILE* f = fopen(fichier,"r");
	if(f == NULL){
		printf("Fichier introuvable, veuillez vous assurez de l'emplacement du fichier.");
	}
	while(fgets(ligne, sizeof(ligne), f)){
	    if(sscanf(ligne," %c -> %c [label=\"%c\"];",&src,&dest,&val) == 3){
		//stockage des transitions
			protocol->transitions[i].etat_dep = src;
			protocol->transitions[i].etat_arriv = dest;
			protocol->transitions[i].lettre = val;
			i++;
		//stockage des etats
		    if(protocol->nbr_etat < 10){
			    if(rechercherEtat(protocol, src) == false){
					protocol->etats[protocol->nbr_etat] = src;
					protocol->nbr_etat++;
			    }
			    else if(rechercherEtat(protocol, dest) == false){
					protocol->etats[protocol->nbr_etat] = dest;
					protocol->nbr_etat++;
			    }
            }
		//stockage des alphabets
		    if(protocol->nbr_alph < 8){
			    if(rechercherAlphabet(protocol, val) == false){
					protocol->Alphabet[protocol->nbr_alph] = val;
					protocol->nbr_alph++;
			    }
            }
	    }
    //stockage des etats initiaux et finaux
	    else if(sscanf(ligne," init -> %c;", &src) == 1){
			protocol->etat_initiaux[protocol->inic] = src;	
			protocol->inic++;
	    }
        else if(sscanf(ligne," %c -> %[^;];", &src,buff) == 2){
		    if (strcmp(buff,"fin") != 0)
                continue ;
		    protocol->etat_finaux[protocol->finc] = src;
		    protocol->finc++;
	    }
	    else continue;
	}
	protocol->nbr_trans = i;
	fclose(f);
}

void automateShow(Automate protocol){
	int i;
	printf("Voici la liste des etats :\n");	
	for( i = 0; i< protocol.nbr_etat ; i++){
		printf("[%c] ",protocol.etats[i]);
	}
	printf("\nVoici la liste d'alphabet : \n");	
	for(i = 0; i< protocol.nbr_alph ; i++){
		printf("[%c] ", protocol.Alphabet[i]);
	}
	printf("\nVoici la liste des transitions :\n");	
	for( i = 0; i< protocol.nbr_trans ; i++){
		printf("[%c] -> %c -> [%c]\n",protocol.transitions[i].etat_dep,protocol.transitions[i].lettre,protocol.transitions[i].etat_arriv);
	}
	printf("\nVoici la liste des etats initiaux :\n");	
	for( i = 0; i< protocol.inic ; i++){
		printf("[%c] ",protocol.etat_initiaux[i]);
	}
	printf("\nVoici la liste des etats finaux :\n");	
	for( i = 0; i< protocol.finc ; i++){
		printf("[%c] ",protocol.etat_finaux[i]);
	}
    printf("\n");
}
void MaxTransitions(Automate *protocol){
    int maxSort = 0, maxEntr = 0;
    char etatMaxSort, etatMaxEntr;
    int i ,j;
    for(i= 0; i < protocol->nbr_etat; i++){
        int nbSorties = 0;
        int nbEntrees = 0;
        for( j = 0; j < protocol->nbr_trans; j++){
            if(protocol->transitions[j].etat_dep == protocol->etats[i]){
                nbSorties++;
            }
            if(protocol->transitions[j].etat_arriv == protocol->etats[i]){
                nbEntrees++;
            }
        }

        if(nbSorties > maxSort){
            maxSort = nbSorties;
            etatMaxSort = protocol->etats[i];
        }
        if(nbEntrees > maxEntr){
            maxEntr = nbEntrees;
            etatMaxEntr = protocol->etats[i];
        }
    }
    printf("Etat avec max transitions sortantes : %c (%d)\n", etatMaxSort, maxSort);
    printf("Etat avec max transitions entrantes : %c (%d)\n", etatMaxEntr, maxEntr);
}
void afficherEtatsAvecTransition(Automate *A, char lettre) {
    bool existe = false;
    printf("Transitions etiquetees par '%c' :\n", lettre);
    for (int i = 0; i < A->nbr_etat; i++) {
        for (int j = 0; j < A->nbr_trans; j++) {
            if (A->transitions[j].etat_dep == A->etats[i] && A->transitions[j].lettre == lettre){
                if (!existe){
                    printf("Etat [%c] -> ", A->etats[i]);
                    existe = true;
                }
                printf("[%c] ", A->transitions[j].etat_arriv);
            }
        }
    }
    if(!existe){
        printf("N'existe pas.\n");
    }
}
void sauvgarder(Automate a){
    int i;
    FILE *f = fopen("automate_utilisateur.dot", "w");
    if(f == NULL) {
        printf("erreur lors la creation du fichier\n");
        return;
    }
    fprintf(f, "digraph G {\n");
    fprintf(f, "init [shape=point];\n");
    for( i = 0; i < a.inic; i++){
         fprintf(f, "init -> %c;\n", a.etat_initiaux[i]);
    }
    for(i = 0; i < a.nbr_trans; i++){
        fprintf(f, "%c -> %c [label=\"%c\"];\n",a.transitions[i].etat_dep,a.transitions[i].etat_arriv,a.transitions[i].lettre);
    }
    for(i = 0; i < a.finc; i++){
        fprintf(f, "%c -> fin;\n", a.etat_finaux[i]);
    }
    fprintf(f, "}\n");
    fclose(f);
    printf("Fichier 'automate_utilisateur.dot' genere avec succes.\n");
}
/*
void SaveAcceptedWords(Automate *A){
	char mot[10];
	FILE *ftxt = fopen("fichier.txt","r"), *fptr = fopen("MotsAccepter.txt","w");
	if (ftxt == NULL || fptr == NULL){
		printf("Fichier introuvable, veuillez vous assurez de l'emplacement du fichier.");
		return;
	}
	while( fscanf(ftxt,"%s",mot) == 1){
		if(estAccepter(&A,mot) == true){
		 	fprintf(fptr,"%s \n",mot);
		}
	}
}*/
int menu(void){
		int choice;
		printf("\n-----------AUTOMATE--------\n");
        printf("1.Lire l'automate depuis graph.dot .  \n2.Afficher les informations de l'automate.  \n");
        printf("3.Generer un fichier.dot .  \n4.Afficher l'etat avec le plus grand nombre des transitions.  \n");
        printf("5.Afficher les etat avec transition etiquete .  \n6.Tester un mot  \n7.extraire Mots accepter ds un fichier.\n");
        printf("0.Quitter le programme.  \nentrer votre choix: ");
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
                break; }
            case 2 : {
                automateShow(a); 
                break;}
            case 3 :{
                int x;
                printf("pour generer depuis une autre automate entrer 1. \npour generer depuis l'ancienne automate entrer 2.\nvotre choix: ");
                do{
                    scanf("%d",&x);
                    if(x!=1 && x!=2)
                        printf("choix invalide,veuillez ressayez: \n");
                }while(x!=1 && x!=2);
                if( x == 1){
                    //generer();
                    //sauvgarder();
                }
                else{
                    sauvgarder(a);break;
                }}
            case 4 : {
                MaxTransitions(&a);break;}
            case 5 : {
                char c;
                printf("entrer la lettre : ");
                scanf(" %c",&c);
                afficherEtatsAvecTransition(&a,c);
                break;
            }
            case 6 :{
                char mot[20];
                printf("entrer le mot a tester : ");
                scanf(" %s",mot);
                //estAccepter(a,mot);
                break;
            }
            case 7 : {
                //saveAcceptedMot(&a);
                break;
            }
            case 0 : printf("Fin du programme\n"); break;
            default : printf("Entrer un choix valide s'il vous plait!\n");
        }
	}while(output !=0);
	return 0;
}