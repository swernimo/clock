#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/tmr0.h"
#include "I2C_Master.h"
#include "RTC.h"
#include <xc.h>
#include <stdint.h>
#include <string.h>

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    I2C_Initialize();
    rtc6_Initialize();
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
        // Add your application code
        if(TMR0_HasOverflowOccured()){
            TMR0_StopTimer();
            PIR0bits.TMR0IF = 0;
            LED_Toggle();
            TMR0_StartTimer();
        }
    }
}