#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
int menu(void)
	{
		int choice;
		printf("-----------AUTOMATE--------\n""1. Charger l'automate depuis graph.dot\n""2. Lire l'automate\n");
		scanf("%d",&choice);
		return choice;
	}

void readDot(Automate protocol)
	{
		int src,dest,i = 0;
		char val;
	FILE* f;
	f = fopen("graph.dot","r");
	if(f == NULL)
		{
			printf("Fichier introuvable, veuillez vous assurez de l'emplacement du fichier.");
		}
	while( fscanf(f," %d -> %d [label=\"%c\"]",&src,&dest,&val ) == 3)
			{
				protocol.transitions[i].etat_dep = src;
				protocol.transitions[i].etat_arriv = dest;
				protocol.transitions[i].lettre = val;
				i++;
			}
	}
void automateShow(Automate protocol)
{
	printf("Voici l'etat initial : %d\n",protocol.etat_initial);

	printf("Voici la liste des etats : ");	
	for(int j = 0; j<10 ; j++)
	{
		printf("[%d] ",protocol.etats[j]);
	}

	printf("Voici la liste d'alphabet : ");	
	for(int k = 0; k<10 ; k++)
	{
		printf("[%c] ", protocol.Alphabet[k]);
	}

	printf("Voici la liste des transitions : ");	
	for(int i = 0; i<20 ; i++)
	{

		printf("[%d] -> %c -> [%d]\n",protocol.transitions[i].etat_dep,protocol.transitions[i].lettre,protocol.transitions[i].etat_arriv);
	}
	printf("l'etat finale est %d", protocol.etat_final);
}

