#ifndef LECTUREETAFFICHAGE_H
#define LECTUREETAFFICHAGE_H
#include "structs.h"
void automateShow(Automate protocol);
void readDot(Automate *protocol,char *fichier);
void sauvgarder(Automate a,const char* str);
#endif