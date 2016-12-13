// Zeiterfassung.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
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

int _tmain(int argc, _TCHAR* argv[])
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
	printf("Bitte geben Sie Ihre Anfangsarbeitszeit ein: \n");
	printf("Stunde (HH): ");
	scanf_s("%d", &wStartH);
	printf("\nMinute(MM): ");
	scanf_s("%d", &wStartM);
	printf("Bitte geben Sie Ihre Arbeitsendzeit ein: \n");
	printf("Stunde (HH): ");
	scanf_s("%d", &wEndH);
	printf("\nMinute(MM): ");
	scanf_s("%d", &wEndM);
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