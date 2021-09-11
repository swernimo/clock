/*
 * File:   Clock.c
 * Author: swern
 *
 * Created on September 11, 2021, 12:51 PM
 */


#include "Clock.h"
#include "./mcc_generated_files/mcc.h"

static void AllOff() {
    CLK_A_SetLow();
    CLK_B_SetLow();
    CLK_C_SetLow();
    CLK_D_SetLow();
    CLK_E_SetLow();
    CLK_F_SetLow();
    CLK_G_SetLow();
}

static void One() {
    AllOff();
    CLK_B_SetHigh();
    CLK_C_SetHigh();
}

static void Two() {
    AllOff();
    CLK_A_SetHigh();
    CLK_B_SetHigh();
    CLK_G_SetHigh();
    CLK_E_SetHigh();
    CLK_D_SetHigh();
}

static void Three() {
    AllOff();
    CLK_A_SetHigh();
    CLK_B_SetHigh();
    CLK_C_SetHigh();
    CLK_D_SetHigh();
    CLK_G_SetHigh();
}

static void Four() {
    AllOff();
    CLK_F_SetHigh();
    CLK_G_SetHigh();
    CLK_B_SetHigh();
    CLK_C_SetHigh();
}

static void Five() {
    AllOff();
    CLK_A_SetHigh();
    CLK_F_SetHigh();
    CLK_G_SetHigh();
    CLK_C_SetHigh();
    CLK_D_SetHigh();    
}

static void Six() {
    AllOff();
    CLK_F_SetHigh();
    CLK_G_SetHigh();
    CLK_C_SetHigh();
    CLK_D_SetHigh();
    CLK_E_SetHigh();
}

static void Seven() {
    AllOff();
    CLK_A_SetHigh();
    CLK_B_SetHigh();
    CLK_C_SetHigh();
}

static void Eight() {
    AllOff();
    CLK_A_SetHigh();
    CLK_B_SetHigh();
    CLK_C_SetHigh();
    CLK_D_SetHigh();
    CLK_E_SetHigh();
    CLK_F_SetHigh();
    CLK_G_SetHigh();
}

static void Nine() {
    AllOff();
    CLK_A_SetHigh();
    CLK_B_SetHigh();
    CLK_C_SetHigh();
    CLK_F_SetHigh();
    CLK_G_SetHigh();
}

static void Zero() {
    AllOff();
    CLK_A_SetHigh();
    CLK_B_SetHigh();
    CLK_C_SetHigh();
    CLK_D_SetHigh();
    CLK_E_SetHigh();
    CLK_F_SetHigh();    
}

void DisplayTime(int hour, int minute, bool isAm) {
     /*
         order of operations:
         * Set Digit High
         * Set Required Letters High
         * delay 1 ms
         * Set All Letters Low
         * Set Digit Low
         */
    switch (hour) {
        case 10:
        case 11:
        case 12:
            CLK_D1_SetHigh();
            One();
            __delay_ms(1);
            break;
    }   
    CLK_D1_SetLow();
    CLK_D2_SetHigh();
    switch (hour) {
        case 1:
        case 11:
            One();
            break;
        case 2:
        case 12:
            Two();
            break;
        case 3:
            Three();            
            break;
        case 4:
            Four();
            break;
        case 5:
            Five();
            break;
        case 6:
            Six();
            break;
        case 7:
            Seven();
            break;
        case 8:
            Eight();
            break;
        case 9:
            Nine();
            break;
        case 10:
            Zero();
            break;
    }
    __delay_ms(1);
    CLK_D2_SetLow();
        
//        CLK_D3_SetHigh();
//        Nine();
//        __delay_ms(1);
//        CLK_D3_SetLow();
//        
//        CLK_D4_SetHigh();
//        Nine();
        
        if(isAm) {
           CLK_DP_SetLow(); 
        } else {
            CLK_DP_SetHigh();
        }
        __delay_ms(1);
        CLK_DP_SetLow();        
        CLK_D4_SetLow();
}

void FlashMidnight() {
    
}

