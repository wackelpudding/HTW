/* 
 * File:   blinkbuzz.h
 * Author: jimeneztuero
 *
 * Created on December 5, 2017, 3:02 PM
 */

#ifndef BLINKBUZZ_H
#define	BLINKBUZZ_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mcc_generated_files/mcc.h"

void blinkbuzz(){
    int raus1 = 0;
    int raus2 = 0;
    bool einmal = true;
    bool los = true;
    while (los){
        int Taster1 = TASTER1_GetValue();
        int Taster2 = TASTER2_GetValue();


        if(Taster1 && einmal){
            einmal = false;
            LED1_SetHigh();
            raus1= raus1+1;
            raus2 = 0;
            __delay_ms(200);
            if (raus1>=3){
                los = false;
                LED1_SetLow();
                LED2_SetLow();
            }
        
        }
        if (!TASTER1_GetValue() && !einmal){
            einmal = !einmal;
            __delay_ms(100);
        }
        if(Taster2 && einmal){
            einmal = false;
            LED2_SetHigh();
            raus2 = raus2 +1;
            raus1 = 0;
            __delay_ms(200);
            if (raus2 >=3){
                los = false;
                LED1_SetLow();
                LED2_SetLow();
               
            } 
        }
        if (!TASTER2_GetValue() && !einmal){
            einmal = !einmal;
            __delay_ms(100);
        }
        
        LED1_SetLow();
        LED2_SetLow();
    }
    BUZZ_SetHigh();
    __delay_ms(500);
    BUZZ_SetLow();
}


#ifdef	__cplusplus
}
#endif

#endif	/* BLINKBUZZ_H */

