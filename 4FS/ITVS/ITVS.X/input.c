#ifndef INPUT
#define INPUT
#include "input.h"

bool GetInput(int in){
    bool oldout;
    switch (in) {
        case 0: 
            oldout = out0; 
            out0 = IN0_GetValue();
            
            if (out0 != oldout){
                printf("Der Input %i ist nun %d. \n", in, out0);
            }
            return out0;
        case 1: 
            oldout = out1; 
            out1 = IN1_GetValue();
            if (out1 != oldout){
                printf("Der Input %i ist nun %d. \n", in, out1);
            };            
            return out1;
        case 2:
            oldout = out2;
            out2 = IN2_GetValue();
            if (out2 != oldout){
                printf("Der Input %i ist nun %d. \n", in, out2);
            };
            return out2;
        case 3:
            oldout = out3;
            out3 = IN3_GetValue();
            if (out3 != oldout){
                printf("Der Input %i ist nun %d. \n", in, out3);
                
            }
            return out3;
        default: break;
    }
    return NULL;
}


#endif