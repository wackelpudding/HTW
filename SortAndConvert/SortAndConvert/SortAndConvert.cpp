// SortAndConvert.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
//

#include "stdio.h"
#include <stdlib.h>

void Start();
void DatenAufnahme();
void Sort();
void Ausgabe();

int Choice; //Fuer die Auswahl des Zifferntypes
int Zahlen[3]; //Array fuer die drei Zahlen

int main()
{
	//welcome();
	Start();
	return 0;
}

/*
    		Tabelle

	printf("\n\n # Messwert | Messung 1 | Messung 2 | Mittelwert\n");
	printf("------------|-----------|-----------|-----------\n");
	printf("     1      | %9.2lf | %9.2lf | %9.2lf \n", M1_M1, M1_M2, M1_Mw);
	printf("            |           |           |            \n");
	printf("     2      | %9.2lf | %9.2lf | %9.2lf \n", M2_M1, M2_M2, M2_Mw);
	printf("            |           |           |            \n");

 */

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
				DatenAufnahme();
				break;
			case 2:
				//Dezimal
				DatenAufnahme();
				break;
			case 3:
				//Hex
				DatenAufnahme();
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
		scanf_s("%o,%o,%o", Zahlen,Zahlen+1,Zahlen+2);
	} else if (Choice == 2) {
		scanf_s("%d,%d,%d", Zahlen,Zahlen+1,Zahlen+2);
	} else {
		printf("(beginnent mit '0x' -> 0x10 fuer eine hexadezimale 10) mit Komma getrennt: ");
		scanf_s("%x,%x,%x", Zahlen,Zahlen+1,Zahlen+2);
	}

	Sort();
	Ausgabe();

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
