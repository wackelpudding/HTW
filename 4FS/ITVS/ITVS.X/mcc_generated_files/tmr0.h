/**
  TMR0 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr0.h

  @Summary
    This is the generated header file for the TMR0 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for TMR0.
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

#ifndef TMR0_H
#define TMR0_H

/**
  Section: Included Files
*/

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif

/**
  Section: Macro Declarations
*/

#define TMR0_INTERRUPT_TICKER_FACTOR    120

/**
  Section: TMR0 APIs
*/

/**
  @Summary
    Initializes the TMR0 module.

  @Description
    This function initializes the TMR0 Registers.
    This function must be called before any other TMR0 function is called.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Comment
    

  @Example
    <code>
    main()
    {
        // Initialize TMR0 module
        TMR0_Initialize();

        // Do something else...
    }
    </code>
*/
void TMR0_Initialize(void);

/**
  @Summary
    Reads the TMR0 register.

  @Description
    This function reads the TMR0 register value and return it.

  @Preconditions
    Initialize  the TMR0 before calling this function.

  @Param
    None

  @Returns
    This function returns the current value of TMR0 register.

  @Example
    <code>
    // Initialize TMR0 module
    // Read the current value of TMR0
    if(0 == TMR0_ReadTimer())
    {
        // Do something else...

        // Reload the TMR value
        TMR0_Reload();
    }
    </code>
*/
uint8_t TMR0_ReadTimer(void);

/**
  @Summary
    Writes the TMR0 register.

  @Description
    This function writes the TMR0 register.
    This function must be called after the initialization of TMR0.

  @Preconditions
    Initialize  the TMR0 before calling this function.

  @Param
    timerVal - Value to write into TMR0 register.

  @Returns
    None

  @Example
    <code>
    #define PERIOD 0x80
    #define ZERO   0x00

    while(1)
    {
        // Read the TMR0 register
        if(ZERO == TMR0_ReadTimer())
        {
            // Do something else...

            // Write the TMR0 register
            TMR0_WriteTimer(PERIOD);
        }

        // Do something else...
    }
    </code>
*/
void TMR0_WriteTimer(uint8_t timerVal);

/**
  @Summary
    Reload the TMR0 register.

  @Description
    This function reloads the TMR0 register.
    This function must be called to write initial value into TMR0 register.

  @Preconditions
    Initialize  the TMR0 before calling this function.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    while(1)
    {
        if(TMR0IF)
        {
            // Do something else...

            // clear the TMR0 interrupt flag
            TMR0IF = 0;

            // Reload the initial value of TMR0
            TMR0_Reload();
        }
    }
    </code>
*/
void TMR0_Reload(void);

/**
  @Summary
    Timer Interrupt Service Routine

  @Description
    Timer Interrupt Service Routine is called by the Interrupt Manager.

  @Returns
    None

  @Param
    None
*/
void TMR0_ISR(void);

/**
  @Summary
    CallBack function.

  @Description
    This routine is called by the Interrupt Manager.

  @Preconditions
    None

  @Param
    None

  @Returns
    None
*/
void TMR0_CallBack(void);

/**
  @Summary
    Set Timer Interrupt Handler

  @Description
    This sets the function to be called during the ISR

  @Preconditions
    Initialize  the TMR0 module with interrupt before calling this.

  @Param
    Address of function to be set

  @Returns
    None
*/
 void TMR0_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Timer Interrupt Handler

  @Description
    This is a function pointer to the function that will be called during the ISR

  @Preconditions
    Initialize  the TMR0 module with interrupt before calling this isr.

  @Param
    None

  @Returns
    None
*/
extern void (*TMR0_InterruptHandler)(void);

/**
  @Summary
    Default Timer Interrupt Handler

  @Description
    This is the default Interrupt Handler function

  @Preconditions
    Initialize  the TMR0 module with interrupt before calling this isr.

  @Param
    None

  @Returns
    None
*/
void TMR0_DefaultInterruptHandler(void);

#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif

#endif // TMR0_H
/**
 End of File
*/
