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
    while (1)
    {
        /*
         order of operations:
         * Set Digit High
         * Set Required Letters High
         * delay 1 ms
         * Set All Letters Low
         * Set Digit Low
         */
        CLK_D1_SetHigh();
        CLK_C_SetHigh();
        CLK_B_SetHigh();
        __delay_ms(1);
        CLK_D1_SetLow();
        CLK_C_SetLow();
        CLK_B_SetLow();
        CLK_D2_SetHigh();
        CLK_A_SetHigh();
        CLK_B_SetHigh();
        CLK_G_SetHigh();
        CLK_E_SetHigh();
        CLK_D_SetHigh();
        __delay_ms(1);
        CLK_D2_SetLow();
        CLK_A_SetLow();
        CLK_B_SetLow();
        CLK_G_SetLow();
        CLK_E_SetLow();
        CLK_D_SetLow();
        CLK_D3_SetHigh();
        CLK_A_SetHigh();
        CLK_B_SetHigh();
        CLK_C_SetHigh();
        CLK_D_SetHigh();
        CLK_G_SetHigh();
        __delay_ms(1);
        CLK_D3_SetLow();
        CLK_A_SetLow();
        CLK_B_SetLow();
        CLK_C_SetLow();
        CLK_D_SetLow();
        CLK_G_SetLow();
        
        CLK_D4_SetHigh();
        CLK_F_SetHigh();
        CLK_G_SetHigh();
        CLK_B_SetHigh();
        CLK_C_SetHigh();
        CLK_DP_SetHigh();
        __delay_ms(1);
        CLK_D4_SetLow();
        CLK_F_SetLow();
        CLK_G_SetLow();
        CLK_B_SetLow();
        CLK_C_SetLow();
        CLK_DP_SetLow();
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