#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include <stdbool.h>
Automate protocol;
int lengthEt = 0,lengthAlp = 0,inic=0,finc=0, nbTransition = 0;
int menu(void){
		int choice;
		printf("-----------AUTOMATE--------\n""1. Charger l'automate depuis graph.dot\n""2. Lire l'automate\n""3. EXIT\n");
		scanf("%d",&choice);
		return choice;
	}
bool rechercherEtat(char etatChar)
{
	int i ;
	for(i = 0 ; i<10;i++)
	{
		if(protocol.etats[i] == etatChar )
		{
			return true;
		}
	}
		return false;

}
bool rechercherAlphabet(char etatChar)
{
	int i ;
	for(i = 0 ; i<5;i++)
	{
		if(protocol.Alphabet[i] == etatChar )
		{
			return true;
		}
	}
		return false;

}

void readDot(){
		char src,dest,val,ligne[100];
	FILE* f;
	f = fopen("demo.dot","r");
	if(f == NULL){
			printf("Fichier introuvable, veuillez vous assurez de l'emplacement du fichier.");
			exit(EXIT_FAILURE);
	}
	while(fgets(ligne, sizeof(ligne), f))
	{
	if(sscanf(ligne," %c -> %c [label=\"%c\"];",&src,&dest,&val) == 3)			{
				protocol.transitions[nbTransition].etat_dep = src;
				protocol.transitions[nbTransition].etat_arriv = dest;
				protocol.transitions[nbTransition].lettre = val;
				nbTransition++;
				
				if(lengthEt < 10){
				if(rechercherEtat(src) == false)
				{
					protocol.etats[lengthEt] = src;
					lengthEt++;
				}
				if(rechercherEtat(dest) == false)
				{
					protocol.etats[lengthEt] = dest;
					lengthEt++;
				}
				}
				//alphabet

				if(lengthAlp < 5){
				if(rechercherAlphabet(val) == false)
				{
					protocol.Alphabet[lengthAlp] = val;
					lengthAlp++;
				}
				}

				
				
			}
	else if(sscanf(ligne," init -> %c;", &src) == 1)
			{

			 protocol.etat_initial[inic] = src;	
			 inic++;
			}
	else if(sscanf(ligne," %c -> fin;", &src) == 1)
			{

			 protocol.etat_final[finc] = src;
			 finc++;
			}
	else continue;



		}
			fclose(f);
	}
void automateShow(){
	int i,j,k;
	printf("Voici la liste des etats :");	
	for( j = 0; j<lengthEt ; j++){
		printf("[%c] ",protocol.etats[j]);
	}
	printf("\nVoici la liste d'alphabet : ");	
	for(k = 0; k<lengthAlp; k++){
		printf("[%c] ", protocol.Alphabet[k]);
	}
	printf("\nVoici la liste des transitions :");	
	for( i = 0; i<nbTransition ; i++){
		printf("[%c] -> %c -> [%c]\n",protocol.transitions[i].etat_dep,protocol.transitions[i].lettre,protocol.transitions[i].etat_arriv);
	}
	printf("\nvoici la liste des etats initiaux : ");
	for(int p = 0; p<inic; p++)
	{
		printf("[%c]",protocol.etat_initial[p]);
	}
	printf("\nvoici la liste des etats finaux : ");
	for(int l = 0; l<finc; l++)
	{
		printf("[%c]",protocol.etat_final[l]);
	}
}
