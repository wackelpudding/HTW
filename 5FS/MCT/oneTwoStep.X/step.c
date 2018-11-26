#include "step.h"
#include "mcc_generated_files/pin_manager.h"
#include <xc.h>


int step(int setStep){
    
    
    


        switch(setStep){
            case 0:
                IN1_SetLow();
                IN2_SetHigh();
                IN3_SetLow();
                IN4_SetHigh();
                break;
            case 1:
                IN1_SetLow();
                IN2_SetHigh();
                IN3_SetHigh();
                IN4_SetLow();
                break;
            case 2:
                IN1_SetHigh();
                IN2_SetLow();
                IN3_SetHigh();
                IN4_SetLow();
                break;
            case 3:
                IN1_SetHigh();
                IN2_SetLow();
                IN3_SetLow();
                IN4_SetHigh();
                break;
            default:
                break;
        }

    return setStep;
}
