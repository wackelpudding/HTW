// Zeiterfassung.cpp : Definiert den Einstiegspunkt fuer die Konsolenanwendung.
//

#include "stdafx.h"

//declarations of functions
int HourMinutes2Seconds(int, int);
int Worktime(int, int);
void DatenErfassung();
void Berechnung();
void DatenAusgabe();
void Start();
//void Welcome();

//init of some needed variables
int End, Begin, Seconds, wStartM, wStartH;
int wEndM, wEndH, Time, Hours, Minutes, Pause;
int errorstate = 0;

int main()
{
	//Welcome();
	Start();
	return 0;
}

int HourMinutes2Seconds(int hours, int minutes)
{
	return (hours * 3600 + minutes * 60);
}

int Worktime(int begin, int end)
{
	return (end - begin);
}

void Start()
{
	DatenErfassung();
	Berechnung();
	if (errorstate == 0)
	{
		DatenAusgabe();
	}
}

void DatenErfassung()
{
	int timecheck = 0; // wird für die  do..while schleife benutzt
	do { //Eingabe der Arbeitszeiten mit kontrolle ob die Zeiten legitim sind.
		printf("Bitte geben Sie Ihre Anfangsarbeitszeit ein (HH:MM): \n");
		scanf_s("%d:%d", &wStartH,&wStartM);
		if ((wStartH <= 23 && wStartH >= 0) && (wStartM >= 0 && wStartM <= 59) ){
			printf("Bitte geben Sie Ihre Arbeitsendzeit ein (HH:MM): \n");
			scanf_s("%d:%d", &wEndH, &wEndM);
			if ((wEndH <= 23 && wEndH >= 0) && (wEndM >= 0 && wEndM <= 59) ){
				timecheck = 1;
			} else {
				printf("\nBitte geben Sie eine gültige Uhrzeit ein!\n");
			}
		} else {
			printf("\nBitte geben Sie eine gültige Uhrzeit ein!\n");
		}

	} while (timecheck == 0);
}

void Berechnung()
{
	Begin = HourMinutes2Seconds(wStartH, wStartM);
	End = HourMinutes2Seconds(wEndH, wEndM);
	if (Begin < End)
	{
		Time = Worktime(Begin, End);
		if (Time > (3600 * 6))
		{
			Pause = 1;
			Time -= 1800;
			Hours = Time / 3600;
			Minutes = (Time % 3600) / 60;
		}
		else
		{
			Hours = Time / 3600;
			Minutes = (Time % 3600) / 60;
		}

	}
	else
	{
		printf("\nTadah, evil error of doom!");
		errorstate = 1;
	}

}

void DatenAusgabe()
{
	printf("\nIhr Eingegeber Arbeitsbeginn: %2.2d:%2.2d \n", wStartH, wStartM);
	printf("\nIhr Eingegebes Arbeitsende: %2.2d:%2.2d \n", wEndH, wEndM);
	if (Pause == 1)
	{
		printf("\nIhrer Arbeitszeit werden 30 Minuten Pausenzeit abgezogen....\n\n");
	}
	printf("\nDaraus ergibt sich eine Arbeitszeit von %2.2d:%2.2d \n", Hours, Minutes);

}
