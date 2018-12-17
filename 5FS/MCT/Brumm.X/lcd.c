#include "lcd.h"
#include <xc.h>
#include "mcc_generated_files/device_config.h"
#include "mcc_generated_files/pin_manager.h"



/* LCD wurde wieder rausgenommen. Es wurde entscheiden, dass nur ein AusgabeMedium 
 * benötigt wird und UART flexibler ist.
*/


void Lcd_Clear()
{
	Lcd_Cmd(0);
	Lcd_Cmd(1);
}

void Lcd_Port(char a)
{
	if(a & 1)
		D4_SetHigh(); 
	else
		D4_SetLow();
	if(a & 2)
		D5_SetHigh();
	else
		D5_SetLow();
	if(a & 4)
		D6_SetHigh();
	else
		D6_SetLow();
	if(a & 8)
		D7_SetHigh();
	else
		D7_SetLow();
}

void Lcd_Cmd(char a)
{
	RS_SetLow();            // => instruction Register
	Lcd_Port(a);
	EN_SetHigh();             // => enabled
    __delay_ms(4);
    EN_SetLow();             // => disabled
}

void Lcd_Set_Cursor(char a, char b)
{
	char temp,z,y;
	if(a == 1)
	{
	  temp = 0x80 + b - 1;
		z = temp>>4;
		y = temp & 0x0F;
		Lcd_Cmd(z);
		Lcd_Cmd(y);
	}
	else if(a == 2)
	{
		temp = 0xC0 + b - 1;
		z = temp>>4;
		y = temp & 0x0F;
		Lcd_Cmd(z);
		Lcd_Cmd(y);
	}
}

void Lcd_Init()
{
  Lcd_Port(0x00);
   __delay_ms(20);
  Lcd_Cmd(0x03);
	__delay_ms(5);
  Lcd_Cmd(0x03);
	__delay_ms(11);
  Lcd_Cmd(0x03);
  Lcd_Cmd(0x02);
  Lcd_Cmd(0x02);
  Lcd_Cmd(0x08);
  Lcd_Cmd(0x00);
  Lcd_Cmd(0x0C);
  Lcd_Cmd(0x00);
  Lcd_Cmd(0x06);
}

void Lcd_Write_Char(char a)
{
   char temp,y;
   temp = a&0x0F;
   y = a&0xF0;
   RS_SetHigh();;             // => RS = 1 , Data Transfer
   Lcd_Port(y>>4);            
   EN_SetHigh();
   __delay_us(40);
   EN_SetLow();
   Lcd_Port(temp);
   EN_SetHigh();
   __delay_us(40);
   EN_SetLow();;
}

void Lcd_Write_String(char *a)
{
	int i;
	for(i=0;a[i]!='\0';i++)     //Iteratives aufrufen der Write-Char-Fkt
	   Lcd_Write_Char(a[i]);
}

/*void Lcd_Reset()
{
    IO_SetHigh();
    __delay_ms(1000);
    IO_SetLow();
    __delay_ms(1000);
    Lcd_Init();
}*/
