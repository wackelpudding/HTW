/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F1937
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"

/*
                         Main application
 */

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    // defining some global variables
    //clear screen & cursor zum seitenanfang + Funktionsmen�
    send_string("\033[H");
    send_string("\033[2J");
    send_string("Willkommen zum I/O-Board Interface.\r\n\n");
    send_string("Der angeschlossene Temperatursensor\n\rwird alle 6 Sekunden abgefragt und\r\ngibt das Messergebnis auf der Konsole bekannt.\r\n");
    send_string("##################################################\r\n");        
    send_string("Sie gibt folgende Funktionen bedienen:\r\n");
    send_string("(Tippen Sie auf die entsprechende Taste auf Ihrer Tastatur.)\r\n");
    send_string("1) Relais K1 schalten.\r\n");
    send_string("2) Relais K2 schalten.\r\n");
    send_string("q) K1 durch Input0 schaltbar machen ein/aus.\r\n");
    send_string("w) K2 durch Input1 schaltbar machen ein/aus.\r\n");
    send_string("##################################################\r\n");
    
    
    while (1)
    {
        // Add your application code
        
        //lese ein einzelnes zeichen vom serial port ein.
        char console = EUSART_Read();
        
        switch(console){
            case '1':
                if (!in0){
                    if (!K1_GetValue() && !in0){
                        LED1_SetHigh();
                        K1_SetHigh();
                        send_string("\033[2K");
                        send_string("Relais K1 ist nun aktiv\r\n");
                    }   else {
                        LED1_SetLow(); 
                        K1_SetLow();
                        send_string("\033[2K");
                        send_string("Relais K1 ist nun inaktiv\r\n");
                    }
                }
                break;
            case '2':
                if (!in1){
                    if (!K2_GetValue()){
                        LED2_SetHigh(); 
                        K2_SetHigh();
                        send_string("\033[2K");
                        send_string("Relais K2 ist nun aktiv\r\n");
                    }   else {
                        LED2_SetLow();
                        K2_SetLow();
                        send_string("\033[2K");
                        send_string("Relais K2 ist nun inaktiv\r\n");
                    }
                }
                break;   
            case 'q':
                in0 = !in0;
                send_string("K1 Inputsteuerung: ");
                if (in0){
                    send_string("AN!\r\n");
                }   else {
                    send_string("AUS!\r\n");
                }
                break;
            case 'w':
                in1 = !in1;
                send_string("K2 Inputsteuerung: ");
                if (in1){
                    send_string("AN!\r\n");
                }   else {
                    send_string("AUS!\r\n");
                }
                break;
            default: break;
        }
    }
}
/**
 End of File
*/