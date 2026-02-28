#include <stdio.h>
#include <stdlib.h>
#include "header.h"
Automate automate;
// main.c
int main()
{
	int output = menu();
	switch(output)
	{
		case 1 : readDot(automate);
		case 2 : automate(automate);
	}
	return 0;
}
