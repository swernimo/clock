#include "TMR_ProgMode.h"
#include <xc.h>

volatile uint16_t timer5ReloadVal;

static void TMR_ProgMode_WriteTimer(uint16_t timerVal)
{
    TMR5H = (uint8_t)(timerVal >> 8);
    TMR5L = (uint8_t)timerVal;
}

static void TMR_ProgMode_Reload(void)
{
    TMR_ProgMode_WriteTimer(timer5ReloadVal);
}

void TMR_ProgMode_Initialize(void)
{
    //Set the Timer to the options selected in the GUI

    //T5GE disabled; T5GTM disabled; T5GPOL low; T5GGO done; T5GSPM disabled; 
    T5GCON = 0x00;

    //GSS T5G_pin; 
    T5GATE = 0x00;

    //CS LFINTOSC; 
    T5CLK = 0x04;

    TMR5H = 0x68;

    TMR5L = 0xA2;

    // Load the TMR value to reload variable
    timer5ReloadVal=(uint16_t)((TMR5H << 8) | TMR5L);

    // CKPS 1:1; nT5SYNC synchronize; TMR5ON enabled; T5RD16 disabled; 
    T5CON = 0x01;
    T5CONbits.TMR5ON = 0;
    
    // Clearing IF flag.
    PIR5bits.TMR5IF = 0;
}

void TMR_ProgMode_StartTimer(void)
{
    T5CONbits.TMR5ON = 1;
    PIR5bits.TMR5IF = 0;
}

void TMR_ProgMode_StopTimer(void)
{
    T5CONbits.TMR5ON = 0;
    PIR5bits.TMR5IF = 0;
    TMR_ProgMode_Reload();
}

bool TMR_ProgMode_HasOverflowOccured(void)
{
    return(PIR5bits.TMR5IF);
}

bool TMR_ProgMode_IsRunning(void) {
    return (T5CONbits.TMR5ON = 1);
}

void TMR_ProgMode_Restart(void) {
    TMR_ProgMode_StopTimer();
    TMR_ProgMode_StartTimer();
}