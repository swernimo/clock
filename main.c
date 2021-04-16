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
    rtcc_set_custom_register(0x21, 0x00);
    rtc6_Initialize();
//    I2C_Write(RTCC_ADDR, RTCC_HOUR, 0x38);
//    uint8_t data = I2C_Read(RTCC_ADDR, RTCC_HOUR);
    TMR_775ms_StartTimer();
    DisplayTime(12, 1, true);
    LED_PM_SetLow();
//    bool alarm1Programmed = rtcc_alarm1_programmed();
//    bool alarm0Programmed = rtcc_alarm0_programmed();
    while (1)
    {
        if(TMR_775ms_HasOverflowOccured()) {
            bool clockProgrammed = rtcc_clock_programmed();
            if(!!clockProgrammed) {
                //flash midnight
            }
            TMR_775ms_StopTimer();
            LED_Toggle();
            Display_Col_Toggle();
            PIR0bits.TMR0IF = 0;
            TMR_775ms_StartTimer();
        }
        if(SW_On_GetValue() == LOW) {
//            LED_PM_SetHigh();
            if(T2CONbits.TMR2ON == 0) {
                TMR_3s_StartTimer();                
            }
        }
        if(SW_On_GetValue() == HIGH) {
            LED_PM_SetLow();
            TMR_3s_StopTimer();
        }
        if(TMR_3s_HasOverflowOccured()){
            LED_PM_SetHigh();
            PIR5bits.TMR1IF = 0;
            TMR_3s_StopTimer();
            //    rtcc_set_custom_register(0x21, 0x01);
        }
    }
}