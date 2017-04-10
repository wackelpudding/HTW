/* bool.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.

lies 2 int ein und liefer

wahr wenn:
	- eine der beiden Variablen 0 ist
	- beide Variablen 0 sind
	- eine Variable negativ ist
	- a <= b
	- a - b < 5

falsch wenn:
	-	a <> b
	- b <= a
	- beide positiv
	- eine oder beide 0 sind 
	- a <= 2 && b >= 3

	
*/

#include "stdafx.h"

int a, b;
void True();
void False();
void Welcome();
void Start();
void DatenAufnahme();


int main()
{
	Welcome();
	DatenAufnahme();
	True();
	return 0;
}

void Welcome(){
	printf("\n\nHallo, dieses Programm ist f�r das Ueben von Boolschen Ausdruecken\n");
}

/*
void Start(){
	//int bla = 1;
	
	//while (bla == 1)
	//{
		int Choice;
		printf("\n\nBitte druecken Sie '1' zum Starten und '0' zum Beenden.\n");
		scanf_s("%d", &Choice);
		switch (Choice)
		{
		case 1:
			DatenAufnahme();
			True();
			//False();
			break;
		case 0:
			printf("\n\nDas Programm wird nun beendet...\n\n");
			bla = 0;
			break;
		default:
			printf("\n1 oder 0 sind die einzig gueltigen Eingaben.\n");
			break;
		}
	//}
}
*/
void DatenAufnahme(){
	printf("\nBitte geben Sie nun 2 Zahlen ein (Zahl1,Zahl2): ");
	scanf_s("%i %i", &a, &b);
}

void True(){



	if (a == 0 ^ b == 0){
		printf("\n Wahr! -  Zahl1 oder Zahl 2 ist '0' \n\n");
	}
	if (a == 0 && b == 0 ){
		printf("\n Wahr! -  Beide Zahlen sind '0' \n\n");
	}

	if (0 > (a && b)){
		printf("\n Wahr! -  Eine Zahl ist negativ \n\n");
	}

	if (a <= b){
		printf("\n Wahr! -  Zahl1 ist kleiner gleich Zahl2 \n\n");
	}

	if ((a - b) < 5){
		printf("\n Wahr! -  Die Differenz von beiden Zahlen ist kleiner als 5! \n\n");
	}
	
}

void False(){
	if !(a == b){
		printf("\n Falsch! -  Zahl1 oder Zahl 2 sind verschieden!\n\n");
	}
	if !(b <= a){
		printf("\n Falsch! -  Zahl2 ist kleiner gleich \n\n");
	}
	if !(a == b){
		printf("\n Falsch! -  Zahl1 oder Zahl 2 sind verschieden!\n\n");
	}
	if !(a == b){
		printf("\n Falsch! -  Zahl1 oder Zahl 2 sind verschieden!\n\n");
	}
	if !(a == b){
		printf("\n Falsch! -  Zahl1 oder Zahl 2 sind verschieden!\n\n");
	}
}
