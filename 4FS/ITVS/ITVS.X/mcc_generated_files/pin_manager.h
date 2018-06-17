/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC16F1937
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.45
        MPLAB 	          :  MPLAB X 4.15	
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

// get/set K1 aliases
#define K1_TRIS                 TRISAbits.TRISA1
#define K1_LAT                  LATAbits.LATA1
#define K1_PORT                 PORTAbits.RA1
#define K1_ANS                  ANSELAbits.ANSA1
#define K1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define K1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define K1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define K1_GetValue()           PORTAbits.RA1
#define K1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define K1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define K1_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define K1_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set K2 aliases
#define K2_TRIS                 TRISAbits.TRISA2
#define K2_LAT                  LATAbits.LATA2
#define K2_PORT                 PORTAbits.RA2
#define K2_ANS                  ANSELAbits.ANSA2
#define K2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define K2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define K2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define K2_GetValue()           PORTAbits.RA2
#define K2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define K2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define K2_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define K2_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set TEMP aliases
#define TEMP_TRIS                 TRISAbits.TRISA3
#define TEMP_LAT                  LATAbits.LATA3
#define TEMP_PORT                 PORTAbits.RA3
#define TEMP_ANS                  ANSELAbits.ANSA3
#define TEMP_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define TEMP_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define TEMP_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define TEMP_GetValue()           PORTAbits.RA3
#define TEMP_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define TEMP_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define TEMP_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define TEMP_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set IN0 aliases
#define IN0_TRIS                 TRISAbits.TRISA4
#define IN0_LAT                  LATAbits.LATA4
#define IN0_PORT                 PORTAbits.RA4
#define IN0_ANS                  ANSELAbits.ANSA4
#define IN0_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define IN0_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define IN0_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define IN0_GetValue()           PORTAbits.RA4
#define IN0_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define IN0_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define IN0_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define IN0_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set IN1 aliases
#define IN1_TRIS                 TRISAbits.TRISA5
#define IN1_LAT                  LATAbits.LATA5
#define IN1_PORT                 PORTAbits.RA5
#define IN1_ANS                  ANSELAbits.ANSA5
#define IN1_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define IN1_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define IN1_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define IN1_GetValue()           PORTAbits.RA5
#define IN1_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define IN1_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define IN1_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define IN1_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set IN2 aliases
#define IN2_TRIS                 TRISAbits.TRISA6
#define IN2_LAT                  LATAbits.LATA6
#define IN2_PORT                 PORTAbits.RA6
#define IN2_ANS                  ANSELAbits.ANSA6
#define IN2_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define IN2_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define IN2_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define IN2_GetValue()           PORTAbits.RA6
#define IN2_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define IN2_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define IN2_SetAnalogMode()      do { ANSELAbits.ANSA6 = 1; } while(0)
#define IN2_SetDigitalMode()     do { ANSELAbits.ANSA6 = 0; } while(0)


// get/set IN3 aliases
#define IN3_TRIS                 TRISAbits.TRISA7
#define IN3_LAT                  LATAbits.LATA7
#define IN3_PORT                 PORTAbits.RA7
#define IN3_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define IN3_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define IN3_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define IN3_GetValue()           PORTAbits.RA7
#define IN3_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define IN3_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)

// get/set TASTER1 aliases
#define TASTER1_TRIS                 TRISBbits.TRISB0
#define TASTER1_LAT                  LATBbits.LATB0
#define TASTER1_PORT                 PORTBbits.RB0
#define TASTER1_WPU                  WPUBbits.WPUB0
#define TASTER1_ANS                  ANSELBbits.ANSB0
#define TASTER1_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define TASTER1_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define TASTER1_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define TASTER1_GetValue()           PORTBbits.RB0
#define TASTER1_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define TASTER1_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define TASTER1_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define TASTER1_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define TASTER1_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define TASTER1_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set TASTER2 aliases
#define TASTER2_TRIS                 TRISBbits.TRISB1
#define TASTER2_LAT                  LATBbits.LATB1
#define TASTER2_PORT                 PORTBbits.RB1
#define TASTER2_WPU                  WPUBbits.WPUB1
#define TASTER2_ANS                  ANSELBbits.ANSB1
#define TASTER2_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define TASTER2_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define TASTER2_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define TASTER2_GetValue()           PORTBbits.RB1
#define TASTER2_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define TASTER2_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define TASTER2_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define TASTER2_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define TASTER2_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define TASTER2_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set LED1 aliases
#define LED1_TRIS                 TRISCbits.TRISC3
#define LED1_LAT                  LATCbits.LATC3
#define LED1_PORT                 PORTCbits.RC3
#define LED1_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define LED1_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define LED1_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define LED1_GetValue()           PORTCbits.RC3
#define LED1_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define LED1_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()               do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()                do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()                do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()       do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()      do { TRISCbits.TRISC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()               do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()                do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()                do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()       do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()      do { TRISCbits.TRISC7 = 0; } while(0)

// get/set LED2 aliases
#define LED2_TRIS                 TRISEbits.TRISE1
#define LED2_LAT                  LATEbits.LATE1
#define LED2_PORT                 PORTEbits.RE1
#define LED2_ANS                  ANSELEbits.ANSE1
#define LED2_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define LED2_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define LED2_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define LED2_GetValue()           PORTEbits.RE1
#define LED2_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define LED2_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define LED2_SetAnalogMode()      do { ANSELEbits.ANSE1 = 1; } while(0)
#define LED2_SetDigitalMode()     do { ANSELEbits.ANSE1 = 0; } while(0)

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
    Interrupt on Change Handler for the IOCBF0 pin functionality
 * @Example
    IOCBF0_ISR();
 */
void IOCBF0_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCBF0 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCBF0 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF0_SetInterruptHandler(MyInterruptHandler);

*/
void IOCBF0_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCBF0 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCBF0_SetInterruptHandler() method.
    This handler is called every time the IOCBF0 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF0_SetInterruptHandler(IOCBF0_InterruptHandler);

*/
extern void (*IOCBF0_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCBF0 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCBF0_SetInterruptHandler() method.
    This handler is called every time the IOCBF0 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCBF0_SetInterruptHandler(IOCBF0_DefaultInterruptHandler);

*/
void IOCBF0_DefaultInterruptHandler(void);


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



#endif // PIN_MANAGER_H
/**
 End of File
*/