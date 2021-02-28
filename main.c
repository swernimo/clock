#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/tmr0.h"
/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    TMR0_StartTimer();
    while (1)
    {
        if(TMR0_HasOverflowOccured()) {
            TMR0_StopTimer();
            LED_Toggle();
            PIR0bits.TMR0IF = 0;
            TMR0_StartTimer();
        }
    }
}