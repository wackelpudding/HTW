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

// get/set RS aliases
#define RS_TRIS                 TRISAbits.TRISA0
#define RS_LAT                  LATAbits.LATA0
#define RS_PORT                 PORTAbits.RA0
#define RS_ANS                  ANSELAbits.ANSA0
#define RS_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define RS_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define RS_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define RS_GetValue()           PORTAbits.RA0
#define RS_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define RS_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define RS_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define RS_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set RW aliases
#define RW_TRIS                 TRISAbits.TRISA1
#define RW_LAT                  LATAbits.LATA1
#define RW_PORT                 PORTAbits.RA1
#define RW_ANS                  ANSELAbits.ANSA1
#define RW_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define RW_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define RW_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define RW_GetValue()           PORTAbits.RA1
#define RW_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define RW_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define RW_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define RW_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set D4 aliases
#define D4_TRIS                 TRISAbits.TRISA2
#define D4_LAT                  LATAbits.LATA2
#define D4_PORT                 PORTAbits.RA2
#define D4_ANS                  ANSELAbits.ANSA2
#define D4_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define D4_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define D4_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define D4_GetValue()           PORTAbits.RA2
#define D4_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define D4_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define D4_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define D4_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set D5 aliases
#define D5_TRIS                 TRISAbits.TRISA3
#define D5_LAT                  LATAbits.LATA3
#define D5_PORT                 PORTAbits.RA3
#define D5_ANS                  ANSELAbits.ANSA3
#define D5_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define D5_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define D5_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define D5_GetValue()           PORTAbits.RA3
#define D5_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define D5_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define D5_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define D5_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set D6 aliases
#define D6_TRIS                 TRISAbits.TRISA4
#define D6_LAT                  LATAbits.LATA4
#define D6_PORT                 PORTAbits.RA4
#define D6_ANS                  ANSELAbits.ANSA4
#define D6_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define D6_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define D6_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define D6_GetValue()           PORTAbits.RA4
#define D6_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define D6_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define D6_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define D6_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set D7 aliases
#define D7_TRIS                 TRISAbits.TRISA5
#define D7_LAT                  LATAbits.LATA5
#define D7_PORT                 PORTAbits.RA5
#define D7_ANS                  ANSELAbits.ANSA5
#define D7_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define D7_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define D7_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define D7_GetValue()           PORTAbits.RA5
#define D7_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define D7_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define D7_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define D7_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set IO aliases
#define IO_TRIS                 TRISAbits.TRISA6
#define IO_LAT                  LATAbits.LATA6
#define IO_PORT                 PORTAbits.RA6
#define IO_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define IO_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define IO_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define IO_GetValue()           PORTAbits.RA6
#define IO_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define IO_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)

// get/set EN aliases
#define EN_TRIS                 TRISAbits.TRISA7
#define EN_LAT                  LATAbits.LATA7
#define EN_PORT                 PORTAbits.RA7
#define EN_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define EN_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define EN_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define EN_GetValue()           PORTAbits.RA7
#define EN_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define EN_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)

// get/set IN1 aliases
#define IN1_TRIS                 TRISCbits.TRISC0
#define IN1_LAT                  LATCbits.LATC0
#define IN1_PORT                 PORTCbits.RC0
#define IN1_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define IN1_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define IN1_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define IN1_GetValue()           PORTCbits.RC0
#define IN1_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define IN1_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)

// get/set IN2 aliases
#define IN2_TRIS                 TRISCbits.TRISC1
#define IN2_LAT                  LATCbits.LATC1
#define IN2_PORT                 PORTCbits.RC1
#define IN2_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define IN2_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define IN2_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define IN2_GetValue()           PORTCbits.RC1
#define IN2_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define IN2_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)

// get/set RC2 procedures
#define RC2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define RC2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define RC2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RC2_GetValue()              PORTCbits.RC2
#define RC2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define RC2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)

// get/set LED aliases
#define LED_TRIS                 TRISCbits.TRISC3
#define LED_LAT                  LATCbits.LATC3
#define LED_PORT                 PORTCbits.RC3
#define LED_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define LED_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define LED_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define LED_GetValue()           PORTCbits.RC3
#define LED_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)

// get/set RD5 procedures
#define RD5_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define RD5_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define RD5_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define RD5_GetValue()              PORTDbits.RD5
#define RD5_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define RD5_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define RD5_SetAnalogMode()         do { ANSELDbits.ANSD5 = 1; } while(0)
#define RD5_SetDigitalMode()        do { ANSELDbits.ANSD5 = 0; } while(0)

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

// get/set BUZZER aliases
#define BUZZER_TRIS                 TRISEbits.TRISE2
#define BUZZER_LAT                  LATEbits.LATE2
#define BUZZER_PORT                 PORTEbits.RE2
#define BUZZER_ANS                  ANSELEbits.ANSE2
#define BUZZER_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define BUZZER_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define BUZZER_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define BUZZER_GetValue()           PORTEbits.RE2
#define BUZZER_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define BUZZER_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define BUZZER_SetAnalogMode()      do { ANSELEbits.ANSE2 = 1; } while(0)
#define BUZZER_SetDigitalMode()     do { ANSELEbits.ANSE2 = 0; } while(0)

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