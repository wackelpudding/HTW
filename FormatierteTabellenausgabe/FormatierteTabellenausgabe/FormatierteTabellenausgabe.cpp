// FormatierteTabellenausgabe.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
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

#include "stdio.h"

void welcome();
void choice();
void PartOne();
void PartTwo();


// Ein paar Konstanten fuer Teil1
const double T1_M1 = 10.00;
const double T1_M2 = 20.00;
const double T2_M1 = 300.00;
const double T2_M2 = 100.00;

//Die Variablen f�r Teil 2
double M1_M1, M1_M2, M1_Mw;
double M2_M1, M2_M2, M2_Mw;
int Choice;

int main()
{
	welcome();
	choice();
	return 0;
}

void welcome()
{
	printf("\nHallo, diese Programm ist fuer die Berechnung von 2 Mittelwerten.\n");
	printf("Teil 1 wird mit Konstanten generiert, Teil 2 mit\nvom Benutzer eingegebenen Daten.");
}



void choice() //Auswahl zwischen Teil1 v Teil2
{
	int bla = 1;

	while (bla == 1)
	{
		printf("\n\nBitte treffen Sie ihre Wahl, welche Teil Sie ausfuehren wollen: ");
		scanf_s("%d", &Choice);
		switch (Choice)
		{
		case 1:
			PartOne();
			bla = 0;
			break;
		case 2:
			PartTwo();
			bla = 0;
			break;
		default:
			printf("\n1 oder 2 sind die einzig gueltigen Eingaben.\n");
			break;
		}
	}


}

void PartOne() //Auswahl nummer "1"
{
	double T1_MW = (T1_M1 + T1_M2) / 2; //errechnung MW von T1
	double T2_MW = (T2_M1 + T2_M2) / 2; //errechnung MW T2

	printf("\n # Messwert | Messung 1 | Messung 2 | Mittelwert\n");
	printf("------------|-----------|-----------|-----------\n");
	printf("     1      | %9.2lf | %9.2lf | %9.2lf \n",T1_M1, T1_M2, T1_MW);
	printf("            |           |           |            \n");
	printf("     2      | %9.2lf | %9.2lf | %9.2lf \n", T2_M1, T2_M2, T2_MW);
	printf("            |           |           |            \n");
}

void PartTwo() //Auswahl Nummer "2"
{
	printf("\n\n Willkommen in Teil %d des Programms, hier haben sie \ndie Moeglichkeit zwei eigene Wertepaare einzugeben.\n\n",Choice);


	printf("Bitte geben Sie Wert 1 von Paar 1 ein: ");
	scanf_s("%lf",&M1_M1);
	printf("\nBitte geben Sie Wert 2 von Paar 1 ein: ");
	scanf_s("%lf",&M1_M2);
	printf("Bitte geben Sie Wert 1 von Paar 2 ein: ");
	scanf_s("%lf",&M2_M1);
	printf("\nBitte geben Sie Wert 2 von Paar 2 ein: ");
	scanf_s("%lf",&M2_M2);

	M1_Mw = (M1_M1 + M1_M2)/2;
	M2_Mw = (M2_M1 + M2_M2)/2;

	printf("\n\n # Messwert | Messung 1 | Messung 2 | Mittelwert\n");
	printf("------------|-----------|-----------|-----------\n");
	printf("     1      | %9.2lf | %9.2lf | %9.2lf \n",M1_M1, M1_M2, M1_Mw);
	printf("            |           |           |            \n");
	printf("     2      | %9.2lf | %9.2lf | %9.2lf \n", M2_M1, M2_M2, M2_Mw);
	printf("            |           |           |            \n");

}
