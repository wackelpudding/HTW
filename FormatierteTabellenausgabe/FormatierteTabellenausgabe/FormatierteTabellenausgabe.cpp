// FormatierteTabellenausgabe.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

/*
Ueben Sie die Arbeit mit den Ein/Ausgabefunktionen printf() und
scanf(). Lesen Sie dazu in Ihren Scripten, in Buechern oder der
Online-Hilfe nach.
Bitte beachten Sie:
Loesen Sie erst Teil 1 der Aufgabe, bevor Sie mit Teil 2 beginnen.
Sie sollen dabei auch lernen, wie man ein vorhandenes Programm
erweitert bzw. veraendert.
Teil 1:
Erzeugen Sie eine kleine Tabelle, z.B.
# Messwert  | Messung 1 | Messung 2 | Mittelwert
------------|-----------|-----------|------------
	1		|     10.00 |     20.00 |      15.00
			|           |           |
	2		|    300.00 |    100.00 |     200.00
			|           |           |

Die Zahlen sollen als Konstanten vom Typ float eingesetzt werden.
Ueberlegen Sie, wie Sie die Tabelle unter Ausnutzung von Forma-
tierungszeichen erzeugen koennen.
Erstellen Sie ein Programm und testen Sie Ihre Loesung.

Teil 2:
Nehmen Sie Ihre Loesung aus Teil 1 und aendern Sie den Quelltext
so, dass die Zahlen nicht mehr als Konstanten sondern als
Variablen angelegt werden. Die Variablen sollen durch den Nutzer
vorgegeben und ueber die Tastatur eingelesen werden.
Verwenden Sie dazu scanf().

*/

#include "stdafx.h"

void welcome();
bool choice();
void PartOne();
void PartTwo();

const double T1_M1 = 10.00;
const double T1_M2 = 20.00;
const double T2_M1 = 300.00;
const double T2_M2 = 100.00;

double M1, M2, Mw;
int Choice;

int _tmain(int argc, _TCHAR* argv[])
{
	welcome();
	choice();
	return 0;
}

void welcome()
{
	printf("\nHallo, diese Programm ist für die Berechnung von 2 Mittelwerten.\n");
	printf("Teil 1 wird mit Konstanten generiert, Teil 2 mit\nvom Benutzer eingegebenen Daten.");
}



bool choice() //Auswahl zwischen Teil1 v Teil2
{
	while (true)
	{
		printf("\n\nBitte treffen Sie ihre Wahl, welche Teil Sie ausfuehren wollen: ");
		scanf_s("%ld", &Choice);
		switch (Choice)
		{
		case 1:
			PartOne();
			return false;
		case 2:
			PartTwo();
			return false;
		default:
			printf("\n1 oder 2 sind die einzig gueltigen Eingaben.\n");
			
		} Choice;
	}
	

}

void PartOne()
{
	printf("\nDieser Teil %ld ist noch nicht fertig\n\n", Choice);
}

void PartTwo()
{
	printf("\nDieser Teil %ld ist noch nicht fertig\n\n",Choice);
}