#include <xc.h>
#include "TMR_775ms.h"

void TMR_775ms_Initialize(void)
{
    // Set TMR0 to the options selected in the User Interface

    // T0CS FOSC/4; T0CKPS 1:256; T0ASYNC synchronised; 
    T0CON1 = 0x48;

    // TMR0H 141; 
    TMR0H = 0x8D;

    // TMR0L 0; 
    TMR0L = 0x00;

    // Clearing IF flag
    PIR0bits.TMR0IF = 0;

    // T0OUTPS 1:16; T0EN enabled; T016BIT 8-bit; 
    T0CON0 = 0x8F;
}

void TMR_775ms_StartTimer(void)
{
    // Start the Timer by writing to TMR0ON bit
    T0CON0bits.T0EN = 1;
}

void TMR_775ms_StopTimer(void)
{
    // Stop the Timer by writing to TMR0ON bit
    T0CON0bits.T0EN = 0;
}

uint8_t TMR_775ms_ReadTimer(void)
{
    uint8_t readVal;

    // read Timer0, low register only
    readVal = TMR0L;

    return readVal;
}

void TMR_775ms_WriteTimer(uint8_t timerVal)
{
    // Write to Timer0 registers, low register only
    TMR0L = timerVal;
 }

void TMR_775ms_Reload(uint8_t periodVal)
{
   // Write to Timer0 registers, high register only
   TMR0H = periodVal;
}

bool TMR_775ms_HasOverflowOccured(void)
{
    // check if  overflow has occurred by checking the TMRIF bit
    return(PIR0bits.TMR0IF);
}