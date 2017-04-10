// SortAndConvert.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
//

#include "stdafx.h"
#include <stdlib.h>

void Start();
void DatenAufnahme();
void Sort();
void Ausgabe();

int Choice; //Fuer die Auswahl des Zifferntypes
int Zahlen[3]; //Array fuer die drei Zahlen
int Error = 0;

void welcome(){
	printf("\nHallo, dieses Programm ist fuer das Sortieren von drei eingebenen Zahlen.");
	printf("\nDie Zahlen koennen oktal, dezimal oder hexadezimal eingeben werden.\n");
}

int main()
{
	welcome();
	Start();
	return 0;
}


void Start(){
	int bla = 1;

		while (bla == 1)
		{
			printf("\n\nIn welchem Format wollen Sie Zahlen eingeben?\nOktal(1)? Dezimal(2)? oder Hexadezimal(3)? (0 zum beenden): ");
			scanf_s("%d", &Choice);
			switch (Choice)
			{
			case 1:
				//Oktal
				do
				{
					DatenAufnahme();
				} while (Error == 1);
				Sort();
				Ausgabe();
				break;
			case 2:
				//Dezimal
				do
				{
					DatenAufnahme();
				} while (Error == 1);
				Sort();
				Ausgabe();
				break;
			case 3:
				//Hex
				do
				{
					DatenAufnahme();
				} while (Error == 1);
				Sort();
				Ausgabe();
				break;
			case 0:
				printf("\n\nDas Programm wird nun beendet...\n\n");
				bla = 0;
				break;
			default:
				printf("\n1,2 oder 3 sind die einzig gueltigen Eingaben.\n");
				break;
			}
		}
}

void DatenAufnahme(){
	printf("\nBitte geben Sie Ihre drei Zahlen wie gewaehlt ein\n");
	if (Choice == 1){
		printf("(mit fuehrender '0' -> 010 fuer eine oktale 10) mit Komma getrennt: ");
		if (scanf_s("%o,%o,%o", Zahlen, Zahlen + 1, Zahlen + 2) == 3){
			Error = 0;
		}
		else {
			printf("\nEine oder alle Zahlen sind nicht oktal!\nBitte versuchen Sie es erneut!\n");
			Error = 1;
		}
	}
	else if (Choice == 2) {
		printf("(wie gewohnt) mit Kommas getrennt: ");
		if (scanf_s("%d,%d,%d", Zahlen, Zahlen + 1, Zahlen + 2) == 3){
			Error = 0;
		}
		else {
			printf("\nEine oder alle Zahlen sind nicht dezimal!\nBitte versuchen Sie es erneut!\n");
			Error = 1;
		}
	}
	else {
		printf("(beginnent mit '0x' -> 0x10 fuer eine hexadezimale 10) mit Komma getrennt: ");
		if (scanf_s("%x,%x,%x", Zahlen, Zahlen + 1, Zahlen + 2) == 3){
			Error = 0;
		}
		else {
			printf("\nEine oder alle Zahlen sind nicht hexadezimal!\nBitte versuchen Sie es erneut!\n");
			Error = 1;
		}
	}
}

int Wechsel (const void * Zahl1, const void * Zahl2)
	{
	   return  ( *(int*)Zahl1 - *(int*)Zahl2 );
	}

void Sort(){
	qsort(Zahlen, 3, sizeof(int), Wechsel);
}

void Ausgabe(){
	printf("\n\n#   Oktal    |   Dezimal   | Hexadezimal#\n");
	printf("-------------|-------------|-------------\n");
	printf(" %11o | %11d | %11x \n", Zahlen[0], Zahlen[0], Zahlen[0]);
	printf("             |             |            \n");
	printf(" %11o | %11d | %11x \n", Zahlen[1], Zahlen[1],Zahlen[1]);
	printf("             |             |            \n");
	printf(" %11o | %11d | %11x \n", Zahlen[2], Zahlen[2], Zahlen[2]);
	printf("             |             |            \n");
}
