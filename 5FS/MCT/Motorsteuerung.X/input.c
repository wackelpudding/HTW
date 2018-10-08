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

    //OW Bus INIT
    ow_master_reset();
    ow_skip_rom();
    //sende "Convert T" an den DS18B20
    ow_write_byte(0x44);
    //warte mindestens 790 us f�r verarbeitung der Daten
    __delay_us(800);
    //OW Bus INIT
    ow_master_reset();
    ow_skip_rom();
    //sende befehl "READ SCRATCHPAD" an DS18B20
    ow_write_byte(0xBE);


    //Antwort einlesen
    for (i=0; i<9; i++){
        //Lese alle 9 Bytes vom OW Bus ein und speicher Sie im Array SENSOR
        SENSOR[i] = ow_read_byte();
    }

    //SENSOR[0] >>= 1;
    if (SENSOR[1] & 0xF8) {           // Negativer Temperaturwert
        SENSOR[0] ^= 0xFF;            // Einer-Komplement
        SENSOR[0]++;                  // inkrementieren
        SENSOR[1] ^= 0xFF;            // Einer-Komplement
        //berechnung der Temperatur
        temp = -(((int) SENSOR[1] << 8) | (int) SENSOR[0]) * 10 / 16;
    } else {
        //berechnung der Temperatur
        temp = (((int) SENSOR[1] << 8) | (int) SENSOR[0]) * 10 / 16;
    }

    return temp;
}



bool GetInput(int in, bool out0, bool out1, bool out2, bool out3){
    //temp var
    bool oldout;
    //switch case fuer die inputabfrage
    switch (in) {
        case 0:
            //alter zustand zwischenspeichern
            oldout = out0;
            //Input abfragen
            out0 = IN0_GetValue();

            if (out0 != oldout){
                printf("%c[2K", 27);
                printf("Der Input 1 ist nun %s.", out0 ? "HIGH" : "LOW" );
                if (in0){
                    K1_PORT = out0;
                    LED1_PORT = out0;
                    printf(" : K1 => %s\r\n", out0 ? "AN" : "AUS");
                }   else {
                    printf("\r\n");
                }
            }
            return out0;
        case 1:
            //alter zustand zwischenspeichern
            oldout = out1;
            //Input abfragen
            out1 = IN1_GetValue();

            //checken ob der Zustand des Inputs sich geaendert hat
            if (out1 != oldout){
                printf("%c[2K", 27);
                printf("Der Input 2 ist nun %s.", out1 ? "HIGH" : "LOW" );
                if (in1){
                    K2_PORT = out1;
                    LED2_PORT = out1;
                    printf(" : K2 => %s\r\n", out1 ? "AN" : "AUS");
                }   else {
                    printf("\r\n");
                }
            };
            return out1;
        case 2:
            //alter zustand zwischenspeichern
            oldout = out2;
            //Input abfragen
            out2 = IN2_GetValue();

            //checken ob der Zustand des Inputs sich geaendert hat
            if (out2 != oldout){
                printf("%c[2K", 27);
                printf("Der Input 2 ist nun %s.\r\n", out2 ? "HIGH" : "LOW" );
            };
            return out2;
        case 3:
            //alter zustand zwischenspeichern
            oldout = out3;
            //Input abfragen
            out3 = IN3_GetValue();


            //checken ob der Zustand des Inputs sich geaendert hat
            if (out3 != oldout){
                printf("%c[2K", 27);
                printf("Der Input 1 ist nun %s.\r\n", out3 ? "HIGH" : "LOW" );
            }
            return out3;
        default: break;
    }
    return NULL;
}



#endif
