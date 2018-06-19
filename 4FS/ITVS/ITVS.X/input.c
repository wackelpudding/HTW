#ifndef INPUT
#define INPUT
#include "input.h"
#include <stdbool.h>
#include "mcc_generated_files/eusart.h"


char data;
    
//Sendet einen String an EUSART
void send_string(const char *x){
    while (*x) {
        EUSART_Write(*x++);
    }
}

float getTemp(void){
    float temp;
    unsigned int sum;
    unsigned char i;
    
    ow_master_reset();
    ow_skip_rom();
    ow_write_byte(0x44);
    __delay_us(800);
    ow_master_reset();
    ow_skip_rom();
    ow_write_byte(0xBE);
    
    
    //Antwort einlesen
    for (i=0; i<9; i++){
        SENSOR[i] = ow_read_byte();
    }
    
    if (SENSOR[1] == 0){   //positive Temp
        temp = SENSOR[0]/5.0;
    } else { //negative Temp
        temp = (~SENSOR[0])+1; // 2er-Komplement
        temp = (temp*(-1))/5; 
    }
    
    sum = 0; // Fehler-Summe löschen
    for(i=0; i<9; i++) sum = sum + SENSOR[i];
    if(sum == 2295) temp = 555; 
           
    return temp;
}

bool GetInput(int in, bool out0, bool out1, bool out2, bool out3){
    bool oldout;
    switch (in) {
        case 0: 
            oldout = out0; 
            out0 = IN0_GetValue();
            
            if (out0 != oldout){
                if (out0){
                    send_string("Der Input 0 ist nun HIGH.\r\n");
                } else {
                    send_string("Der Input 0 ist nun LOW.\r\n");
                }
            }
            return out0;
        case 1: 
            oldout = out1; 
            out1 = IN1_GetValue();
            if (out1 != oldout){
                if (out1){
                    send_string("Der Input 1 ist nun HIGH.\r\n");
                } else {
                    send_string("Der Input 1 ist nun LOW.\r\n");
                }
                
            };            
            return out1;
        case 2:
            oldout = out2;
            out2 = IN2_GetValue();
            if (out2 != oldout){
                if (out2){
                    send_string("Der Input 2 ist nun HIGH.\r\n");
                } else {
                    send_string("Der Input 2 ist nun LOW.\r\n");
                }
            };
            return out2;
        case 3:
            oldout = out3;
            out3 = IN3_GetValue();
            if (out3 != oldout){
                if (out3){
                    send_string("Der Input 3 ist nun HIGH.\r\n");
                } else {
                    send_string("Der Input 3 ist nun LOW.\r\n");
                }
            }
            return out3;
        default: break;
    }
    return NULL;
}



#endif