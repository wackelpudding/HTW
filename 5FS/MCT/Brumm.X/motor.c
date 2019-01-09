
#include "motor.h"
#include <xc.h>  
#include "mcc_generated_files/device_config.h"
#include "mcc_generated_files/pin_manager.h"
#include <stdint.h>
#include <stdbool.h>
#include "lcd.h"
#include "mcc_generated_files/epwm1.h"

/**
 * Initialisiert EUSART, stellt somit alle Register korrekt ein.
 */

void EUSART_Initialize(void) {
    // Set the EUSART module to the options selected in the user interface.

    // ABDOVF no_overflow; SCKP Non-Inverted; BRG16 16bit_generator; WUE disabled; ABDEN disabled; 
    BAUDCON = 0x08;

    // SPEN enabled; RX9 8-bit; CREN enabled; ADDEN disabled; SREN disabled; 
    RCSTA = 0x90;

    // TX9 8-bit; TX9D 0; SENDB sync_break_complete; TXEN enabled; SYNC asynchronous; BRGH hi_speed; CSRC slave; 
    TXSTA = 0x24;

    // SPBRGL 103; 
    SPBRGL = 0x67;

    // SPBRGH 0; 
    SPBRGH = 0x00;


}

/**
 * Schreibt ein Byte nach EUSART
 * 
 * @param txData
 *  Ein zu schreibendes Byte
 */

void EUSART_Write(uint8_t txData) {
    while (0 == PIR1bits.TXIF) {
    }

    TXREG = txData; // Write the data byte to the USART.
}

/**
 * Schreibt einen String nach EUSART.
 * 
 * @param x
 *  Ein String
 */

void send_string(const char *x) {
    while (*x) {
        EUSART_Write(*x++);
    }
}

/**
 * Bekommt ein bis zu 3 stelligen integer und konvertiert ihn zu einem 3 stelligen String.
 * Führende nullen werden zu Leerzeichen konvertiert.
 * 
 * @param integer
 *  zu konvertierender Integer (3- stellig)
 */
void conv_int_to_string(uint8_t integer) {
    char result[3] = ""; //initialisierung return char-array
    uint8_t rest;
    for (uint8_t i = 0; i < 3; i++) { //loop für alle 3 stellen
        rest = integer % 10; //modulo rest für die letzte Stelle
        integer = integer / 10; //restzahl ganzzahlig durch 10 teilen
        result[2 - i] = rest + 48; //result array rückwärts befüllen
    }
    if (result[0] == 48) { // wenn Stelle H null ist mit dem ACSII Wert für Leerzeichen ersetzen.
        result[0] = 32;
        if (result[1] == 48) { // wenn Stelle Z null ist mit dem ACSII Wert für Leerzeichen ersetzen.
            result[1] = 32;
        }
    }
    for (uint8_t i = 0; i < 3; i++) {//schreibe das Ergebnis nach EUSART.
        EUSART_Write(result[i]);
    }

}

/**
 * stellt Rechtslauf auf dem Motor ein.
 */
void rechtslauf() {
    IN1_SetLow();
    IN2_SetHigh();
}

/**
 * Stellt linkslauf bei dem Motor ein.
 */
void linkslauf() {
    IN1_SetHigh();
    IN2_SetLow();
}

/**
 * stoppt den Motor.
 */
void stop() {
    IN1_SetLow();
    IN2_SetLow();
}

/**
 * motorsteuerung() bekommt einen Wert vom Potentiometer
 * und macht anschließende Auswertung des Wertes.
 * 
 * @param poti
 *  Der abgelesene Wert vom Potentiometer zwischen 0 und 1023.
 *  poti <= 500 : der Motor dreht linkswärts
 *                  mit steigender geschwindigkeit je kleiner der Wert.
 *  500 < poti <= 522 : der Motor wird gestoppt.
 * 
 *  poti > 522: der Motor dreht rechtswärts mit steigender Geschwindigkeit
 *              je größer der Wert.
 */
void motorsteuerung(int poti) {
    int temp = 0;
    uint8_t percent = 0;
    if (poti <= 500) {
        linkslauf();
        send_string("\033[1;17H");  //Cursor auf 1:17
        send_string("links ");
        temp = (float) -(poti - 500) / 500 * 543 + 480; //Offset wird einberechnet und den Motor direkt anlaufen zu lassen.
        EPWM1_LoadDutyValue(temp);
        percent = (uint8_t) ((float) temp / 1023 * 100);
        send_string("\033[2;11H"); // Cursor auf 2:11
        conv_int_to_string(percent);
        send_string("%");
    } else if (poti > 500 && poti <= 522) {
        stop();
        send_string("\033[1;17H");
        send_string("STOP  ");
        send_string("\033[2;11H");
        send_string("  0%");
        EPWM1_LoadDutyValue(0);
        __delay_ms(350);    // Delay um den Motor zu schonen.
    } else {
        rechtslauf();
        send_string("\033[1;17H");
        send_string("rechts");
        temp = (float) (poti - 523) / 500 * 543 + 480; //Offset wird einberechnet und den Motor direkt anlaufen zu lassen.
        percent = (uint8_t) ((float) temp / 1023 * 100);
        EPWM1_LoadDutyValue(temp);
        send_string("\033[2;11H");
        conv_int_to_string(percent);
        send_string("%");
    }

}