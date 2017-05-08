// swap.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
//

#include "stdafx.h"

void welcome();
void choice();
void PartOne();
void swap(int* , int*);
void BubbleSort(int*);
void DatenAufnahme();
void Ausgabe();

int z1, z2;
int Zahlen[5]; //Array fuer die 5 Zahlen

int main()
{
	choice();
}

void swap(int* z1, int* z2) {

	int temp;

	temp = *z1;
	*z1 = *z2;
	*z2 = temp;
}

void welcome()
{
	printf("\nHallo, diese Programm ist fuer das Sortieren via BubbleSort und erwartet 5 Zahlen zur eingabe\n");
}

void BubbleSort(int *a) {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (a[j] > a[j + 1]){
				swap(&a[j],&a[(j+1)]);
			}
		}
	}
}

void DatenAufnahme() {
	int Error = 0;
	do
	{
		printf("\nBitte geben Sie Ihre 5 Zahlen mit Komma getrennt ein: ");
		if (scanf_s("%d,%d,%d,%d,%d", Zahlen, Zahlen + 1, Zahlen + 2, Zahlen + 3, Zahlen + 4) == 5) {
			Error = 0;
			//Ausgabe(Zahlen);
		}
			else {
				printf("\nBitte geben Sie genau 5 Zahlen ein!\nBitte versuchen Sie es erneut!\n");
				Error = 1;
			}
	} while (Error == 1);
}



void choice() //Auswahl zwischen Teil1 v Teil2 v Teil3
{
	int Choice;
	int bla = 1;

	welcome();

	while (bla == 1)
	{
		printf("\n\nBitte druecken Sie '1' (Enter) und geben Sie danach 5 Zahlen zum sortieren ein (0 zum Beenden): ");
		scanf_s("%d", &Choice);
		switch (Choice)
		{
		case 1:
			PartOne();
			break;

		case 0:
			bla = 0;
			break;
		default:
			printf("\n1 ist die einzig gueltigen Eingaben.\n");
			break;
		}
	}


}

void Ausgabe(int array[]) {
	for (int i = 0; i < 5; i++) {
		printf("\n%d", array[i]);
	}
}

void PartOne() {
	welcome();
	DatenAufnahme();
	printf("\n");
	BubbleSort(Zahlen);
	Ausgabe(Zahlen);
}
