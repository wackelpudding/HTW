/* 
 * File:   hexcounter.h
 * Author: jimeneztuero
 *
 * Created on December 19, 2017, 6:20 PM
 */

#ifndef HEXCOUNTER_H
#define	HEXCOUNTER_H

#ifdef	__cplusplus
extern "C" {
#endif




#ifdef	__cplusplus
}
#endif

#endif	/* HEXCOUNTER_H */

#include "mcc_generated_files/pin_manager.h"


void reset();
void ausgabe(int);
void Null();
void Eins();
void Zwei();
void Drei();
void Vier();
void Fuenf();
void Sechs();
void Sieben();
void Acht();
void Neun();
void HexZehn();
void HexElf();
void HexZwoelf();
void HexDreizehn();
void HexVierzehn();
void HexFuenfzehn();
void Error();

int zaehler = 0;
bool einmal = true;

void hexcount(){
    
    int taster1 = TASTER1_GetValue();
    int taster2 = TASTER2_GetValue();
   
    
    if(taster1){          // Taster 1 erhoeht den Zaehler um 1.
        zaehler += 1;
        if (zaehler > 15){
            zaehler -= 1;
        }
    }
    
    if(taster2){          // Taster 2 reduziert den Zähler um 1.
        zaehler -= 1;
        if (zaehler < 0){
            zaehler += 1;
        } 
            
    }
    
    
    ausgabe(zaehler);
 
}

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
}

void Eins(){
    SEGB_SetHigh();
    SEGC_SetHigh();
}

void Zwei(){
    SEGA_SetHigh();
    SEGB_SetHigh();
    SEGG_SetHigh();
    SEGD_SetHigh();
    SEGE_SetHigh();
}

void Drei(){
    SEGA_SetHigh();
    SEGB_SetHigh();
    SEGC_SetHigh();
    SEGD_SetHigh();
    SEGG_SetHigh();
}

void Vier(){
    SEGB_SetHigh();
    SEGC_SetHigh();
    SEGG_SetHigh();
    SEGF_SetHigh();
}

void Fuenf(){
    SEGA_SetHigh();
    SEGC_SetHigh();
    SEGD_SetHigh();
    SEGG_SetHigh();
    SEGF_SetHigh();
}

void Sechs(){
    SEGG_SetHigh();
    SEGC_SetHigh();
    SEGD_SetHigh();
    SEGE_SetHigh();
    SEGF_SetHigh();
}

void Sieben(){
    SEGA_SetHigh();
    SEGB_SetHigh();
    SEGC_SetHigh();
}

void Acht(){
    SEGA_SetHigh();
    SEGB_SetHigh();
    SEGC_SetHigh();
    SEGD_SetHigh();
    SEGE_SetHigh();
    SEGF_SetHigh();
    SEGG_SetHigh();
}

void Neun(){
    SEGA_SetHigh();
    SEGB_SetHigh();
    SEGC_SetHigh();
    SEGD_SetHigh();
    SEGF_SetHigh();
    SEGG_SetHigh();
}

void HexZehn(){             // A
    SEGA_SetHigh();
    SEGB_SetHigh();
    SEGC_SetHigh();
    SEGE_SetHigh();
    SEGF_SetHigh();
    SEGG_SetHigh();
}

void HexElf(){             // B.
    SEGA_SetHigh();
    SEGB_SetHigh();
    SEGC_SetHigh();
    SEGD_SetHigh();
    SEGE_SetHigh();
    SEGF_SetHigh();
    SEGG_SetHigh();
    SEGDP_SetHigh();
}

void HexZwoelf(){             // C
    SEGA_SetHigh();
    SEGD_SetHigh();
    SEGE_SetHigh();
    SEGF_SetHigh();
}

void HexDreizehn(){             // D.
    SEGA_SetHigh();
    SEGB_SetHigh();
    SEGC_SetHigh();
    SEGD_SetHigh();
    SEGE_SetHigh();
    SEGF_SetHigh();
    SEGDP_SetHigh();
}

void HexVierzehn(){             // E.
    SEGA_SetHigh();
    SEGD_SetHigh();
    SEGE_SetHigh();
    SEGF_SetHigh();
    SEGG_SetHigh();
    SEGDP_SetHigh();
}

void HexFuenfzehn(){             // F.
    SEGA_SetHigh();
    SEGG_SetHigh();
    SEGE_SetHigh();
    SEGF_SetHigh();
}

void Error(){             // E   -- hier ohne Punkt
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