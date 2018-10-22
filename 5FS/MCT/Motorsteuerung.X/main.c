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
#include "lcd.h"

/*
                         Main application
 */
uint16_t convertedValue = 0;

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();
    
    
    IN1_SetHigh();
    IN2_SetLow();
    
    Lcd_Init(); //Initialisierung des LCD
        uint16_t convertedValue= 0; //benutze Variablen werden deklariert und initalisiert
        float percent =0;
        char Buffer[] = {"InitalizeValue"}; 
        //RW_SetLow(); // Read-Modus
        
        Lcd_Clear(); // Bildschirm clearen
        Lcd_Set_Cursor(1,1); //Cursor nach oben Links (1,1) setzen
        Lcd_Write_String("Welfrieden:"); // Text in der oberen Zeile
        Lcd_Set_Cursor(2,1);
        Lcd_Write_String("Done:");
    while (1)
    {
        
        convertedValue = ADC_GetConversion(POT); //Konvertierte Wert in Variablen "convertedValue" speichern
        percent = ((float) convertedValue/1023)*100; //Umrechnen in den Spannungswert
        Lcd_Set_Cursor(2,6);
        sprintf(Buffer,"...%2.0f%% ", percent); //Umwandel des Wertes des floats "percent" in die Zeichenkette "Buffer"
        Lcd_Write_String(Buffer);
        EPWM1_LoadDutyValue(convertedValue);
        //__delay_ms(5);
     }
}
/**
 End of File
 */