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


// get/set K2 aliases
#define K2_TRIS                 TRISAbits.TRISA1
#define K2_LAT                  LATAbits.LATA1
#define K2_PORT                 PORTAbits.RA1
#define K2_ANS                  ANSELAbits.ANSA1
#define K2_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define K2_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define K2_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define K2_GetValue()           PORTAbits.RA1
#define K2_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define K2_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define K2_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define K2_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

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