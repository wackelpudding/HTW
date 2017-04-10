/*
20161101_mm_in_inch.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.

Aufgabe:
- Wir wollen den Wert in mm einlesen
- Umrechnung von "mm" in "in"
- Ergebnis der Umrechnung ausgeben

Anforderungen:
- Mitteilung seines Verwendudungszwecks
- Dezimalwert für m mit einer Nachkommastelle
- Vorgabewert und Umrechnungswert solleb veide ausgegeben werden
- Nach der Ausgabe des Umrechnungswertes wird das Programm beendet

Formel:
- 1 Inch = 25.4 mm

Algorithmus:
#preprozessor (include std libs .. stdafx.h)
1. Gebe den Zweck des Programms aus
2. Lies die Größen in Inch ein
3. Konvertiere Inch in mm mit Hilfe einer Variable according to formula
4. Gebe die Ergebnisse aus


*/

#include "stdafx.h" //preprozessor

void greeting(); //declare greeting func defined later
void calc();


const double InchPerMm = 25.4; // declare constant variable for calc mm -> inch

double Inch, Mm;


int _tmain(int argc, _TCHAR* argv[])	//let's roll
{
	greeting();
	calc();
	return 0;
}

void greeting() // send a warm welcome to the DAU executing this
{
	printf("\n\n Konvertierung von mm in inch\n");
	printf("\nHallo DAU, da du anscheint zu faul bist einen Taschenrechner\nzu benutzen Rechne ich 'mm' in 'inch' fuer dich um.\n\n");
}

void calc()
{
	printf("Also... einmal mm bitte: ");
	scanf_s("%lf", &Mm);

	Inch = Mm/ InchPerMm;

	printf("\n\nSo Pie mal Daumen sollten deine %.3lf mm \nso ziemlich genau %.3lf inch sein...\n\n", Mm, Inch);
}