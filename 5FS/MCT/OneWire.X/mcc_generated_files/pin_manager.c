/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F1937
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB             :  MPLAB X 4.15

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.
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

#include <xc.h>
#include "pin_manager.h"
#include "stdbool.h"
#include "mcc.h"




void (*IOCBF0_InterruptHandler)(void);
void (*IOCBF1_InterruptHandler)(void);


void PIN_MANAGER_Initialize(void)
{
    /**
    LATx registers
    */
    LATE = 0x00;
    LATD = 0x00;
    LATA = 0x00;
    LATB = 0x00;
    LATC = 0x00;

    /**
    TRISx registers
    */
    TRISE = 0x0D;
    TRISA = 0xF9;
    TRISB = 0xFF;
    TRISC = 0xB7;
    TRISD = 0xFF;

    /**
    ANSELx registers
    */
    ANSELD = 0xFF;
    ANSELB = 0x3C;
    ANSELE = 0x05;
    ANSELA = 0x00;

    /**
    WPUx registers
    */
    WPUE = 0x00;
    WPUB = 0x00;
    OPTION_REGbits.nWPUEN = 1;

    /**
    ODx registers
    */

    /**
    APFCONx registers
    */
    APFCON = 0x00;

    /**
    IOCx registers 
    */
    //interrupt on change for group IOCBF - flag
    IOCBFbits.IOCBF0 = 0;
    //interrupt on change for group IOCBF - flag
    IOCBFbits.IOCBF1 = 0;
    //interrupt on change for group IOCBN - negative
    IOCBNbits.IOCBN0 = 0;
    //interrupt on change for group IOCBN - negative
    IOCBNbits.IOCBN1 = 0;
    //interrupt on change for group IOCBP - positive
    IOCBPbits.IOCBP0 = 1;
    //interrupt on change for group IOCBP - positive
    IOCBPbits.IOCBP1 = 1;



    // register default IOC callback functions at runtime; use these methods to register a custom function
    IOCBF0_SetInterruptHandler(IOCBF0_DefaultInterruptHandler);
    IOCBF1_SetInterruptHandler(IOCBF1_DefaultInterruptHandler);
   
    // Enable IOCI interrupt 
    INTCONbits.IOCIE = 1; 
    
}
  
void PIN_MANAGER_IOC(void)
{   
	// interrupt on change for pin IOCBF0
    if(IOCBFbits.IOCBF0 == 1)
    {
        IOCBF0_ISR();  
    }	
	// interrupt on change for pin IOCBF1
    if(IOCBFbits.IOCBF1 == 1)
    {
        IOCBF1_ISR();  
    }	
}

/**
   IOCBF0 Interrupt Service Routine
*/
void IOCBF0_ISR(void) {

    // Add custom IOCBF0 code
    /**
    if (!K1_GetValue()){
            LED1_SetHigh();
            __delay_ms(300);
            K1_SetHigh();
            printf("%c[2K", 27);
            send_string("Relais K1 ist nun aktiv\r");
        }   else {
            LED1_SetLow();
            __delay_ms(300); 
            K1_SetLow();
            printf("%c[2K", 27);
            send_string("Relais K1 ist nun inaktiv\r");
    }*/

    // Call the interrupt handler for the callback registered at runtime
    if(IOCBF0_InterruptHandler)
    {
        IOCBF0_InterruptHandler();
    }
    IOCBFbits.IOCBF0 = 0;
}

/**
  Allows selecting an interrupt handler for IOCBF0 at application runtime
*/
void IOCBF0_SetInterruptHandler(void (* InterruptHandler)(void)){
    IOCBF0_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCBF0
*/
void IOCBF0_DefaultInterruptHandler(void){
    // add your IOCBF0 interrupt custom code
    // or set custom function using IOCBF0_SetInterruptHandler()
}

/**
   IOCBF1 Interrupt Service Routine
*/
void IOCBF1_ISR(void) {

    // Add custom IOCBF1 code


    // Call the interrupt handler for the callback registered at runtime
    if(IOCBF1_InterruptHandler)
    {
        IOCBF1_InterruptHandler();
    }
    IOCBFbits.IOCBF1 = 0;
}

/**
  Allows selecting an interrupt handler for IOCBF1 at application runtime
*/
void IOCBF1_SetInterruptHandler(void (* InterruptHandler)(void)){
    IOCBF1_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCBF1
*/
void IOCBF1_DefaultInterruptHandler(void){
    // add your IOCBF1 interrupt custom code
    // or set custom function using IOCBF1_SetInterruptHandler()
}

/**
 End of File
*/