#ifndef INPUT_C
#define INPUT_C
#include "input.h"
#include "onewire.h"


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

#endif
