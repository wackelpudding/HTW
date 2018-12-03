#include "step.h"
#include "mcc_generated_files/pin_manager.h"
#include <xc.h>
#include "mcc_generated_files/device_config.h"


int step(int curStep, int setStep){
        
    if (((curStep + setStep) % 4) == 1 || ((curStep + setStep) % 4) == 3){
        switch(setStep){
            case 1:
                IN1_SetHigh();
                IN2_SetHigh();
                IN3_SetLow();
                IN4_SetLow();
                break;
            case 2:
                IN1_SetLow();
                IN2_SetHigh();
                IN3_SetHigh();
                IN4_SetLow();
                break;
            case 3:
                IN1_SetLow();
                IN2_SetLow();
                IN3_SetHigh();
                IN4_SetHigh();
                break;
            case 4:
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
    return curStep;
}

int stepping(int curStep, int toStep){
    int temp = curStep;
    if (toStep == 0){
        return curStep;
    }
    if (toStep < 0){
        toStep *= -1;
        for (int i = 1; i <= toStep; i++){
            temp--;
            if (temp == 0){
                temp = 4;
            }
            step(temp + 1, temp);
            __delay_ms(10);
        }
    } else {
        for (int i = 1; i <= toStep; i++){
            temp++;
            if (temp == 5){
                temp = 1;
            }
            step(temp - 1,temp);
            __delay_ms(10);
        }
    }
    return (curStep + toStep % 4) + 1;
}


void schrittmotor(int curStep, int poti){
    
    
    
    
}
