#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/tmr0.h"
#include "I2C.h"
#include "RTCC.h"
#include "Display.h"

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
    I2C_Initialize();
    rtc6_Initialize();
//    I2C_Write(RTCC_ADDR, RTCC_HOUR, 0x38);
//    uint8_t data = I2C_Read(RTCC_ADDR, RTCC_HOUR);
    TMR0_StartTimer();
    DisplayTime(12, 1, true);
    rtcc_set_custom_register(0x21, 0x07);
    LED_PM_SetLow();
    bool clockProgrammed = rtcc_clock_programmed();
    bool alarm1Programmed = rtcc_alarm1_programmed();
    bool alarm0Programmed = rtcc_alarm0_programmed();
    while (1)
    {
        if(!!clockProgrammed) {
            //flash midnight
        }
        if(TMR0_HasOverflowOccured()) {
            TMR0_StopTimer();
            LED_Toggle();
            Display_Col_Toggle();
            PIR0bits.TMR0IF = 0;
            TMR0_StartTimer();
        }
        if(SW_On_GetValue() == LOW) {
//            LED_PM_SetHigh();
            if(T2CONbits.TMR2ON == 0) {
                TMR2_StartTimer();                
            }
        }
        if(SW_On_GetValue() == HIGH) {
            LED_PM_SetLow();
            TMR2_StopTimer();
        }
        if(TMR2_HasOverflowOccured()){
            LED_PM_SetHigh();
            PIR5bits.TMR1IF = 0;
            TMR2_StopTimer();
            //    rtcc_set_custom_register(0x21, 0x01);
        }
    }
}