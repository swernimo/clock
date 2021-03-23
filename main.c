#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/tmr0.h"
#include "I2C.h"
#include "RTCC.h"
#include "Utilities.h"

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    I2C_Initialize();
    rtc6_Initialize();
//    I2C_Write(RTCC_ADDR, RTCC_HOUR, 0x38);
//    uint8_t data = I2C_Read(RTCC_ADDR, RTCC_HOUR);
    TMR0_StartTimer();
    while (1)
    {
        if(TMR0_HasOverflowOccured()) {
            TMR0_StopTimer();
            LED_Toggle();
            Display_Col_Toggle();
            PIR0bits.TMR0IF = 0;
            TMR0_StartTimer();
        }
    }
}