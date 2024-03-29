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
    CLK_A_SetHigh();
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

static void Test() {
    CLK_D1_SetHigh();
    One();
    __delay_ms(1);
    CLK_D1_SetLow();
    CLK_D2_SetHigh();
    Two();
    __delay_ms(1);
    CLK_D2_SetLow();
    CLK_D3_SetHigh();
    Three();
    __delay_ms(1);
    CLK_D3_SetLow();
    CLK_D4_SetHigh();
    CLK_DP_SetHigh();
    Four();
    __delay_ms(1);
    CLK_D4_SetLow();
    CLK_DP_SetLow();
}

static void DisplayHours(int hour) {
    switch (hour) {
        case 1:
            CLK_D1_SetLow();
            CLK_D2_SetHigh();
            One();
            break;
        case 2:
            CLK_D1_SetLow();
            CLK_D2_SetHigh();
            Two();
            break;
        case 3:
            CLK_D1_SetLow();
            CLK_D2_SetHigh();
            Three();            
            break;
        case 4:
            CLK_D1_SetLow();
            CLK_D2_SetHigh();
            Four();
            break;
        case 5:
            CLK_D1_SetLow();
            CLK_D2_SetHigh();
            Five();
            break;
        case 6:
            CLK_D1_SetLow();
            CLK_D2_SetHigh();
            Six();
            break;
        case 7:
            CLK_D1_SetLow();
            CLK_D2_SetHigh();
            Seven();
            break;
        case 8:
            CLK_D1_SetLow();
            CLK_D2_SetHigh();
            Eight();
            break;
        case 9:
            CLK_D1_SetLow();
            CLK_D2_SetHigh();
            Nine();
            break;
        case 10:
            CLK_D1_SetHigh();
            One();
            __delay_ms(1);
            CLK_D1_SetLow();
            CLK_D2_SetHigh();
            Zero();
            break;
        case 11:
            CLK_D1_SetHigh();
            One();
            __delay_ms(1);
            CLK_D1_SetLow();
            CLK_D2_SetHigh();
            One();
            break;
        case 12:
            CLK_D1_SetHigh();
            One();
            __delay_ms(1);
            CLK_D1_SetLow();
            CLK_D2_SetHigh();
            Two();
            break;
    }
    __delay_ms(1);
    CLK_D2_SetLow();
}

static void DisplayMinuteSameOnesPlace(void (onesPlace)(void), int minute) {    
    switch(minute % 10) {
        case 0:
            CLK_D3_SetHigh();
            onesPlace();
            __delay_ms(1);
            CLK_D3_SetLow();
            CLK_D4_SetHigh();
            Zero();
            __delay_ms(1);
            CLK_D4_SetLow();
            break;
        case 1:
            CLK_D3_SetHigh();
            onesPlace();
            __delay_ms(1);
            CLK_D3_SetLow();
            CLK_D4_SetHigh();
            One();
            __delay_ms(1);
            CLK_D4_SetLow();
            break;
        case 2:
            CLK_D3_SetHigh();
            onesPlace();
            __delay_ms(1);
            CLK_D3_SetLow();
            CLK_D4_SetHigh();
            Two();
            __delay_ms(1);
            CLK_D4_SetLow();
            break;
        case 3:
            CLK_D3_SetHigh();
            onesPlace();
            __delay_ms(1);
            CLK_D3_SetLow();
            CLK_D4_SetHigh();
            Three();
            __delay_ms(1);
            CLK_D4_SetLow();
            break;
        case 4:
            CLK_D3_SetHigh();
            onesPlace();
            __delay_ms(1);
            CLK_D3_SetLow();
            CLK_D4_SetHigh();
            Four();
            __delay_ms(1);
            CLK_D4_SetLow();
            break;
        case 5:
            CLK_D3_SetHigh();
            onesPlace();
            __delay_ms(1);
            CLK_D3_SetLow();
            CLK_D4_SetHigh();
            Five();
            __delay_ms(1);
            CLK_D4_SetLow();
            break;
        case 6:
            CLK_D3_SetHigh();
            onesPlace();
            __delay_ms(1);
            CLK_D3_SetLow();
            CLK_D4_SetHigh();
            Six();
            __delay_ms(1);
            CLK_D4_SetLow();
            break;
        case 7:
            CLK_D3_SetHigh();
            onesPlace();
            __delay_ms(1);
            CLK_D3_SetLow();
            CLK_D4_SetHigh();
            Seven();
            __delay_ms(1);
            CLK_D4_SetLow();
            break;
        case 8:
            CLK_D3_SetHigh();
            onesPlace();
            __delay_ms(1);
            CLK_D3_SetLow();
            CLK_D4_SetHigh();
            Eight();
            __delay_ms(1);
            CLK_D4_SetLow();
            break;
        case 9:
            CLK_D3_SetHigh();
            onesPlace();
            __delay_ms(1);
            CLK_D3_SetLow();
            CLK_D4_SetHigh();
            Nine();
            __delay_ms(1);
            CLK_D4_SetLow();
            break;
    }
}

static void DisplayMinutes(int minute) {
    if (minute < 10) {
        DisplayMinuteSameOnesPlace(Zero, minute);
    } else if (minute < 20) {
        DisplayMinuteSameOnesPlace(One, minute);
    } else if (minute < 30) {
        DisplayMinuteSameOnesPlace(Two, minute);        
    } else if (minute < 40) {
        DisplayMinuteSameOnesPlace(Three, minute);
    } else if (minute < 50) {
        DisplayMinuteSameOnesPlace(Four, minute);
    } else {
        DisplayMinuteSameOnesPlace(Five, minute);
    }
}

void DisplayTime(int hour, int minute, bool isPm) {
    DisplayHours(hour);
    DisplayMinutes(minute);
    
    if(isPm) {
        CLK_D4_SetHigh();
        CLK_DP_SetHigh();
        __delay_ms(1);
        CLK_D4_SetLow();
        CLK_DP_SetLow();
    } else {
       CLK_DP_SetLow(); 
    }
}

void FlashMidnight() {
    
}

