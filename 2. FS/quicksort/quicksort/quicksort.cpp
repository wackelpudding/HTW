// quicksort - Ricardo Jimenez Tuero
//

#include "stdafx.h"

//Funktionsdeklarationen
void swap(int*, int*);
void welcome();
void DatenAufnahme();
void QuickSort(int[], int, int);
int pivot(int, int);
void choice();
void Ausgabe(int[], int);

//globale Variablendeklaration
int Liste[1000];
int ManualListe[] = { 89,17,36,24,12,2 };
int laenge;

int main()
{
	welcome();
	choice();
	return 0;
}

//Eine simple Funktion, die die Basisfunktionalität des Programms wiedergibt.
void welcome() {
	printf("\nGuten Tag dieses Programm ist fuer das Sortieren via Quicksort.\n");
}

// Die Tauschfunktion, erwartet 2 elemente und vertauscht sie mit hilfe einer 'temporären' Variable.
void swap(int* z1, int* z2) {

	int temp;
	printf("\n------\nTausche %d und %d.\n------\n",*z1,*z2);
	temp = *z1;
	*z1 = *z2;
	*z2 = temp;
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
	int Choice;
	int bla = 1;

	while (bla == 1)
	{		// Benutzermenue
		printf("\n\t\t\t<<<Menü>>>"
				"\nBitte druecken Sie:"
				"\n\t'1' (Enter) für eine vorgegebene Liste oder"
				"\n\t-------------"
				"\n\t'2' (Enter) für die Option selber eine Zahlenliste anzugeben."
				"\n\t(Die Zahl '0' beendet die Eingabe und löst das Sortieren aus)"
				"\n\t-------------"
				"\n\t(0 zum Beenden): ");
		scanf_s("%d", &Choice); // Benutzereingabe für das Menue
		switch (Choice) // Beginn Switch Case und somit auswertung der Benutzereingabe vom Menue
		{
		case 1:
			/*Fall eins umfass die Sortierung des anfangs vordefinierten Arrays.
			 * Für diesen kann die Laenge des Arrays Rechnerisch anhang der Speicherbelegung bestimmen. */
			laenge = sizeof(ManualListe) / sizeof(ManualListe[0]); //rechnerische bestimmung des arrays
			int links = 0; //linker Zeiger
			int rechts = laenge-1; // rechter zeiger (-1, da der array bei 0 anfängt zu zaehlen)
			QuickSort(ManualListe, links, rechts); // Aufruf der Quicksort funktion mit der Manuellen Liste
			printf("\n------Finale Ausgabe-------\n\n");
			Ausgabe(ManualListe, laenge); // ausgabe der Sortierten Liste
			break;
		case 2:
			DatenAufnahme();
			printf("\n------Finale Ausgabe-------\n\n");
			Ausgabe(Liste, laenge);
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

void DatenAufnahme() {

	int wubdi = 0;

	do {
		printf("Bitte geben Sie ein Element ein: ");
		scanf_s("%d", &Liste[wubdi]);
		wubdi++;
	} while (Liste[wubdi - 1] != 0);

	laenge = wubdi-1;
}

// Die Funktion für Quicksort, die nach Aufgabenstellung das Element in der Mitte ) bestimmen soll
int pivot(int j, int l) {
	return ((l+j) / 2);
}


// Quicksort funktion, der Algorithmus kann online nachgelesen werden, somit spar ich mir die Erklärung
void QuickSort(int liste[], int links, int rechts) {

	int i, j, x, p;



	if (links < rechts) {
		printf("------Zwischenausgabe------\n");
		Ausgabe(liste, laenge);
		p = pivot(links, rechts);
		x = liste[p];
		printf("\nDas aktuelle Pivotelement ist: %d\t",x);
		swap(&liste[links],&liste[p]);

		i = links;
		j = rechts;

		while (i <= j) {
			while ((i <= rechts) && (liste[i]) <= x) {
				i++;
			}
			while ((j > links) && (liste[j] > x)) {
				j--;
			}
			if (i < j) {
				swap(&liste[i], &liste[j]);
				j--;
				i++;
			}
		}
		printf("i:%d\tj:%d\n\n", links, rechts);
		swap(&liste[links], &liste[j]);

		QuickSort(liste, links, j - 1);
		QuickSort(liste, j + 1, rechts);
	}
}

//Ausgabe des benutzten Array. Einzeilig, mit Tabs getrennt
void Ausgabe(int array[], int l) {
	for (int i = 0; i < l; i++) {
		printf("%d\t", array[i]);
	}
	printf("\n\n");
}
