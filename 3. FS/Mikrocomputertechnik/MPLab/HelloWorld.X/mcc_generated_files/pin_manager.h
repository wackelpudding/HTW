/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.35
        Device            :  PIC16F1937
        Version           :  1.01
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


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set TASTER1 aliases
#define TASTER1_TRIS               TRISCbits.TRISC0
#define TASTER1_LAT                LATCbits.LATC0
#define TASTER1_PORT               PORTCbits.RC0
#define TASTER1_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define TASTER1_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define TASTER1_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define TASTER1_GetValue()           PORTCbits.RC0
#define TASTER1_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define TASTER1_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)

// get/set TASTER2 aliases
#define TASTER2_TRIS               TRISCbits.TRISC1
#define TASTER2_LAT                LATCbits.LATC1
#define TASTER2_PORT               PORTCbits.RC1
#define TASTER2_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define TASTER2_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define TASTER2_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define TASTER2_GetValue()           PORTCbits.RC1
#define TASTER2_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define TASTER2_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set LED2 aliases
#define LED2_TRIS               TRISCbits.TRISC3
#define LED2_LAT                LATCbits.LATC3
#define LED2_PORT               PORTCbits.RC3
#define LED2_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define LED2_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define LED2_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define LED2_GetValue()           PORTCbits.RC3
#define LED2_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)

// get/set POTI aliases
#define POTI_TRIS               TRISEbits.TRISE0
#define POTI_LAT                LATEbits.LATE0
#define POTI_PORT               PORTEbits.RE0
#define POTI_ANS                ANSELEbits.ANSE0
#define POTI_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define POTI_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define POTI_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define POTI_GetValue()           PORTEbits.RE0
#define POTI_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define POTI_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define POTI_SetAnalogMode()  do { ANSELEbits.ANSE0 = 1; } while(0)
#define POTI_SetDigitalMode() do { ANSELEbits.ANSE0 = 0; } while(0)

// get/set LED1 aliases
#define LED1_TRIS               TRISEbits.TRISE1
#define LED1_LAT                LATEbits.LATE1
#define LED1_PORT               PORTEbits.RE1
#define LED1_ANS                ANSELEbits.ANSE1
#define LED1_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define LED1_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define LED1_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define LED1_GetValue()           PORTEbits.RE1
#define LED1_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define LED1_SetAnalogMode()  do { ANSELEbits.ANSE1 = 1; } while(0)
#define LED1_SetDigitalMode() do { ANSELEbits.ANSE1 = 0; } while(0)

// get/set BUZZ aliases
#define BUZZ_TRIS               TRISEbits.TRISE2
#define BUZZ_LAT                LATEbits.LATE2
#define BUZZ_PORT               PORTEbits.RE2
#define BUZZ_ANS                ANSELEbits.ANSE2
#define BUZZ_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define BUZZ_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define BUZZ_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define BUZZ_GetValue()           PORTEbits.RE2
#define BUZZ_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define BUZZ_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define BUZZ_SetAnalogMode()  do { ANSELEbits.ANSE2 = 1; } while(0)
#define BUZZ_SetDigitalMode() do { ANSELEbits.ANSE2 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/