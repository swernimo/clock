#include "TMR_5m.h"
#include <stdbool.h>
#include <xc.h>
#include <stdint.h>

volatile uint16_t timer0ReloadVal16bit;

void TMR_5m_Initialize(void)
{
    // Set TMR0 to the options selected in the User Interface

    // T0CS T0CKI_PIN; T0CKPS 1:32; T0ASYNC synchronised; 
    T0CON1 = 0x05;

    // TMR0H 255; 
    TMR0H = 0xFF;

    // TMR0L 255; 
    TMR0L = 0xFF;

    // Load TMR0 value to the 16-bit reload variable
    timer0ReloadVal16bit = (TMR0H << 8) | TMR0L;

    // Clearing IF flag
    PIR0bits.TMR0IF = 0;

    // T0OUTPS 1:15; T0EN enabled; T016BIT 16-bit; 
    T0CON0 = 0x9E;
}

void TMR_5m_StartTimer(void)
{
    // Start the Timer by writing to TMR0ON bit
    T0CON0bits.T0EN = 1;
}

void TMR_5m_StopTimer(void)
{
    // Stop the Timer by writing to TMR0ON bit
    T0CON0bits.T0EN = 0;
}

//uint16_t TMR_5m_ReadTimer(void)
//{
//    uint16_t readVal;
//    uint8_t readValLow;
//    uint8_t readValHigh;
//
//    readValLow  = TMR0L;
//    readValHigh = TMR0H;
//    readVal  = ((uint16_t)readValHigh << 8) + readValLow;
//
//    return readVal;
//}
//
//void TMR_5m_WriteTimer(uint16_t timerVal)
//{
//    // Write to the Timer0 register
//    TMR0H = timerVal >> 8;
//    TMR0L = (uint8_t) timerVal;
//}
//
//void TMR_5m_Reload(void)
//{
//    // Write to the Timer0 register
//    TMR0H = timer0ReloadVal16bit >> 8;
//    TMR0L = (uint8_t) timer0ReloadVal16bit;
//}

bool TMR_5m_HasOverflowOccured(void)
{
    // check if  overflow has occurred by checking the TMRIF bit
    return(PIR0bits.TMR0IF);
}