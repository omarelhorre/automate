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
	FILE* f;
	fptr = fopen("graph.dot","r");
	if(fptr == NULL)
		{
			printf("Fichier introuvable, veuillez vous assurez de l'emplacement du fichier.");
		}i
	while( fscanf(f," %d -> %d [label=\"%c\"]",&src,&dest,&val ) == 3)
			{
				protocol.transition[i].etat_dep = src;
				protocol.transition[î].etat_arrive = dest;
				protocol.tranisition[i].lettre = val;
			}
	}
void automateShow(Automate protocol)
{
	for(int i = 0; i<20 ; i++)
	{

		printf("%d -> %c -> %d",protocol.transition[i].etat_dep,protocol.transition[i].lettre,protocol.transition[i].etat_arrive);
	}
}

