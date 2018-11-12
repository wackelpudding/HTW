/* 
 * File:   motor.h
 * Author: Ricardo
 *
 * Created on October 23, 2018, 10:59 AM
 */

#ifndef MOTOR_H
#define	MOTOR_H

#include <stdint.h>
#include <stdbool.h>

//#define EUSART_DataReady  (EUSART_is_rx_ready())

/**
  @Summary
    Initialization routine that takes inputs from the EUSART GUI.

  @Description
    This routine initializes the EUSART driver.
    This routine must be called before any other EUSART routine is called.

  @Preconditions
    None

  @Param
    None

  @Returns
    None

  @Comment
    
*/
void EUSART_Initialize(void);

/**
  @Summary
    Checks if the EUSART transmitter is ready to transmit data

  @Description
    This routine checks if EUSART transmitter is ready 
    to accept and transmit data byte

  @Preconditions
    EUSART_Initialize() function should have been called
    before calling this function.
    EUSART transmitter should be enabled before calling 
    this function

  @Param
    None

  @Returns
    Status of EUSART transmitter
    TRUE: EUSART transmitter is ready
    FALSE: EUSART transmitter is not ready
    
  @Example
    <code>
    void main(void)
    {
        volatile uint8_t rxData;
        
        // Initialize the device
        SYSTEM_Initialize();
        
        while(1)
        {
            // Logic to echo received data
            if(EUSART_is_rx_ready())
            {
                rxData = UART1_Read();
                if(EUSART_is_tx_ready())
                {
                    EUSARTWrite(rxData);
                }
            }
        }
    }
    </code>
*/
bool EUSART_is_tx_ready(void);

/**
  @Summary
    Read a byte of data from the EUSART.

  @Description
    This routine reads a byte of data from the EUSART.

  @Preconditions
    EUSART_Initialize() function should have been called
    before calling this function. The transfer status should be checked to see
    if the receiver is not empty before calling this function.

  @Param
    None

  @Returns
    A data byte received by the driver.
*/
uint8_t EUSART_Read(void);

 /**
  @Summary
    Writes a byte of data to the EUSART.

  @Description
    This routine writes a byte of data to the EUSART.

  @Preconditions
    EUSART_Initialize() function should have been called
    before calling this function. The transfer status should be checked to see
    if transmitter is not busy before calling this function.

  @Param
    txData  - Data byte to write to the EUSART

  @Returns
    None
*/
void EUSART_Write(uint8_t txData);

void send_string(const char *x);

void conv_int_to_string(uint8_t integer);


#endif	/* MOTOR_H */

