#include <stdio.h>
#include <stdlib.h>
#include "header.h"
extern Automate protocol;
// main.c
int main(){
	int output;
	do{
	output = menu();
	switch(output){
		case 1 : {
			readDot();
			printf("\n");
			break; }
		case 2 : {
			 automateShow(); 
			printf("\n");
			 break;}
		case 3 : printf("Fin du programme\n"); break;
		default : printf("Entrer un choix valide s'il vous plait!\n");
	}
	}while(output !=3);
	return 0;
}
