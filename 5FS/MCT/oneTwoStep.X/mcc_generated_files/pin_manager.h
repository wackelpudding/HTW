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
        Driver Version    :  2.11
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

// get/set IN1 aliases
#define IN1_TRIS                 TRISAbits.TRISA0
#define IN1_LAT                  LATAbits.LATA0
#define IN1_PORT                 PORTAbits.RA0
#define IN1_ANS                  ANSELAbits.ANSA0
#define IN1_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define IN1_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define IN1_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define IN1_GetValue()           PORTAbits.RA0
#define IN1_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define IN1_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define IN1_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define IN1_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set IN2 aliases
#define IN2_TRIS                 TRISAbits.TRISA1
#define IN2_LAT                  LATAbits.LATA1
#define IN2_PORT                 PORTAbits.RA1
#define IN2_ANS                  ANSELAbits.ANSA1
#define IN2_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define IN2_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define IN2_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define IN2_GetValue()           PORTAbits.RA1
#define IN2_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define IN2_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define IN2_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define IN2_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set IN3 aliases
#define IN3_TRIS                 TRISAbits.TRISA2
#define IN3_LAT                  LATAbits.LATA2
#define IN3_PORT                 PORTAbits.RA2
#define IN3_ANS                  ANSELAbits.ANSA2
#define IN3_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define IN3_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define IN3_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define IN3_GetValue()           PORTAbits.RA2
#define IN3_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define IN3_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define IN3_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define IN3_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set IN4 aliases
#define IN4_TRIS                 TRISAbits.TRISA3
#define IN4_LAT                  LATAbits.LATA3
#define IN4_PORT                 PORTAbits.RA3
#define IN4_ANS                  ANSELAbits.ANSA3
#define IN4_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define IN4_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define IN4_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define IN4_GetValue()           PORTAbits.RA3
#define IN4_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define IN4_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define IN4_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define IN4_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set POT aliases
#define POT_TRIS                 TRISEbits.TRISE0
#define POT_LAT                  LATEbits.LATE0
#define POT_PORT                 PORTEbits.RE0
#define POT_ANS                  ANSELEbits.ANSE0
#define POT_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define POT_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define POT_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define POT_GetValue()           PORTEbits.RE0
#define POT_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define POT_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define POT_SetAnalogMode()      do { ANSELEbits.ANSE0 = 1; } while(0)
#define POT_SetDigitalMode()     do { ANSELEbits.ANSE0 = 0; } while(0)

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