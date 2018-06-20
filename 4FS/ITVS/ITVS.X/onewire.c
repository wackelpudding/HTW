#ifndef ONEWIRE_C
#define ONEWIRE_C
#include "mcc_generated_files/mcc.h"

unsigned char SENSOR [9];


unsigned char ow_master_reset (void)
{
    unsigned char rec;
    TEMP_LAT = 0;             // set the (I)O to low level
    TEMP_TRIS = 0;            // config the DQ-IO as output (-> low)
    __delay_us(490);        // delay of >480 us
    TEMP_TRIS = 1;            // config the  DQ-IO as input (high-z -> pull up)
    __delay_us(40);
    rec = TEMP_GetValue();               // read the level (if low, slave available)
    __delay_us(450);        // wait for end of slot
    return (rec);
}

void ow_write_bit (unsigned char val)
{
	TEMP_LAT = 0;						// set the (I)O to low level
    TEMP_TRIS = 0;                    // config the DQ-IO as output (-> low)

    if(val)                    		// if the bit to transfer is a "1"
    {
        __delay_us(1);				// wait 1 us and..
        TEMP_TRIS = 1;                // ..config the  DQ-IO as input (high-z -> pull up)
    }

    __delay_us(100);                // wait for end of slot

    TEMP_TRIS = 1;                    // config the  DQ-IO as input (high-z -> pull up)
}

/*******************************************************************************
One_Wire_Write_Byte
--------------------------------------------------------------------------------
This function will write a complete byte on the bus.
*******************************************************************************/

void ow_write_byte (unsigned char val)
{
    unsigned char i, mask = 1;

	// write the byte by sending eight bits (LSB first)
    for (i=0; i<8; i++)
    {
            ow_write_bit(val & mask);
            mask = (mask << 1);
    }
}

unsigned char ow_read_bit (void)
{
    unsigned char rec;

									// perform a very short low impuls
    TEMP_TRIS = 0;					// config the DQ-IO as output (-> low)
    TEMP_TRIS = 1;                    // config the  DQ-IO as input (high-z -> pull up)

    __delay_us(15);
    rec = TEMP_GetValue();                       // read the level on DQ (this is the read bit)
    __delay_us(105);                // wait for end of slot

    return(rec);
}

/*******************************************************************************
One_Wire_Read_Byte
--------------------------------------------------------------------------------
This function will read a complete byte from the bus.
*******************************************************************************/

unsigned char ow_read_byte (void)
{
    unsigned char value = 0 , i;

    // read the byte by reading eight bits (LSB first)
    for(i=0; i<8; i++)
    {
        if ( ow_read_bit() )
        {
            value |= 0x01 << i;
        }
    }

    return(value);
}

    //send the skip rom command to the onewire bus
void ow_skip_rom(void)
{
    ow_write_byte(0xCC);
}

#endif