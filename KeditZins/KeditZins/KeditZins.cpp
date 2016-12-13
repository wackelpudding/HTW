// KeditZins.cpp
// Ricardo Jimenez Tuero - B1IKT - Grundlagen der Programmierung
//

#include "stdafx.h"

int Jahre;
float KreditRahmen, ZinsSatz, ZinsSumme, Rate, Zinsen; // Variblen zur allg. Befehlsverarbeitung..
float OrgKredit, OrgRate; // Zwischenspeicher für Originalwerte

float zinsrechnung(float KreditRahmen, float ZinsSatz){
	return (KreditRahmen * ZinsSatz / 100);
}

float kreditrechnung(float KreditRahmen, float Zinsen, float Rate){
	return (KreditRahmen + Zinsen - Rate);
}

void DatenAufnahme(){
	printf("Guten Tag,\n\num ihnen Ihren Kreditzins und die Laufzeit zu berechnen\nbenoetige ich folgende Daten:\n\n");
	printf("- Kreditrahmen\n- aktueller Zinssatz\n- Wunschrate\n\n");

	// Aufnahme der Grundlegenden Daten die keiner tieferen Pruefung erfordern.
	printf("Kreditrahmen in GELD (XXX.XX): ");
	scanf_s("%f", &KreditRahmen);
	printf("\nZinssatz (XXX.XX%%): ");
	scanf_s("%f", &ZinsSatz);

	Zinsen = zinsrechnung(KreditRahmen, ZinsSatz);
	printf("\n\nAuf Grunder eingegebenen Daten ergibt sich jaehrliche Zinsen von: %.2f GELD\n\n", Zinsen);
	//Die Raten daerfen nicht kleiner als die Zinsen gewaehlt werden.. Kundenfreundlichkeit.. pah!
	do
	{
		printf("\nBitte geben Sie die Rate ein (groesser als Zinsen!): ");
		scanf_s("%f", &Rate);
	} while (Rate <= Zinsen);
}

void Berechnung(){
	OrgKredit = KreditRahmen; //Sicherung des Originalen Kreditrahmens
	Jahre = 0;						//Alles hat einen Anfang..
	while (KreditRahmen > 0){	//Somit ergibt sich, dass die letzte Rate bei nichterfuellen dieser Bedingung = Kreditrahmen ist.
		Jahre++;
		Zinsen = zinsrechnung(KreditRahmen, ZinsSatz);
		KreditRahmen = kreditrechnung(KreditRahmen, Zinsen, Rate);
		ZinsSumme = ZinsSumme + Zinsen;
	}
	if (KreditRahmen < 0)
	{
		OrgRate = Rate;
		Rate = Rate + KreditRahmen;
		printf("\nDie letzte Rate belaeuft sich auf: %.2f GELD", Rate);
	}

}

void DatenAusgabe(){
	printf("\n\nKreditrahmen: %9.2f GELD\n", OrgKredit);
	printf("Monatliche Rate: %9.2f GELD\n", OrgRate);
	printf("Gesamte Laufdauer: %9.2d Jahre\n", Jahre);
	printf("Zinssumme: %9.2f GELD\n\n", ZinsSumme);
}

void Start(){
	printf("Dieses Programm dient zur Berechnung des Kreditzinses und der Laufzeit Ihres Wunschkredites.\n\n");
	int boolean = 1;
	int Choice;

	do { // mindestens einmal durchlaufen
		DatenAufnahme();
		Berechnung();
		DatenAusgabe();

		//Abfrage, ob beendet werden soll.
		printf("\nMoechten Sie das Programm erneut ausfuehren? Ja(1)/ Nein(0): ");
		scanf_s("%d", &Choice);
		switch(Choice)
			{
			case 0:
				printf("Ihre Eingabe war: %d", Choice);
				printf("\n\nDas Programm wird beendet....\n");
				boolean = 0;
				break;
			default:
				printf("Ihre Eingabe war: %d\n\n", Choice);
				break;
			}
	} while (boolean == 1); // wenn hier kein Abbruch erfolgt fängt die Schleife wieder oben bei do an ..



}

int main()
{
	Start();
	return 0;
}

