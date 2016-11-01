// 161101_DrawL1L3_mit_Deklaration.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

void drawl1l3(); //declare drawL1L3
void drawl3();	 //declare drawL3
void drawl1();	 //declare drawL1

void drawl1()		//define previously declared funktion
{
	printf("\n |\n |\n |\n\ |\n |\n\ |________\n\n");
}

void drawl3()		//define previously declared funktion
{
	printf("  ________\n |\n |\n |\n\ |\n |\n\ |\n\n");
}

int _tmain(int argc, _TCHAR* argv[])
{
	drawl1l3();
	return 0;
}

void drawl1l3()		//define previously declared funktion
{
	drawl1();
	drawl3();
}