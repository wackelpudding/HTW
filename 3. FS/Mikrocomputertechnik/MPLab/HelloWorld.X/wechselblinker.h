/* 
 * File:   wechselblinker.h
 * Author: jimeneztuero
 *
 * Created on December 5, 2017, 3:27 PM
 */

#ifndef WECHSELBLINKER_H
#define	WECHSELBLINKER_H

#ifdef	__cplusplus
extern "C" {
#endif

    #include "mcc_generated_files/mcc.h"
    
    
    
    void wechselblinker(){
    int i = 0;
    
    
    
    while(!TASTER2_GetValue()){
        
        LED1_SetHigh();
        __delay_ms(25);
        LED1_SetLow();
        LED2_SetHigh();
        __delay_ms(25);
        LED2_SetLow();
        __delay_ms(25);
        
        if(i==100){
            LED1_SetHigh();
            LED2_SetHigh();
            __delay_ms(200);
            LED1_SetLow();
            LED2_SetLow();
            __delay_ms(200);
            i = 0;
            }
        i++;
            }
    BUZZ_SetHigh();
    __delay_ms(500);
    BUZZ_SetLow();
        }
 


#ifdef	__cplusplus
}
#endif

#endif	/* WECHSELBLINKER_H */

