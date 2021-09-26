#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/TMR_775ms.h"
#include "I2C.h"
#include "RTCC.h"
//#include "Display.h"
#include "mcc_generated_files/TMR_3s.h"
#include "TMR_5m.h"
#include "Utilities.h"
#include "TMR_ProgMode.h"
#include "Clock.h"

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
//    rtc6_SetTime(9, 9, true);
    DateTime_t currentTime = rtc6_GetTime();
    while (1)
    {
        if(TMR_775ms_HasOverflowOccured()) {            
            currentTime = rtc6_GetTime();
            TMR_775ms_StopTimer();
            TMR_775ms_StartTimer();
        }
        
        DisplayTime(currentTime.hr, currentTime.min, currentTime.isPm);
       
        if (SW_On_Pressed) {
            LED_On_Toggle();
        }
        
        if (SW_Led_Pressed) {
            LED_Led_Toggle();
        }
        
        if (SW_Prog_Pressed) {
            LED_Prog_Toggle();
        }
        
        if (SW_Hr_Pressed) {
            LED_Hr_Toggle();
        }
        
        if (SW_Min_Pressed) {
            LED_Min_Toggle();
        }
    }
}