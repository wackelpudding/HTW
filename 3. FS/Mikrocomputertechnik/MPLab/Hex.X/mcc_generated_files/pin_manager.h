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

// get/set SEGA aliases
#define SEGA_TRIS               TRISAbits.TRISA0
#define SEGA_LAT                LATAbits.LATA0
#define SEGA_PORT               PORTAbits.RA0
#define SEGA_ANS                ANSELAbits.ANSA0
#define SEGA_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define SEGA_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define SEGA_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define SEGA_GetValue()           PORTAbits.RA0
#define SEGA_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define SEGA_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define SEGA_SetAnalogMode()  do { ANSELAbits.ANSA0 = 1; } while(0)
#define SEGA_SetDigitalMode() do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set SEGB aliases
#define SEGB_TRIS               TRISAbits.TRISA1
#define SEGB_LAT                LATAbits.LATA1
#define SEGB_PORT               PORTAbits.RA1
#define SEGB_ANS                ANSELAbits.ANSA1
#define SEGB_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define SEGB_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define SEGB_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define SEGB_GetValue()           PORTAbits.RA1
#define SEGB_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define SEGB_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define SEGB_SetAnalogMode()  do { ANSELAbits.ANSA1 = 1; } while(0)
#define SEGB_SetDigitalMode() do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set SEGC aliases
#define SEGC_TRIS               TRISAbits.TRISA2
#define SEGC_LAT                LATAbits.LATA2
#define SEGC_PORT               PORTAbits.RA2
#define SEGC_ANS                ANSELAbits.ANSA2
#define SEGC_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define SEGC_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define SEGC_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define SEGC_GetValue()           PORTAbits.RA2
#define SEGC_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define SEGC_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define SEGC_SetAnalogMode()  do { ANSELAbits.ANSA2 = 1; } while(0)
#define SEGC_SetDigitalMode() do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set SEGD aliases
#define SEGD_TRIS               TRISAbits.TRISA3
#define SEGD_LAT                LATAbits.LATA3
#define SEGD_PORT               PORTAbits.RA3
#define SEGD_ANS                ANSELAbits.ANSA3
#define SEGD_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define SEGD_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define SEGD_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define SEGD_GetValue()           PORTAbits.RA3
#define SEGD_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define SEGD_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define SEGD_SetAnalogMode()  do { ANSELAbits.ANSA3 = 1; } while(0)
#define SEGD_SetDigitalMode() do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set SEGE aliases
#define SEGE_TRIS               TRISAbits.TRISA4
#define SEGE_LAT                LATAbits.LATA4
#define SEGE_PORT               PORTAbits.RA4
#define SEGE_ANS                ANSELAbits.ANSA4
#define SEGE_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define SEGE_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define SEGE_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define SEGE_GetValue()           PORTAbits.RA4
#define SEGE_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define SEGE_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define SEGE_SetAnalogMode()  do { ANSELAbits.ANSA4 = 1; } while(0)
#define SEGE_SetDigitalMode() do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set SEGF aliases
#define SEGF_TRIS               TRISAbits.TRISA5
#define SEGF_LAT                LATAbits.LATA5
#define SEGF_PORT               PORTAbits.RA5
#define SEGF_ANS                ANSELAbits.ANSA5
#define SEGF_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define SEGF_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define SEGF_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define SEGF_GetValue()           PORTAbits.RA5
#define SEGF_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define SEGF_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define SEGF_SetAnalogMode()  do { ANSELAbits.ANSA5 = 1; } while(0)
#define SEGF_SetDigitalMode() do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set SEGG aliases
#define SEGG_TRIS               TRISAbits.TRISA6
#define SEGG_LAT                LATAbits.LATA6
#define SEGG_PORT               PORTAbits.RA6
#define SEGG_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define SEGG_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define SEGG_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define SEGG_GetValue()           PORTAbits.RA6
#define SEGG_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define SEGG_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)

// get/set SEGDP aliases
#define SEGDP_TRIS               TRISAbits.TRISA7
#define SEGDP_LAT                LATAbits.LATA7
#define SEGDP_PORT               PORTAbits.RA7
#define SEGDP_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define SEGDP_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define SEGDP_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define SEGDP_GetValue()           PORTAbits.RA7
#define SEGDP_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define SEGDP_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)

// get/set RESET1 aliases
#define RESET1_TRIS               TRISBbits.TRISB1
#define RESET1_LAT                LATBbits.LATB1
#define RESET1_PORT               PORTBbits.RB1
#define RESET1_WPU                WPUBbits.WPUB1
#define RESET1_ANS                ANSELBbits.ANSB1
#define RESET1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RESET1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RESET1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RESET1_GetValue()           PORTBbits.RB1
#define RESET1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RESET1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RESET1_SetPullup()      do { WPUBbits.WPUB1 = 1; } while(0)
#define RESET1_ResetPullup()    do { WPUBbits.WPUB1 = 0; } while(0)
#define RESET1_SetAnalogMode()  do { ANSELBbits.ANSB1 = 1; } while(0)
#define RESET1_SetDigitalMode() do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set RESET2 aliases
#define RESET2_TRIS               TRISBbits.TRISB2
#define RESET2_LAT                LATBbits.LATB2
#define RESET2_PORT               PORTBbits.RB2
#define RESET2_WPU                WPUBbits.WPUB2
#define RESET2_ANS                ANSELBbits.ANSB2
#define RESET2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define RESET2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define RESET2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RESET2_GetValue()           PORTBbits.RB2
#define RESET2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define RESET2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define RESET2_SetPullup()      do { WPUBbits.WPUB2 = 1; } while(0)
#define RESET2_ResetPullup()    do { WPUBbits.WPUB2 = 0; } while(0)
#define RESET2_SetAnalogMode()  do { ANSELBbits.ANSB2 = 1; } while(0)
#define RESET2_SetDigitalMode() do { ANSELBbits.ANSB2 = 0; } while(0)

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


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF1 pin functionality
 * @Example
    IOCBF1_ISR();
 */
void IOCBF1_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF1 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF1 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF1_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF1 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF1_SetInterruptHandler() method.
    This handler is called every time the IOCBF1 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF1_SetInterruptHandler(IOCBF1_InterruptHandler);

*/
extern void (*IOCBF1_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF1 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF1_SetInterruptHandler() method.
    This handler is called every time the IOCBF1 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF1_SetInterruptHandler(IOCBF1_DefaultInterruptHandler);

*/
void IOCBF1_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCBF2 pin functionality
 * @Example
    IOCBF2_ISR();
 */
void IOCBF2_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF2 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF2 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF2_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF2 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF2_SetInterruptHandler() method.
    This handler is called every time the IOCBF2 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF2_SetInterruptHandler(IOCBF2_InterruptHandler);

*/
extern void (*IOCBF2_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF2 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF2_SetInterruptHandler() method.
    This handler is called every time the IOCBF2 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF2_SetInterruptHandler(IOCBF2_DefaultInterruptHandler);

*/
void IOCBF2_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/