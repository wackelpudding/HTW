#include "mcc.h"

#ifndef OUTPUT_INCLUDED
#define OUTPUT_INCLUDED

void ausgabe(int Zahl){
    reset();    // Vor der Ausgabe sollen erstmal alle LEDs ausgemacht werden.

    switch (Zahl){              // Je nach Zahl werden nun die passenden LEDs angemacht.
        case 0: Null();break;
        case 1: Eins();break;
        case 2: Zwei();break;
        case 3: Drei();break;
        case 4: Vier();break;
        case 5: Fuenf();break;
        case 6: Sechs();break;
        case 7: Sieben();break;
        case 8: Acht();break;
        case 9: Neun();break;
        case 10: HexZehn();break;
        case 11: HexElf();break;
        case 12: HexZwoelf();break;
        case 13: HexDreizehn();break;
        case 14: HexVierzehn();break;
        case 15: HexFuenfzehn();break;
        default: Error ();break;
    }


}

void Null(){
    SEGA_SetHigh();
    SEGB_SetHigh();
    SEGC_SetHigh();
    SEGD_SetHigh();
    SEGE_SetHigh();
    SEGF_SetHigh();
} // Ausgabe der Null

void Eins(){
    SEGB_SetHigh();
    SEGC_SetHigh();
}  // Ausgabe der Eins

void Zwei(){    // Ausgabe der Zwei
    SEGA_SetHigh();
    SEGB_SetHigh();
    SEGG_SetHigh();
    SEGD_SetHigh();
    SEGE_SetHigh();
}

void Drei(){    // Ausgabe der Drei
    SEGA_SetHigh();
    SEGB_SetHigh();
    SEGC_SetHigh();
    SEGD_SetHigh();
    SEGG_SetHigh();
}

void Vier(){    // Ausgabe der Vier
    SEGB_SetHigh();
    SEGC_SetHigh();
    SEGG_SetHigh();
    SEGF_SetHigh();
}

void Fuenf(){   // Ausgabe der der F�nf
    SEGA_SetHigh();
    SEGC_SetHigh();
    SEGD_SetHigh();
    SEGG_SetHigh();
    SEGF_SetHigh();
}

void Sechs(){   // Ausgabe der Sechs
    SEGG_SetHigh();
    SEGC_SetHigh();
    SEGD_SetHigh();
    SEGE_SetHigh();
    SEGF_SetHigh();
}

void Sieben(){  // Ausgabe der Sieben
    SEGA_SetHigh();
    SEGB_SetHigh();
    SEGC_SetHigh();
}

void Acht(){    // Ausgabe der Acht
    SEGA_SetHigh();
    SEGB_SetHigh();
    SEGC_SetHigh();
    SEGD_SetHigh();
    SEGE_SetHigh();
    SEGF_SetHigh();
    SEGG_SetHigh();
}

void Neun(){    // Ausgabe der Neun
    SEGA_SetHigh();
    SEGB_SetHigh();
    SEGC_SetHigh();
    SEGD_SetHigh();
    SEGF_SetHigh();
    SEGG_SetHigh();
}

void HexZehn(){     // Ausgabe der Hexadezimalen Zehn -> A
    SEGA_SetHigh();
    SEGB_SetHigh();
    SEGC_SetHigh();
    SEGE_SetHigh();
    SEGF_SetHigh();
    SEGG_SetHigh();
}

void HexElf(){     // Ausgabe der Hexadezimalen Elf -> B.
    SEGA_SetHigh();
    SEGB_SetHigh();
    SEGC_SetHigh();
    SEGD_SetHigh();
    SEGE_SetHigh();
    SEGF_SetHigh();
    SEGG_SetHigh();
    SEGDP_SetHigh();
}

void HexZwoelf(){  // Ausgabe der Hexadezimalen Zw�lf -> C
    SEGA_SetHigh();
    SEGD_SetHigh();
    SEGE_SetHigh();
    SEGF_SetHigh();
}

void HexDreizehn(){     // Ausgabe der Hexadezimalen Dreizehn -> D.
    SEGA_SetHigh();
    SEGB_SetHigh();
    SEGC_SetHigh();
    SEGD_SetHigh();
    SEGE_SetHigh();
    SEGF_SetHigh();
    SEGDP_SetHigh();
}

void HexVierzehn(){ // Ausgabe der Hexadezimalen Vierzehn -> E.
    SEGA_SetHigh();
    SEGD_SetHigh();
    SEGE_SetHigh();
    SEGF_SetHigh();
    SEGG_SetHigh();
    SEGDP_SetHigh();
}

void HexFuenfzehn(){    // Ausgabe der Hexadezimalen FuenfZehn F.
    SEGA_SetHigh();
    SEGG_SetHigh();
    SEGE_SetHigh();
    SEGF_SetHigh();
}

void Error(){             // Ausgabe eines Fehlerzustandes als E -- hier ohne Punkt
    SEGA_SetHigh();
    SEGD_SetHigh();
    SEGE_SetHigh();
    SEGF_SetHigh();
    SEGG_SetHigh();
}

void reset(){           //macht alle Lampen aus
    SEGA_SetLow();
    SEGB_SetLow();
    SEGC_SetLow();
    SEGD_SetLow();
    SEGE_SetLow();
    SEGF_SetLow();
    SEGG_SetLow();
    SEGDP_SetLow();
}

void hochzaehlen(){ // Erh�ht den Z�hler und prellt den taster und schaltet die LED2 vom Taster2 an.
    if (TASTER2_GetValue() && einmal){
        zaehler -= 1;
        einmal = false;
        LED2_SetHigh();
        if (zaehler < 0){
            zaehler += 1;
        }
    }
}

void runterzaehlen(){   // Verringert den Z�hler und prellt den Taster und setz zur anzeige die Taster1 LED1.
    if (TASTER1_GetValue() && einmal){
        zaehler += 1;
        einmal = false;
        LED1_SetHigh();
        if (zaehler > 15){
            zaehler -= 1;
        }
    }
}

void entprellen(){  // entprellt beide Taster und schaltet beide LEDs aus.
    if (!einmal){
        einmal = true ;
        LED1_SetLow();
        LED2_SetLow();
    }
}

#endif
