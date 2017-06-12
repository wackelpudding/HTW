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
			sol = SearchOfSorted(SortedListe, zahl, 0, laenge); //Aufruf der Sortierung und Speicherung des Ergebnisses in einer Variable
			if (sol > 0) {
				printf("\nDas gesuchte Element steht an Stelle %d der Liste.\n\n", sol); //Wenn in der Liste wird hier noch der Platz ausgegeben
			}
			else {
				printf("\nDas gesuchte Element ist nicht in der Liste.\n\n"); //Ausgabe wenn das Element nicht in der List ist
			}
			break;
		case 0:
			bla = 0;
			break;
		default:
			printf("\n1 ist die einzig gueltigen Eingabe.\n"); //Fehlermeldung bei falscher Case eingabe
			break;
		}
	}


}

//Durchsuchen einer sortierten Liste
int SearchOfSorted(int SL[], int tar, int limit, int len ) {
	int p = pivot(len, limit); //ermittlung des Pivot elements und speichern in einer variable
	printf("\nDas aktuelle Pivotelement ist: %d\t", p); // Ausgabe aktuelles Pivotelement
	printf("\nDas aktuelle 'rechts' ist: %d\t", len);	// Ausgabe aktuelle "rechte" Grenze

	if (SL[p] == tar) return p + 1; // Wenn Das Pivotelement das Ziel ist, wird dessen Wertigkeit um eins erhoeht, um der Stelle in der iste zu entsprechen.
	if (p == len) return -1; // Wenn das Ende der Liste erreicht ist, soll ein "Fehler" zurrueckgegeben werden


	/*
	 * If-Else für den Vergleich ob das element Groesser oder kleiner ist
	 * 		Groesser als Ziel
	 * 				- Gebe den Vergleich aus und mach einen Rekursiven selbstaufruf,
	 * 				  wobei das Pivotelement reduziert um 1 als neues rechts (groesse der Liste) und
	 * 				  "links" bleibt.
	 *
	 * 		Kleiner als Ziel
	 * 				Gebe den Vergleich aus und fuehre einen rekursiven Selbstaufruf auf,
	 * 				wo nun die linke untergrenze das Pivotelement erhoeht um eins darstellt und die rechte grenze beibehalten wird
	 */
	if (SL[p] > tar)
	{
		printf("\n%d > %d", SL[p], tar);
		return SearchOfSorted(SL, tar, limit, p-1);

	}
	else
	{
		printf("\n%d < %d", SL[p], tar);
		return SearchOfSorted(SL, tar, p+1, len);
	}


}


// ermittlung des mittleren elements fuer die Suche
int pivot(int j, int l) {
	return ((l + j) / 2);
}

//simple Datenaufnahme mit einer Ausgabe und einer Datenaufnahme
void DatenAufnahme() {
		printf("Bitte geben Sie die gesuchte Zahlein: ");
		scanf_s("%d", &zahl);
}
