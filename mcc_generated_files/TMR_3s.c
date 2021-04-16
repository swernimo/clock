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
    // Start the Timer by writing to TMRxON bit
    T1CONbits.TMR1ON = 1;
}

void TMR_3s_StopTimer(void)
{
    // Stop the Timer by writing to TMRxON bit
    T1CONbits.TMR1ON = 0;
}
//
//uint16_t TMR_3s_ReadTimer(void)
//{
//    uint16_t readVal;
//    uint8_t readValHigh;
//    uint8_t readValLow;
//    
//    T1CONbits.T1RD16 = 1;
//	
//    readValLow = TMR1L;
//    readValHigh = TMR1H;
//    
//    readVal = ((uint16_t)readValHigh << 8) | readValLow;
//
//    return readVal;
//}
//
//void TMR_3s_WriteTimer(uint16_t timerVal)
//{
//    if (T1CONbits.nT1SYNC == 1)
//    {
//        // Stop the Timer by writing to TMRxON bit
//        T1CONbits.TMR1ON = 0;
//
//        // Write to the Timer1 register
//        TMR1H = (uint8_t)(timerVal >> 8);
//        TMR1L = (uint8_t)timerVal;
//
//        // Start the Timer after writing to the register
//        T1CONbits.TMR1ON =1;
//    }
//    else
//    {
//        // Write to the Timer1 register
//        TMR1H = (uint8_t)(timerVal >> 8);
//        TMR1L = (uint8_t)timerVal;
//    }
//}
//
//void TMR_3s_Reload(void)
//{
//    TMR1_WriteTimer(timer1ReloadVal);
//}
//
//void TMR_3s_StartSinglePulseAcquisition(void)
//{
//    T1GCONbits.T1GGO = 1;
//}
//
//uint8_t TMR_3s_CheckGateValueStatus(void)
//{
//    return (T1GCONbits.T1GVAL);
//}

bool TMR_3s_HasOverflowOccured(void)
{
    // check if  overflow has occurred by checking the TMRIF bit
    return(PIR5bits.TMR1IF);
}