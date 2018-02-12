/**
  Generated Pin Manager File

  Company:
    Microchip Technology Inc.

  File Name:
    pin_manager.c

  Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.35
        Device            :  PIC16F1937
        Driver Version    :  1.02
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/

#include <xc.h>
#include "stdbool.h"
#include "mcc.h"


void (*IOCBF1_InterruptHandler)(void);
void (*IOCBF2_InterruptHandler)(void);


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
    TRISA = 0x00;
    TRISB = 0xFF;
    TRISC = 0xF7;
    TRISD = 0xFF;

    /**
    ANSELx registers
    */   
    ANSELB = 0x39;
    ANSELD = 0xFF;
    ANSELE = 0x05;
    ANSELA = 0x00;

    /**
    WPUx registers
    */ 
    WPUE = 0x08;
    WPUB = 0xF9;
    OPTION_REGbits.nWPUEN = 1;

    
    /**
    APFCONx registers
    */
    APFCON = 0x00;

    /**
    IOCx registers
    */
    // interrupt on change for group IOCBF - flag
    IOCBFbits.IOCBF1 = 0;
    IOCBFbits.IOCBF2 = 0;
    // interrupt on change for group IOCBN - negative
    IOCBNbits.IOCBN1 = 0;
    IOCBNbits.IOCBN2 = 0;
    // interrupt on change for group IOCBP - positive
    IOCBPbits.IOCBP1 = 1;
    IOCBPbits.IOCBP2 = 1;

    // register default IOC callback functions at runtime; use these methods to register a custom function
    IOCBF1_SetInterruptHandler(IOCBF1_DefaultInterruptHandler);
    IOCBF2_SetInterruptHandler(IOCBF2_DefaultInterruptHandler);
   
    // Enable IOCI interrupt 
    INTCONbits.IOCIE = 1; 
    
}       

void PIN_MANAGER_IOC(void)
{   
    // interrupt on change for pin IOCBF1
    if(IOCBFbits.IOCBF1 == 1)
    {
        IOCBF1_ISR();  
    }                          

    // interrupt on change for pin IOCBF2
    if(IOCBFbits.IOCBF2 == 1)
    {
        IOCBF2_ISR();  
    }                          


}

/**
   IOCBF1 Interrupt Service Routine
*/
void IOCBF1_ISR(void) {

    // Add custom IOCBF1 code
    runterzaehlen();
    ausgabe(zaehler);
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
   IOCBF2 Interrupt Service Routine
*/
void IOCBF2_ISR(void) {

    // Add custom IOCBF2 code
    hochzaehlen();
    ausgabe(zaehler);
    // Call the interrupt handler for the callback registered at runtime
    if(IOCBF2_InterruptHandler)
    {
        IOCBF2_InterruptHandler();
    }
    IOCBFbits.IOCBF2 = 0;
}

/**
  Allows selecting an interrupt handler for IOCBF2 at application runtime
*/
void IOCBF2_SetInterruptHandler(void (* InterruptHandler)(void)){
    IOCBF2_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCBF2
*/
void IOCBF2_DefaultInterruptHandler(void){
    // add your IOCBF2 interrupt custom code
    // or set custom function using IOCBF2_SetInterruptHandler()
}

/**
 End of File
*/