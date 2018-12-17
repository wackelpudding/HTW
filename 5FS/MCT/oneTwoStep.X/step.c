#include "step.h"
#include "mcc_generated_files/pin_manager.h"
#include <xc.h>
#include "mcc_generated_files/device_config.h"

/**
 * Die Funktion step stellt einen neuen Schritt im Schrittmotor ein.
 * Sie achtet zus�tzlich darauf, dass nur legale Schritte eingestellt werden.
 * Ein legaler Schritt ist ein Schritt von der Weite '1'. Inklusive �bertrag.
 * 
 * @param curStep 
 *  Der aktuelle Schritt im Schrittmotor
 * @param setStep
 *  Der einzustellende Schritt im Schrittmotor
 * @return 
 *  Gibt den aktuellen Schritt im Schrittmotor zurr�ck
 */
int step(int curStep, int setStep) {

    if (((curStep + setStep) % 4) == 1 || ((curStep + setStep) % 4) == 3) {
        switch (setStep) {
            case 1: // Schritt 1 und die dazugeh�rigen Spuleneinstellungen.
                IN1_SetHigh();
                IN2_SetHigh();
                IN3_SetLow();
                IN4_SetLow();
                break;
            case 2: // Schritt 2 und die dazugeh�rigen Spuleneinstellungen.
                IN1_SetLow();
                IN2_SetHigh();
                IN3_SetHigh();
                IN4_SetLow();
                break;
            case 3: // Schritt 3 und die dazugeh�rigen Spuleneinstellungen.
                IN1_SetLow();
                IN2_SetLow();
                IN3_SetHigh();
                IN4_SetHigh();
                break;
            case 4: // Schritt 4 und die dazugeh�rigen Spuleneinstellungen.
                IN1_SetHigh();
                IN2_SetLow();
                IN3_SetLow();
                IN4_SetHigh();
                break;
            default: // Wenn ein ung�ltiger Schritt gegeben ist, soll nichts getan werden.
                break;
        }
        return setStep;
    }
    return curStep;
}

/**
 * Die Funktion stepping macht eine gew�nschte Anzahl von Schritten.
 * Diese k�nnen gegen den Uhrzeigersinn (positive Schrittzahl),
 * oder im Uhrzeigersinn (negative Schrittzahl)
 * 
 * 
 * @param curStep 
 *  Der aktuelle Schritt im Schrittmotor
 * @param toStep
 *  Anzahl zu t�tigender Schritte
 *     toStep < 0: im Uhrzeigersinn
 *     toStep > 0: gegen den Uhrzeigersinn
 * @return 
 *  Gibt den aktuellen Schritt im Schrittmotor zurr�ck 
 */

int stepping(int curStep, int toStep) {
    int temp = curStep; 
    if (toStep == 0) { // Wenn keine Schritte gemacht werden sollen.
        return curStep;
    }
    if (toStep < 0) { // Wenn die Anzahl der Schritt negativ ist.
        toStep *= -1; // negiere die Schrittzahl
        for (int i = 1; i <= toStep; i++) { // Schrittschleife f�r anzahl der Schritte  
            temp--; 
            if (temp == 0) { // Da r�ckw�rts gez�hlt wird, und nur 4 Schritte da sind
                temp = 4;    // muss beim erreichen der Null der �bertrag gemacht werden.
            }
            curStep = step(temp + 1, temp); // Stelle mit step() den n�chsten Schritt ein.
            __delay_ms(10); //delay f�r das Einhalten der Bauteilspezifikation von 100Hz.
        }
    } else {    //Schrittzahl positiv.
        for (int i = 1; i <= toStep; i++) { // Schrittschleife f�r anzahl der Schritte
            temp++;
            if (temp == 5) { //�bertragskorrektur beim Vorw�rstlaufen.
                temp = 1;
            }
            curStep = step(temp - 1, temp); // Stelle mit step() den n�chsten Schritt ein.
            __delay_ms(10); //delay f�r das Einhalten der Bauteilspezifikation von 100Hz.
        }
    }
    return curStep; 
}

/**
 * clock dienst dazu, den Schrittmotor eine volle Drehung im Uhrzeigersinn
 * innerhalb von ~60 Sekunden durchzuf�hren.
 * 
 * @param curStep
 *  Der aktuelle Schritt im Schrittmotor
 */

int clock(int curStep) {

    curStep = stepping(curStep, -4);
    __delay_us(77500);
    return curStep;

}
