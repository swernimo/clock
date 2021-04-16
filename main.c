#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/TMR_775ms.h"
#include "I2C.h"
#include "RTCC.h"
#include "Display.h"
#include "mcc_generated_files/TMR_3s.h"
#include "TMR_5m.h"

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    TMR_5m_Initialize();
    TMR_3s_Initialize();
    TMR_775ms_Initialize();
    I2C_Initialize();
    rtc6_Initialize();
    TMR_775ms_StartTimer();
    DisplayTime(12, 1, true);
    LED_PM_SetLow();
    while (1)
    {
        if(TMR_775ms_HasOverflowOccured()) {
            bool clockProgrammed = rtcc_clock_programmed();
            if(!!clockProgrammed) {
                FlashMidnight();
            }
            TMR_775ms_StopTimer();
            LED_Toggle();
            PIR0bits.TMR0IF = 0;
            TMR_775ms_StartTimer();
        }
        if(SW_On_GetValue() == LOW) {
            if(!TMR_3s_IsRunning()) {
                TMR_3s_StartTimer();                
            }
        }
        if(SW_On_GetValue() == HIGH) {
            //restart 3 second timer to exit programming mode
            LED_PM_SetLow();
            TMR_3s_StopTimer();
        }
        if(TMR_3s_HasOverflowOccured()){
            LED_PM_SetHigh();
            TMR_3s_StopTimer();
            rtcc_set_clock_programmed();
        }
    }
}