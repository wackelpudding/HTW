#ifndef INPUT_C
#define INPUT_C
#include "input.h"


extern unsigned char SENSOR[9];
    
//Sendet einen String an EUSART
void send_string(const char *x){
    while (*x) {
        EUSART_Write(*x++);
    }
}

int getTemp(void){
    int temp;
    unsigned int sum;
    unsigned char i;
    
    ow_master_reset();
    ow_skip_rom();
    //sende "Convert T" an den DS18B20
    ow_write_byte(0x44); 
    __delay_us(800);
    ow_master_reset();
    ow_skip_rom();
    //sende befehl "READ SCRATCHPAD" an DS18B20
    ow_write_byte(0xBE); 
    
    
    //Antwort einlesen
    for (i=0; i<9; i++){
        SENSOR[i] = ow_read_byte();
    }
    SENSOR[0] >>= 1;
    if (SENSOR[1] & 0xF8) {                                 // Negativer Temperaturwert
        SENSOR[0] ^= 0xFF;                                     // Einer-Komplement
        SENSOR[0]++;                                           // inkrementieren
        SENSOR[1] ^= 0xFF;                                     // Einer-Komplement
        temp = -(((int) SENSOR[1] << 8) | (int) SENSOR[0]) * 10 / 16;
    } else {
        temp = (((int) SENSOR[1] << 8) | (int) SENSOR[0]) * 10 / 16;
    }
           
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
                    printf("%c[2K", 27);
                    send_string("Der Input 0 ist nun HIGH.\r");
                } else {
                    printf("%c[2K", 27);
                    send_string("Der Input 0 ist nun LOW.\r");
                }
            }
            return out0;
        case 1: 
            oldout = out1; 
            out1 = IN1_GetValue();
            if (out1 != oldout){
                if (out1){
                    printf("%c[2K", 27);
                    send_string("Der Input 1 ist nun HIGH.\r");
                } else {
                    printf("%c[2K", 27);
                    send_string("Der Input 1 ist nun LOW.\r");
                }
                
            };            
            return out1;
        case 2:
            oldout = out2;
            out2 = IN2_GetValue();
            if (out2 != oldout){
                if (out2){
                    printf("%c[2K", 27);
                    send_string("Der Input 2 ist nun HIGH.\r");
                } else {
                    printf("%c[2K", 27);
                    send_string("Der Input 2 ist nun LOW.\r");
                }
            };
            return out2;
        case 3:
            oldout = out3;
            out3 = IN3_GetValue();
            if (out3 != oldout){
                if (out3){
                    printf("%c[2K", 27);
                    send_string("Der Input 3 ist nun HIGH.\r");
                } else {
                    printf("%c[2K", 27);
                    send_string("Der Input 3 ist nun LOW.\r");
                }
            }
            return out3;
        default: break;
    }
    return NULL;
}



#endif