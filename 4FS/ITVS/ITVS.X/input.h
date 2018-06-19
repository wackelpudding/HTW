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

#include <stdbool.h>
#include <stdio.h>
#include "mcc_generated_files/pin_manager.h"
#include <xc.h>
#include "onewire.h"
#include "mcc_generated_files/mcc.h"

bool GetInput(int in, bool out0, bool out1, bool out2, bool out3); 

void send_string(const char *x);

float getTemp(void);

unsigned char SENSOR[9];
bool out0 = false;
bool out1 = false;
bool out2 = false;
bool out3 = false;



#ifdef	__cplusplus
}
#endif

#endif	/* INPUT_H */

