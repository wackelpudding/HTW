// countletters.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
// Quelle: https://wiki.freitagsrunde.org/C-Kurs/Buchstaben_z%C3%A4hlen/Musterl%C3%B6sung 
// Ueberarbeitet von Ricardo Jimenez Tuero
// Die Loesung dieser Aufgabe ist trivial und ich hoffe mein Verstaendis der ablaeufe ist durch meine Ausfuehrliche kommentierung gegeben.
// Das Programm wird ueber die Windows-shell "cmd" aufgerufen. Unter Unix systemen kann das programm mit der unix-shell aufgerufen werden.

#define _CRT_SECURE_NO_WARNINGS //damit in visual studio fopen() verwendet werden kann
#include "stdafx.h"
#include <stdlib.h>


//Ausabe von Rauten zu Verbildlichung de Vorkommen der einzelnen buchstaben zueinander
void Ausgabe(int length) {
	int i;
	for (i = 0; i < length; i++) {
		printf("#");
	}
}

//die Main Funktion
int main(int argc, char **argv) {
	if (argc != 2) { 
		//Sie erwartet eine weitere Eingabe beim Aufruf des programms. argc steht für argumentcount und zaehlt die anzahl der uebergebenen Parameter
		//Wenn keine Datei mitgegeben wird ein Fehler ausgegeben
		printf("FEHLER: Bitte geben Sie einen Dateinamen beim Aufruf des Programms an.\n");
		return 0;
	}

	// oeffne Datei und gib einen Fehler aus, wenn du sie nicht öffnen kannst.
	FILE *file = fopen(argv[1], "r");
	if (file == NULL) {
		printf("FEHLER: Kann Datei nicht oeffnen!\n");
		return 0;
	}

	// Initialisiere die Variablen, ein Array fuer das hochzaehklen von aA-zZ und eine allgemeine zum hochzaehlen.
	int Buchstabenliste[26] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int AlleBuchstaben = 0;

	/* Hier wird nun jedes Zeichen eingelesen
	 * Alle Zeichen werden als character eingelesen und kriegen somit intern einen definierten Zahlenwert
	 * Diese Wissen nutzen wir um leicht herauszufinden, ob das aktuell eingelesene Zeichen
	 * ein buchstabe ist, oder eben nicht. Dafuer muessen wir nicht mal die intern verwendeten
	 * Zahlen kennen, da man diese einfach mit dem zahlenbereich von klein/gross a bis klein/gross Z
	 * vergleicht und anschliessend den grundwert des jeweiligen vergleichs vom zutreffenden ergebnis abzieht um dies in die
	 * Buchstabenstatistik einzufuegen (+ ein an der stelle im array), die gesamt summe der gefundenen buchstaben
	 * wird anschließend auch hochgerechnet.
	 */
	while (1) { //das C-Aequivalent zu "TRUE"
		int zeichen = fgetc(file); // lese den nächsten character aus file ein
		if (zeichen < 0) {
			// Ein zeichen kleiner als 0 definiert das Dateiede, da jedes Zeichen ein positiven wert hat
			break;
		}
		if (zeichen >= 'A' && zeichen <= 'Z') {
			// Das gefundene Zeichen ist ein Grossbuchstabe
			Buchstabenliste[zeichen - 'A']++;
			AlleBuchstaben++;
		}
		else if (zeichen >= 'a' && zeichen <= 'z') {
			// Das gefundene Zeichen ist ein kleinbuchstabe
			Buchstabenliste[zeichen - 'a']++;
			AlleBuchstaben++;
		}
	}

	// Am ende muss die datei natuerlich geschlossen werden, da es sonst bei der mehrmaligen verwendung der gleichen Datei zu schweren Fehler kommen kann.
	fclose(file);
	
	// Ausgabe der Statistik mit Auswertung aller gesammelten Buchstaben
	int i;
	for (i = 0; i < 26; i++) {
		printf("%c : %3d  ", (char)(i + 'A'), Buchstabenliste[i]);
		Ausgabe((Buchstabenliste[i] * 300) / AlleBuchstaben);
		printf("\n");
	}
}