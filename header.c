#include <stdio.h>
#include <stdlib.h>
#define A[20][20]
void readDot(void)
	{
	FILE* f;
	fptr = fopen("graph.dot","r");
	if(fptr == NULL)
		{
			printf("File not opened, please check if your graph.dot file exists in this 					directory");
		}
	fscanf(file, "
	while( fscanf(f," %c -> %c [label=\"%d\"]",&src,&dest,&val)
	}
