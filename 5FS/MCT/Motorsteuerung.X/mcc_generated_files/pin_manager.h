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