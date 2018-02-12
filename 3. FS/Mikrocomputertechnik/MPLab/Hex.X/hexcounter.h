/*
 * File:   hexcounter.h
 * Author: jimeneztuero
 *
 * Created on December 19, 2017, 6:20 PM
 */


#ifdef	__cplusplus
extern "C" {
#endif





#ifdef	__cplusplus
}
#endif

#ifndef HEXCOUNT_H
#define HEXCOUNT_H

#include "mcc_generated_files/pin_manager.h"  //bibliotheken einbinden
#include <stdbool.h>

int zaehler = 0;        //zähler initialisieren
bool einmal = true;     //Entprellen initialisieren
//deklarieren von allen verwendeten Funktionen.
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
void hochzaehlen();
void runterzaehlen();
void entprellen();
#endif /* HEXCOUNT_H */
