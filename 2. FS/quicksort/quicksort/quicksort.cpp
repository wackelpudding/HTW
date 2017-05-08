// quicksort - Ricardo Jimenez Tuero
//

#include "stdafx.h"

//Funktionsdeklarationen
void swap(int*, int*);
void welcome();
void DatenAufnahme();
void QuickSort(int[], int, int);
int pivot(int[], int);
void Ausgabe(int[], int);

//globale Variablendeklaration
int Liste[1000];
//int Liste[] = { 89,17,36,24,12,2 };  //zum wechseln die kommentarzeile wechseln.... 
int laenge;

int main()
{
	welcome();

	//DatenAufnahme();
	
	//laenge = sizeof(Liste) / sizeof(Liste[0]);

	int wubdi = 0;

	do {
		printf("Bitte geben Sie ein Element ein: ");
		scanf_s("%d", &Liste[wubdi]);
		wubdi++;
	} while (Liste[wubdi - 1] != 0);

	laenge = wubdi - 1;

	int links = 0;
	int rechts = laenge-1;

	QuickSort(Liste, links, rechts);
	
	printf("\n------Finale Ausgabe-------\n\n");
	Ausgabe(Liste, laenge);

	return 0;
}


void welcome() {
	printf("\nGuten Tag dieses Programm ist fuer das sortieren via Quicksort.\n\n");
}

void swap(int* z1, int* z2) {

	int temp;
	printf("\n------\nTausche %d und %d.\n------\n",*z1,*z2);
	temp = *z1;
	*z1 = *z2;
	*z2 = temp;
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

int pivot(int j, int l) {
	return ((l+j) / 2);
}

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



void Ausgabe(int array[], int l) {
	for (int i = 0; i < l; i++) {
		printf("%d\t", array[i]);
	}
	printf("\n\n");
}