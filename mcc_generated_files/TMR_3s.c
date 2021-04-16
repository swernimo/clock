#include <xc.h>
#include "TMR_3s.h"

volatile uint16_t timer1ReloadVal;

void TMR_3s_Initialize(void)
{
    //Set the Timer to the options selected in the GUI

    //T1GE disabled; T1GTM disabled; T1GPOL low; T1GGO done; T1GSPM disabled; 
    T1GCON = 0x00;

    //GSS T1G_pin; 
    T1GATE = 0x00;

    //CS LFINTOSC; 
    T1CLK = 0x04;

    //TMR1H 210; 
    TMR1H = 0xD2;

    //TMR1L 151; 
    TMR1L = 0x97;

    // Clearing IF flag.
    PIR5bits.TMR1IF = 0;
	
    // Load the TMR value to reload variable
    timer1ReloadVal=(uint16_t)((TMR1H << 8) | TMR1L);

    // CKPS 1:8; nT1SYNC synchronize; TMR1ON enabled; T1RD16 disabled; 
    T1CON = 0x31;
}

void TMR_3s_StartTimer(void)
{
    T1CONbits.TMR1ON = 1;
}

void TMR_3s_StopTimer(void)
{
    T1CONbits.TMR1ON = 0;
    PIR5bits.TMR1IF = 0;
}

bool TMR_3s_IsRunning(void) {
    return (T1CONbits.TMR1ON == 1);
}

bool TMR_3s_HasOverflowOccured(void)
{
    return(PIR5bits.TMR1IF);
}