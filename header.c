#include <stdio.h>
#include <stdlib.h>

int menu(void)
	{
		int choice;
		printf("-----------AUTOMATE--------\n""1. Charger l'automate depuis graph.dot\n""2. Lire l'automate\n");
		scanf("%d",&choice);
		return choice;
	}

/*
#define MAX 20
int A[MAX][MAX];
char val[MAX][MAX];
void initMatrices(int A[MAX][MAX], char val[MAX][MAX])
	{
		for(int i = 0; i<20 ; i++)
		{
			for(int j = 0 ; j<20 ; j++)
			{
				A[i][j] = 0;
				val[i][j] = '';
			}
		}
	}
void fillMatrices(int A[MAX][MAX], char val[MAX][MAX])
	{
		int u,v;
		printf("Entrer le nombres d'alphabets dans votre mots");
		int alphabets;
		scanf("%d",alphabets);
		initMatrices(A,val);
		for(int i =0; i<alphabets ; i++)
			{
				scanf("%d,%d",u,v);
				A[u][v] = 1;
			}
	}

void readDot(int A[MAX][MAX], val[MAX][MAX])
	{
	FILE* f;
	fptr = fopen("graph.dot","r");
	if(fptr == NULL)
		{
			printf("Fichier introuvable, veuillez vous assurez de l'emplacement du fichier.");
		}
	initMatrices(A,val);
	fscanf(f, "%s");
	while( fscanf(f," %c -> %c [label=\"%d\"]",&src,&dest,&val ) == 3)
			{
				A[src][dest] = 1;
				val[i][j] = label;
			}
	}
*/ 
