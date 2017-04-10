// zyklen.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"


void welcome()
{
	printf("\nHallo, diese Programm ist fuer das Ausgeben von 3 Zaehlreihen\n");
	printf("Teil 1: vorpruefende Schleife .\n");
	printf("Teil 2: nachpruefende Schleife.\n");
	printf("Teil 3: Zaehlzyklus..\n");
	printf("Teil 4: Zaehlzyklus mit eigenen Werte.\n\n\n");
}

void PartOne(){
	int VorZaehler = 1;
	while (VorZaehler < 20)
	{
		printf("%d ", VorZaehler);
		VorZaehler = VorZaehler + 2;
	}
	printf("\n");
}

void PartTwo(){
	int NachZaehler = 1;
	do
	{
		printf("%d ", NachZaehler);
		NachZaehler = NachZaehler + 2;
	} 
	while (NachZaehler < 20);
	printf("\n");
}

void PartThree(){
	for (int i = 1; i < 20; i = i + 2)
	{
		printf("%d ", i);
	}
	printf("\n");
}

void PartFour(){
	int Upper, Lower, Step;
	printf("Teil 4 erfordert Eingaben:\n- Untergrenze\n- Obergrenze\n- Schrittweite\n\n");
	printf("Bitte beachten Sie dass die die Untergrenze KLEINER als die Obergrenze sein muss.\n\n");
	do
	{
		printf("Bitte geben Sie die Untergrenze ein: ");
		scanf_s("%d", &Lower);
		printf("\n\nBitte geben Sie die Obergrenze ein: ");
		scanf_s("%d", &Upper);
	} while (Lower >= Upper);
	printf("\n\nBitte geben Sie die Schrittweite ein: ");
	scanf_s("%d", &Step);

	printf("\n\n\nDie Schleife laeuft nun von %d bis %d mit einer Schrittweite von %d\n\n", Lower, Upper, Step);

	for (int i = Lower; i <= Upper; i = i + Step)
	{
		printf("%d ", i);
	}
	printf("\n");
}


void choice() //Auswahl zwischen Teil1 v Teil2 v Teil3
{
	int Choice;
	int bla = 1;

	while (bla == 1)
	{
		welcome();
		printf("\n\nBitte treffen Sie ihre Wahl, welche Teil Sie ausfuehren wollen(0 zum Beenden): ");
		scanf_s("%d", &Choice);
		switch (Choice)
		{
		case 1:
			PartOne();
			break;
		case 2:
			PartTwo();
			break;
		case 3:
			PartThree();
			break;
		case 4:
			PartFour();
			break;
		case 0:
			bla = 0;
			break;
		default:
			printf("\n1-4 sind die einzig gueltigen Eingaben.\n");
			break;
		}
	}


}

int _tmain(int argc, _TCHAR* argv[])
{
	choice();
	return 0;
}

