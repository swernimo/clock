#include <xc.h>
#include "TMR_3s.h"

void TMR_3s_Initialize(void)
{
    // Set TMR2 to the options selected in the User Interface

    // T2CS LFINTOSC; 
    T2CLKCON = 0x04;

    // T2PSYNC Not Synchronized; T2MODE Software control; T2CKPOL Rising Edge; T2CKSYNC Not Synchronized; 
    T2HLT = 0x00;

    // T2RSEL T2CKIPPS pin; 
    T2RST = 0x00;

    // T2PR 181; 
    T2PR = 0xB5;

    // TMR2 0; 
    T2TMR = 0x00;

    // Clearing IF flag.
    PIR5bits.TMR2IF = 0;

    // T2CKPS 1:32; T2OUTPS 1:16; TMR2ON on; 
    T2CON = 0xDF;
}

void TMR_3s_ModeSet(TMR2_HLT_MODE mode)
{
   // Configure different types HLT mode
    T2HLTbits.MODE = mode;
}

void TMR_3s_ExtResetSourceSet(TMR2_HLT_EXT_RESET_SOURCE reset)
{
    //Configure different types of HLT external reset source
    T2RSTbits.RSEL = reset;
}

void TMR_3s_Start(void)
{
    // Start the Timer by writing to TMRxON bit
    T2CONbits.TMR2ON = 1;
}

void TMR_3s_StartTimer(void)
{
    TMR_3s_Start();
}

void TMR_3s_Stop(void)
{
    // Stop the Timer by writing to TMRxON bit
    T2CONbits.TMR2ON = 0;
}

void TMR_3s_StopTimer(void)
{
    TMR_3s_Stop();
}

uint8_t TMR_3s_Counter8BitGet(void)
{
    uint8_t readVal;

    readVal = TMR2;

    return readVal;
}

uint8_t TMR_3s_ReadTimer(void)
{
    return TMR_3s_Counter8BitGet();
}

void TMR_3s_Counter8BitSet(uint8_t timerVal)
{
    // Write to the Timer2 register
    TMR2 = timerVal;
}

void TMR_3s_WriteTimer(uint8_t timerVal)
{
    TMR_3s_Counter8BitSet(timerVal);
}

void TMR_3s_Period8BitSet(uint8_t periodVal)
{
   PR2 = periodVal;
}

void TMR_3s_LoadPeriodRegister(uint8_t periodVal)
{
   TMR_3s_Period8BitSet(periodVal);
}

bool TMR_3s_HasOverflowOccured(void)
{
    // check if  overflow has occurred by checking the TMRIF bit
    bool status = PIR5bits.TMR2IF;
    if(status)
    {
        // Clearing IF flag.
        PIR5bits.TMR2IF = 0;
    }
    return status;
}
/**
  End of File
*/