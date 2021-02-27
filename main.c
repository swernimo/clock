#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/tmr0.h"
#include "I2C.h"
//#include "RTC.h"
//

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
//    I2C_Initialize();
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
    
//    MCP7940_Write(MCP7940_ADDR, ADDR_SEC, 0x0 | OSC_ON); // sec to zero BUT osc on
//    MCP7940_Write(MCP7940_ADDR, ADDR_MIN, 0x59); //  min to 59
//    MCP7940_Write(MCP7940_ADDR, ADDR_HOUR, 0x12); //  hour to 12
    while (1)
    {
        // Add your application code
        if(TMR0_HasOverflowOccured()){
//            sec = MCP7940_Read(MCP7940_ADDR, ADDR_SEC);        
//            min = MCP7940_Read(MCP7940_ADDR, ADDR_MIN);
            TMR0_StopTimer();
            PIR0bits.TMR0IF = 0;
            LED_Toggle();
            TMR0_StartTimer();
        }
    }
}