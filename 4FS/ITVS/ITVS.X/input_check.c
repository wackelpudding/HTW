#include "mcc_generated_files/mcc.h"


void input_check(int input){
        
    switch(input){
        case 0:
            In0 = IN0_GetValue();
            if (Start_In0 != In0){
                Start_In0 = In0;
                printf("Der Port %s hat sich auf %d geaendert", input, In0);
            }
            break;
        case 1:
            In1 = IN1_GetValue();
            if (Start_In1 != In1){
                Start_In1 = In1;
                printf("Der Port %s hat sich auf %d geaendert", input, In1);
            }
            break;
        case 2:
            In2 = IN2_GetValue();
            if (Start_In2 != In2){
                Start_In2 = In2;
                printf("Der Port %s hat sich auf %d geaendert", input, In2);
            }
            break;
        case 3:
            In3 = IN3_GetValue();
            if (Start_In3 != In3){
                Start_In3 = In3;
                printf("Der Port %s hat sich auf %d geaendert", input, In3);
            }
            break;
        default:
            break;
    }
    
}
