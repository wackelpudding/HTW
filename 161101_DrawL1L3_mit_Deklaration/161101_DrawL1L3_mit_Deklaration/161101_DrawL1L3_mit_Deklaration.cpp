// 161101_DrawL1L3_mit_Deklaration.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
//

#include "stdafx.h"


void drawl1()
{
	printf("\n |\n |\n |\n\ |\n |\n\ |________\n\n");
}

void drawl3()
{
	printf("  ________\n |\n |\n |\n\ |\n |\n\ |\n\n");
}

void drawl1l3()
{
	drawl1();
	drawl3();
}

int _tmain(int argc, _TCHAR* argv[])
{
	drawl1l3();
	return 0;
}

