// SearchOfSorted.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
//

#include "stdafx.h"

//Funktionsdeklarationen
void welcome();
void choice();
int SearchOfSorted(int[], int, int ,int);
void DatenAufnahme();
int pivot(int, int);

//globale Variablendeklaration
int SortedListe[14] = { 10,17,23,24,31,32,37,43,46,51,68,69,78,83 };
int laenge = 13;
int zahl;


int main()
{
	welcome();
	choice();
	
	return 0;
}

//Eine simple Funktion, die die Basisfunktionalität des Programms wiedergibt.
void welcome() {
	printf("\nGuten Tag dieses Programm ist fuer das Durchsuchen einer sortieren Liste.\n");
}



/*	Die Choice() Funktion hat mehrere Funktionszwecke.
* 1: entschlackung der main, funktion
* 2: Bereitstellung einer simplen "Menuefuehrung" mit Hilfe eines Switch-Case und und einer While .. do Schleife.
* 3: Das abarbeiten und aufrufen sämtlicher Unterfunktionen mit passenden Parametern und die vom Benutzer gewählte eingabe...
* zu erfüllen.
*
* Man kann hier Argumentieren "das kann man doch allen in main abarbeiten", letztendlich ist es eine von mir getroffene designentscheidung.
* */
void choice() //Auswahl zwischen Teil1 v Teil2
{
	int Choice, sol;
	int bla = 1;

	while (bla == 1)
	{		// Benutzermenue
		printf("\n\t\t\t<<<Menu>>>"
			"\nBitte druecken Sie:"
			"\n\t'1' (Enter) fuer die Eingabe der Suchzahl."
			"\n\t-------------"
			"\n\t(0 zum Beenden)\n\t: ");
		scanf_s("%d", &Choice); // Benutzereingabe fuer das Menue
		switch (Choice) // Beginn Switch Case und somit auswertung der Benutzereingabe vom Menue
		{
		case 1:
			DatenAufnahme();
			printf("\n");
			sol = SearchOfSorted(SortedListe, zahl, 0, laenge);
			if (sol > 0) {
				printf("\nDas gesuchte Element steht an Stelle %d der Liste.\n\n", sol);
			}
			else {
				printf("\nDas gesuchte Element ist nicht in der Liste.\n\n");
			}
			break;
		case 0:
			bla = 0;
			break;
		default:
			printf("\n1 ist die einzig gueltigen Eingabe.\n");
			break;
		}
	}


}

int SearchOfSorted(int SL[], int tar, int limit, int len ) {
	int p = pivot(len, limit);
	printf("\nDas aktuelle Pivotelement ist: %d\t", p);
	printf("\nDas aktuelle len ist: %d\t", len);

	if (SL[p] == tar) return p + 1;
	if (p == len) return -1;
	
	if (SL[p] > tar)
	{
		printf("\n%d > %d", SL[p], tar);
		SearchOfSorted(SL, tar, limit, p-1);

	}
	else
	{
		printf("\n%d < %d", SL[p], tar);
		SearchOfSorted(SL, tar, p+1, len);
	}


}


// ermittlung des mittleren elements fuer die Suche
int pivot(int j, int l) {
	return ((l + j) / 2);
}

void DatenAufnahme() {
		printf("Bitte geben Sie die gesuchte Zahlein: ");
		scanf_s("%d", &zahl);
}