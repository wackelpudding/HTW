
#include "motor.h"
#include <xc.h>  
#include "mcc_generated_files/device_config.h"
#include "mcc_generated_files/pin_manager.h"
#include <stdint.h>
#include <stdbool.h>

void EUSART_Initialize(void)
{
    // Set the EUSART module to the options selected in the user interface.

    // ABDOVF no_overflow; SCKP Non-Inverted; BRG16 16bit_generator; WUE disabled; ABDEN disabled; 
    BAUDCON = 0x08;

    // SPEN enabled; RX9 8-bit; CREN enabled; ADDEN disabled; SREN disabled; 
    RCSTA = 0x90;

    // TX9 8-bit; TX9D 0; SENDB sync_break_complete; TXEN enabled; SYNC asynchronous; BRGH hi_speed; CSRC slave; 
    TXSTA = 0x24;

    // SPBRGL 103; 
    SPBRGL = 0x67;

    // SPBRGH 0; 
    SPBRGH = 0x00;


}

/*uint8_t EUSART_Read(void)
{
    while(!PIR1bits.RCIF)
    {
    }

    
    if(1 == RCSTAbits.OERR)
    {
        // EUSART error - restart

        RCSTAbits.CREN = 0; 
        RCSTAbits.CREN = 1; 
    }

    return RCREG;
}*/



void EUSART_Write(uint8_t txData)
{
    while(0 == PIR1bits.TXIF)
    {
    }

    TXREG = txData;    // Write the data byte to the USART.
}

/*char getch(void)
{
    return EUSART_Read();
}*/

/*void putch(char txData)
{
    EUSART_Write(txData);
}*/

void send_string(const char *x){
    while (*x) {
        EUSART_Write(*x++);
    }
}

void conv_int_to_string(uint8_t integer){
    char result[3] = "";
    uint8_t rest;
    for (uint8_t i = 0; i < 3; i++) {
        rest = integer % 10;
        integer = integer / 10;
        result[2-i] = rest + 48;
    }
    if (result[0] == 48){
        result[0] = 32; 
    }
    if (result[1] == 48){
        result[1] = 32; 
    }
    for (uint8_t i = 0; i < 3; i++) {
        EUSART_Write(result[i]);
    }
    
    //return result;
}