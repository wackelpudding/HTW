// KeditZins.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

int Jahre;
float KreditRahmen, ZinsSatz, ZinsSumme, Rate, Zinsen;
float OrgKredit;

float zinsrechnung(float KreditRahmen, float ZinsSatz){
	return (KreditRahmen * ZinsSatz / 100);
}

float kreditrechnung(float KreditRahmen, float Zinsen, float Rate){
	return (KreditRahmen + Zinsen - Rate);
}

void DatenAufnahme(){
	printf("Guten Tag,\n um ihnen Ihren Kreditzins \nund die Laufzeit zu berechnen benötige ich folgende Daten:\n");
	printf("- Kreditrahmen\n- aktueller Zinssatz\n- Wunschrate\n\n");

	// Aufnahme der Grundlegenden Daten die keiner tieferen Prüfung erfordern.
	printf("Kreditrahmen in GELD (XXX.XX): ");
	scanf_s("%f", &KreditRahmen);
	printf("\nZinssatz (XXX.XX%%): ");
	scanf_s("%f", &ZinsSatz);

	Zinsen = zinsrechnung(KreditRahmen, ZinsSatz);
	printf("\n\nAuf Grunder eingegebenen Daten ergibt sich jaehrliche Zinsen von: %.2f GELD\n\n", Zinsen);
	//Die Raten dürfen nicht kleiner als die Zinsen gewählt werden.. Kundenfreundlichkeit.. pah!
	do
	{
		printf("\nBitte geben Sie die Rate ein (groesser als Zinsen!): ");
		scanf_s("%f", &Rate);
	} while (Rate <= Zinsen);
}

void Berechnung(){
	OrgKredit = KreditRahmen; //Sicherung des Originalen Kreditrahmens
	Jahre = 0;						//Alles hat einen Anfang..
	while (KreditRahmen > 0){	//Somit ergibt sich, dass die letzte Rate bei nichterfüllen dieser Bedingung = Kreditrahmen ist.
		Jahre++;
		Zinsen = zinsrechnung(KreditRahmen, ZinsSatz);
		KreditRahmen = kreditrechnung(KreditRahmen, Zinsen, Rate);
		ZinsSumme = ZinsSumme + Zinsen;
	}
	if (KreditRahmen < 0)
	{
		Rate = Rate + KreditRahmen;
		printf("\nDie letzte Rate belaeuft sich auf: %.2f GELD", Rate);
	}
	
}

void DatenAusgabe(){
	printf("\n\nKreditrahmen: %9.2f GELD\n", OrgKredit);
	printf("Monatliche Rate: %9.2f GELD\n", Rate);
	printf("Gesamte Laufdauer: %9.2d Jahre\n", Jahre);
	printf("Zinssumme: %9.2f GELD\n\n", ZinsSumme);
}

void Start(){
	printf("Dieses Programm dient zur Berechnung des Kreditzinses und der Laufzeit Ihres Wunschkredites.\n\n");
	DatenAufnahme();
	Berechnung();
	DatenAusgabe();
}

int _tmain(int argc, _TCHAR* argv[])
{
	Start();
}

