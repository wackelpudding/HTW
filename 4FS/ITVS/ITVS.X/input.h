/* 
 * File:   input.h
 * Author: Ricardo
 *
 * Created on June 17, 2018, 12:23 AM
 */

#ifndef INPUT_H
#define	INPUT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/mcc.h"


/*** prototypes ***************************************************************/    
//Fragt einen der 4 Inputs an und
// liefert den aktuellen Zustand des Inputs zurrück
bool GetInput(int in, bool out0, bool out1, bool out2, bool out3); 

//sendet einen string via EUSART_Write
void send_string(const char *x);

//Fragt den Temperatursensor ab und liefert die Tempteratur 
//als integer ein ein Zehntel Grad genau. (222 entsprechen 22,5 grad celsius))
int getTemp(void);


extern unsigned char SENSOR[9];

//deklaration der Input Variablen
bool out0 = false;
bool out1 = false;
bool out2 = false;
bool out3 = false;



#ifdef	__cplusplus
}
#endif

#endif	/* INPUT_H */

