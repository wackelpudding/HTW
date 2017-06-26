// EinfachVerketteteListen.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

//Definition des Strukturelements
struct Wortliste
{
	char Wort[20];
	Wortliste* next;
};


//Variablendeklaration für unsere Wortliste
Wortliste *satz;

void satzaufbau(Wortliste *&Satzanfang) {
	Wortliste *neu, *ende;

	printf("\nBitte gib deinen Satz Wort fuer Wort ein...\nEinsatz ende mit einem Punkt ('.')\n\t:");

	Satzanfang = NULL;
	ende = NULL;
	do {
	
		neu = new Wortliste;
		cin >>neu->Wort;
		neu->next = NULL;
		if (Satzanfang == NULL) Satzanfang = neu;
		else ende->next = neu;
		ende = neu;
	
	
	} while (neu->Wort[0]!='.');
}


int rekausgabe(Wortliste *&Satzanfang) {
	if (Satzanfang == NULL) { 
		printf("\n");
		return 0; };
	cout << Satzanfang->Wort << " ";
	return rekausgabe(Satzanfang->next);
}

void ausgabeit(Wortliste *&Satzanfang) {
	Wortliste *nehmichjetzt;
	nehmichjetzt = Satzanfang;
	printf("\nDiese Ausgabe erfolgt iterativ...\n\n\t");
	while (nehmichjetzt != NULL){
		cout << nehmichjetzt->Wort << " ";
		nehmichjetzt = nehmichjetzt->next;
	}
}

void welcome() {
	printf("\nDiese Funktion ist fuer den Aufbau eines 'Satzes' mit hilfe von einfach verketteten Listen.\n");
}

int main()
{
	welcome();
	satzaufbau(*&satz);
	ausgabeit(*&satz);
	printf("\n\nDiese Ausgabe erfolgt rekursiv...\n\n\t");
	rekausgabe(*&satz);

	return 0;
}
