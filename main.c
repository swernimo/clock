#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/TMR_775ms.h"
#include "I2C.h"
#include "RTCC.h"
#include "Display.h"
#include "mcc_generated_files/TMR_3s.h"
#include "TMR_5m.h"
#include "Utilities.h"
#include "TMR_ProgMode.h"

static void InitializeDevice() {
    SYSTEM_Initialize();
    TMR_5m_Initialize();
    TMR_3s_Initialize();
    TMR_775ms_Initialize();
    TMR_ProgMode_Initialize();
    I2C_Initialize();
    rtc6_Initialize();    
}

void main(void)
{
    InitializeDevice();
    TMR_775ms_StartTimer();
    DisplayTime(12, 1, true);
    LED_PM_SetLow();
    bool currentlyProgramming = false;
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
        
        if(SW_On_Pressed) {
            if(!TMR_3s_IsRunning()) {
                TMR_3s_StartTimer();                
            }
        }
        
        if(currentlyProgramming) {
            //if any of the programming buttons are pressed (hour, min, prog) reset the timer
            //TMR_ProgMode_Restart();
        }
        
        if(!SW_On_Pressed) {
            TMR_3s_StopTimer();
            if (currentlyProgramming) {
                if(TMR_ProgMode_HasOverflowOccured()) {
                    TMR_ProgMode_StopTimer();
                    LED_PM_SetLow();
                    rtcc_set_clock_programmed();
                    currentlyProgramming = false;
                } else {                    
                    TMR_ProgMode_StartTimer();
                }                
            }
        }
        if(TMR_3s_HasOverflowOccured()){
            if (!currentlyProgramming) {
                LED_PM_SetHigh();
                currentlyProgramming = true;
            }
        }
    }
}