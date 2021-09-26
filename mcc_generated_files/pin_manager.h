/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC18F67K40
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above
        MPLAB 	          :  MPLAB X 5.45	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set SW_Led aliases
#define SW_Led_TRIS                 TRISAbits.TRISA3
#define SW_Led_LAT                  LATAbits.LATA3
#define SW_Led_PORT                 PORTAbits.RA3
#define SW_Led_WPU                  WPUAbits.WPUA3
#define SW_Led_OD                   ODCONAbits.ODCA3
#define SW_Led_ANS                  ANSELAbits.ANSELA3
#define SW_Led_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define SW_Led_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define SW_Led_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define SW_Led_GetValue()           PORTAbits.RA3
#define SW_Led_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define SW_Led_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define SW_Led_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define SW_Led_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define SW_Led_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define SW_Led_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define SW_Led_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define SW_Led_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set SW_Prog aliases
#define SW_Prog_TRIS                 TRISAbits.TRISA4
#define SW_Prog_LAT                  LATAbits.LATA4
#define SW_Prog_PORT                 PORTAbits.RA4
#define SW_Prog_WPU                  WPUAbits.WPUA4
#define SW_Prog_OD                   ODCONAbits.ODCA4
#define SW_Prog_ANS                  ANSELAbits.ANSELA4
#define SW_Prog_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define SW_Prog_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define SW_Prog_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define SW_Prog_GetValue()           PORTAbits.RA4
#define SW_Prog_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define SW_Prog_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define SW_Prog_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define SW_Prog_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define SW_Prog_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define SW_Prog_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define SW_Prog_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define SW_Prog_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set SW_On aliases
#define SW_On_TRIS                 TRISAbits.TRISA5
#define SW_On_LAT                  LATAbits.LATA5
#define SW_On_PORT                 PORTAbits.RA5
#define SW_On_WPU                  WPUAbits.WPUA5
#define SW_On_OD                   ODCONAbits.ODCA5
#define SW_On_ANS                  ANSELAbits.ANSELA5
#define SW_On_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define SW_On_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define SW_On_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define SW_On_GetValue()           PORTAbits.RA5
#define SW_On_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define SW_On_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define SW_On_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define SW_On_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define SW_On_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define SW_On_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define SW_On_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define SW_On_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set LED_Night aliases
#define LED_Night_TRIS                 TRISBbits.TRISB1
#define LED_Night_LAT                  LATBbits.LATB1
#define LED_Night_PORT                 PORTBbits.RB1
#define LED_Night_WPU                  WPUBbits.WPUB1
#define LED_Night_OD                   ODCONBbits.ODCB1
#define LED_Night_ANS                  ANSELBbits.ANSELB1
#define LED_Night_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define LED_Night_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define LED_Night_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define LED_Night_GetValue()           PORTBbits.RB1
#define LED_Night_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define LED_Night_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define LED_Night_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define LED_Night_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define LED_Night_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define LED_Night_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define LED_Night_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define LED_Night_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set LED_Day aliases
#define LED_Day_TRIS                 TRISBbits.TRISB2
#define LED_Day_LAT                  LATBbits.LATB2
#define LED_Day_PORT                 PORTBbits.RB2
#define LED_Day_WPU                  WPUBbits.WPUB2
#define LED_Day_OD                   ODCONBbits.ODCB2
#define LED_Day_ANS                  ANSELBbits.ANSELB2
#define LED_Day_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define LED_Day_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define LED_Day_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define LED_Day_GetValue()           PORTBbits.RB2
#define LED_Day_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define LED_Day_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define LED_Day_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define LED_Day_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define LED_Day_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define LED_Day_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define LED_Day_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define LED_Day_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set RTCC_MFP aliases
#define RTCC_MFP_TRIS                 TRISCbits.TRISC2
#define RTCC_MFP_LAT                  LATCbits.LATC2
#define RTCC_MFP_PORT                 PORTCbits.RC2
#define RTCC_MFP_WPU                  WPUCbits.WPUC2
#define RTCC_MFP_OD                   ODCONCbits.ODCC2
#define RTCC_MFP_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define RTCC_MFP_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define RTCC_MFP_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RTCC_MFP_GetValue()           PORTCbits.RC2
#define RTCC_MFP_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define RTCC_MFP_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define RTCC_MFP_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define RTCC_MFP_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define RTCC_MFP_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define RTCC_MFP_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)

// get/set SW_Hr aliases
#define SW_Hr_TRIS                 TRISCbits.TRISC5
#define SW_Hr_LAT                  LATCbits.LATC5
#define SW_Hr_PORT                 PORTCbits.RC5
#define SW_Hr_WPU                  WPUCbits.WPUC5
#define SW_Hr_OD                   ODCONCbits.ODCC5
#define SW_Hr_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define SW_Hr_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define SW_Hr_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define SW_Hr_GetValue()           PORTCbits.RC5
#define SW_Hr_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define SW_Hr_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define SW_Hr_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define SW_Hr_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define SW_Hr_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define SW_Hr_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)

// get/set SW_Min aliases
#define SW_Min_TRIS                 TRISCbits.TRISC6
#define SW_Min_LAT                  LATCbits.LATC6
#define SW_Min_PORT                 PORTCbits.RC6
#define SW_Min_WPU                  WPUCbits.WPUC6
#define SW_Min_OD                   ODCONCbits.ODCC6
#define SW_Min_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define SW_Min_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define SW_Min_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define SW_Min_GetValue()           PORTCbits.RC6
#define SW_Min_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define SW_Min_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define SW_Min_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define SW_Min_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define SW_Min_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define SW_Min_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)

// get/set CLK_D4 aliases
#define CLK_D4_TRIS                 TRISDbits.TRISD2
#define CLK_D4_LAT                  LATDbits.LATD2
#define CLK_D4_PORT                 PORTDbits.RD2
#define CLK_D4_WPU                  WPUDbits.WPUD2
#define CLK_D4_OD                   ODCONDbits.ODCD2
#define CLK_D4_ANS                  ANSELDbits.ANSELD2
#define CLK_D4_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define CLK_D4_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define CLK_D4_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define CLK_D4_GetValue()           PORTDbits.RD2
#define CLK_D4_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define CLK_D4_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define CLK_D4_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define CLK_D4_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define CLK_D4_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define CLK_D4_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define CLK_D4_SetAnalogMode()      do { ANSELDbits.ANSELD2 = 1; } while(0)
#define CLK_D4_SetDigitalMode()     do { ANSELDbits.ANSELD2 = 0; } while(0)

// get/set CLK_D3 aliases
#define CLK_D3_TRIS                 TRISDbits.TRISD3
#define CLK_D3_LAT                  LATDbits.LATD3
#define CLK_D3_PORT                 PORTDbits.RD3
#define CLK_D3_WPU                  WPUDbits.WPUD3
#define CLK_D3_OD                   ODCONDbits.ODCD3
#define CLK_D3_ANS                  ANSELDbits.ANSELD3
#define CLK_D3_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define CLK_D3_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define CLK_D3_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define CLK_D3_GetValue()           PORTDbits.RD3
#define CLK_D3_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define CLK_D3_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define CLK_D3_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define CLK_D3_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define CLK_D3_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define CLK_D3_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define CLK_D3_SetAnalogMode()      do { ANSELDbits.ANSELD3 = 1; } while(0)
#define CLK_D3_SetDigitalMode()     do { ANSELDbits.ANSELD3 = 0; } while(0)

// get/set CLK_D2 aliases
#define CLK_D2_TRIS                 TRISDbits.TRISD4
#define CLK_D2_LAT                  LATDbits.LATD4
#define CLK_D2_PORT                 PORTDbits.RD4
#define CLK_D2_WPU                  WPUDbits.WPUD4
#define CLK_D2_OD                   ODCONDbits.ODCD4
#define CLK_D2_ANS                  ANSELDbits.ANSELD4
#define CLK_D2_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define CLK_D2_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define CLK_D2_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define CLK_D2_GetValue()           PORTDbits.RD4
#define CLK_D2_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define CLK_D2_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define CLK_D2_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define CLK_D2_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define CLK_D2_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define CLK_D2_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define CLK_D2_SetAnalogMode()      do { ANSELDbits.ANSELD4 = 1; } while(0)
#define CLK_D2_SetDigitalMode()     do { ANSELDbits.ANSELD4 = 0; } while(0)

// get/set CLK_F aliases
#define CLK_F_TRIS                 TRISDbits.TRISD5
#define CLK_F_LAT                  LATDbits.LATD5
#define CLK_F_PORT                 PORTDbits.RD5
#define CLK_F_WPU                  WPUDbits.WPUD5
#define CLK_F_OD                   ODCONDbits.ODCD5
#define CLK_F_ANS                  ANSELDbits.ANSELD5
#define CLK_F_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define CLK_F_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define CLK_F_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define CLK_F_GetValue()           PORTDbits.RD5
#define CLK_F_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define CLK_F_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define CLK_F_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define CLK_F_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define CLK_F_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define CLK_F_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define CLK_F_SetAnalogMode()      do { ANSELDbits.ANSELD5 = 1; } while(0)
#define CLK_F_SetDigitalMode()     do { ANSELDbits.ANSELD5 = 0; } while(0)

// get/set CLK_C aliases
#define CLK_C_TRIS                 TRISDbits.TRISD6
#define CLK_C_LAT                  LATDbits.LATD6
#define CLK_C_PORT                 PORTDbits.RD6
#define CLK_C_WPU                  WPUDbits.WPUD6
#define CLK_C_OD                   ODCONDbits.ODCD6
#define CLK_C_ANS                  ANSELDbits.ANSELD6
#define CLK_C_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define CLK_C_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define CLK_C_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define CLK_C_GetValue()           PORTDbits.RD6
#define CLK_C_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define CLK_C_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define CLK_C_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define CLK_C_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define CLK_C_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define CLK_C_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define CLK_C_SetAnalogMode()      do { ANSELDbits.ANSELD6 = 1; } while(0)
#define CLK_C_SetDigitalMode()     do { ANSELDbits.ANSELD6 = 0; } while(0)

// get/set CLK_DP aliases
#define CLK_DP_TRIS                 TRISDbits.TRISD7
#define CLK_DP_LAT                  LATDbits.LATD7
#define CLK_DP_PORT                 PORTDbits.RD7
#define CLK_DP_WPU                  WPUDbits.WPUD7
#define CLK_DP_OD                   ODCONDbits.ODCD7
#define CLK_DP_ANS                  ANSELDbits.ANSELD7
#define CLK_DP_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define CLK_DP_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define CLK_DP_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define CLK_DP_GetValue()           PORTDbits.RD7
#define CLK_DP_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define CLK_DP_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define CLK_DP_SetPullup()          do { WPUDbits.WPUD7 = 1; } while(0)
#define CLK_DP_ResetPullup()        do { WPUDbits.WPUD7 = 0; } while(0)
#define CLK_DP_SetPushPull()        do { ODCONDbits.ODCD7 = 0; } while(0)
#define CLK_DP_SetOpenDrain()       do { ODCONDbits.ODCD7 = 1; } while(0)
#define CLK_DP_SetAnalogMode()      do { ANSELDbits.ANSELD7 = 1; } while(0)
#define CLK_DP_SetDigitalMode()     do { ANSELDbits.ANSELD7 = 0; } while(0)

// get/set CLK_A aliases
#define CLK_A_TRIS                 TRISEbits.TRISE0
#define CLK_A_LAT                  LATEbits.LATE0
#define CLK_A_PORT                 PORTEbits.RE0
#define CLK_A_WPU                  WPUEbits.WPUE0
#define CLK_A_OD                   ODCONEbits.ODCE0
#define CLK_A_ANS                  ANSELEbits.ANSELE0
#define CLK_A_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define CLK_A_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define CLK_A_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define CLK_A_GetValue()           PORTEbits.RE0
#define CLK_A_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define CLK_A_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define CLK_A_SetPullup()          do { WPUEbits.WPUE0 = 1; } while(0)
#define CLK_A_ResetPullup()        do { WPUEbits.WPUE0 = 0; } while(0)
#define CLK_A_SetPushPull()        do { ODCONEbits.ODCE0 = 0; } while(0)
#define CLK_A_SetOpenDrain()       do { ODCONEbits.ODCE0 = 1; } while(0)
#define CLK_A_SetAnalogMode()      do { ANSELEbits.ANSELE0 = 1; } while(0)
#define CLK_A_SetDigitalMode()     do { ANSELEbits.ANSELE0 = 0; } while(0)

// get/set CLK_E aliases
#define CLK_E_TRIS                 TRISEbits.TRISE1
#define CLK_E_LAT                  LATEbits.LATE1
#define CLK_E_PORT                 PORTEbits.RE1
#define CLK_E_WPU                  WPUEbits.WPUE1
#define CLK_E_OD                   ODCONEbits.ODCE1
#define CLK_E_ANS                  ANSELEbits.ANSELE1
#define CLK_E_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define CLK_E_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define CLK_E_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define CLK_E_GetValue()           PORTEbits.RE1
#define CLK_E_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define CLK_E_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define CLK_E_SetPullup()          do { WPUEbits.WPUE1 = 1; } while(0)
#define CLK_E_ResetPullup()        do { WPUEbits.WPUE1 = 0; } while(0)
#define CLK_E_SetPushPull()        do { ODCONEbits.ODCE1 = 0; } while(0)
#define CLK_E_SetOpenDrain()       do { ODCONEbits.ODCE1 = 1; } while(0)
#define CLK_E_SetAnalogMode()      do { ANSELEbits.ANSELE1 = 1; } while(0)
#define CLK_E_SetDigitalMode()     do { ANSELEbits.ANSELE1 = 0; } while(0)

// get/set CLK_D aliases
#define CLK_D_TRIS                 TRISHbits.TRISH0
#define CLK_D_LAT                  LATHbits.LATH0
#define CLK_D_PORT                 PORTHbits.RH0
#define CLK_D_WPU                  WPUHbits.WPUH0
#define CLK_D_OD                   ODCONHbits.ODCH0
#define CLK_D_SetHigh()            do { LATHbits.LATH0 = 1; } while(0)
#define CLK_D_SetLow()             do { LATHbits.LATH0 = 0; } while(0)
#define CLK_D_Toggle()             do { LATHbits.LATH0 = ~LATHbits.LATH0; } while(0)
#define CLK_D_GetValue()           PORTHbits.RH0
#define CLK_D_SetDigitalInput()    do { TRISHbits.TRISH0 = 1; } while(0)
#define CLK_D_SetDigitalOutput()   do { TRISHbits.TRISH0 = 0; } while(0)
#define CLK_D_SetPullup()          do { WPUHbits.WPUH0 = 1; } while(0)
#define CLK_D_ResetPullup()        do { WPUHbits.WPUH0 = 0; } while(0)
#define CLK_D_SetPushPull()        do { ODCONHbits.ODCH0 = 0; } while(0)
#define CLK_D_SetOpenDrain()       do { ODCONHbits.ODCH0 = 1; } while(0)

// get/set CLK_D1 aliases
#define CLK_D1_TRIS                 TRISHbits.TRISH1
#define CLK_D1_LAT                  LATHbits.LATH1
#define CLK_D1_PORT                 PORTHbits.RH1
#define CLK_D1_WPU                  WPUHbits.WPUH1
#define CLK_D1_OD                   ODCONHbits.ODCH1
#define CLK_D1_SetHigh()            do { LATHbits.LATH1 = 1; } while(0)
#define CLK_D1_SetLow()             do { LATHbits.LATH1 = 0; } while(0)
#define CLK_D1_Toggle()             do { LATHbits.LATH1 = ~LATHbits.LATH1; } while(0)
#define CLK_D1_GetValue()           PORTHbits.RH1
#define CLK_D1_SetDigitalInput()    do { TRISHbits.TRISH1 = 1; } while(0)
#define CLK_D1_SetDigitalOutput()   do { TRISHbits.TRISH1 = 0; } while(0)
#define CLK_D1_SetPullup()          do { WPUHbits.WPUH1 = 1; } while(0)
#define CLK_D1_ResetPullup()        do { WPUHbits.WPUH1 = 0; } while(0)
#define CLK_D1_SetPushPull()        do { ODCONHbits.ODCH1 = 0; } while(0)
#define CLK_D1_SetOpenDrain()       do { ODCONHbits.ODCH1 = 1; } while(0)

// get/set CLK_G aliases
#define CLK_G_TRIS                 TRISHbits.TRISH2
#define CLK_G_LAT                  LATHbits.LATH2
#define CLK_G_PORT                 PORTHbits.RH2
#define CLK_G_WPU                  WPUHbits.WPUH2
#define CLK_G_OD                   ODCONHbits.ODCH2
#define CLK_G_SetHigh()            do { LATHbits.LATH2 = 1; } while(0)
#define CLK_G_SetLow()             do { LATHbits.LATH2 = 0; } while(0)
#define CLK_G_Toggle()             do { LATHbits.LATH2 = ~LATHbits.LATH2; } while(0)
#define CLK_G_GetValue()           PORTHbits.RH2
#define CLK_G_SetDigitalInput()    do { TRISHbits.TRISH2 = 1; } while(0)
#define CLK_G_SetDigitalOutput()   do { TRISHbits.TRISH2 = 0; } while(0)
#define CLK_G_SetPullup()          do { WPUHbits.WPUH2 = 1; } while(0)
#define CLK_G_ResetPullup()        do { WPUHbits.WPUH2 = 0; } while(0)
#define CLK_G_SetPushPull()        do { ODCONHbits.ODCH2 = 0; } while(0)
#define CLK_G_SetOpenDrain()       do { ODCONHbits.ODCH2 = 1; } while(0)

// get/set CLK_B aliases
#define CLK_B_TRIS                 TRISHbits.TRISH3
#define CLK_B_LAT                  LATHbits.LATH3
#define CLK_B_PORT                 PORTHbits.RH3
#define CLK_B_WPU                  WPUHbits.WPUH3
#define CLK_B_OD                   ODCONHbits.ODCH3
#define CLK_B_SetHigh()            do { LATHbits.LATH3 = 1; } while(0)
#define CLK_B_SetLow()             do { LATHbits.LATH3 = 0; } while(0)
#define CLK_B_Toggle()             do { LATHbits.LATH3 = ~LATHbits.LATH3; } while(0)
#define CLK_B_GetValue()           PORTHbits.RH3
#define CLK_B_SetDigitalInput()    do { TRISHbits.TRISH3 = 1; } while(0)
#define CLK_B_SetDigitalOutput()   do { TRISHbits.TRISH3 = 0; } while(0)
#define CLK_B_SetPullup()          do { WPUHbits.WPUH3 = 1; } while(0)
#define CLK_B_ResetPullup()        do { WPUHbits.WPUH3 = 0; } while(0)
#define CLK_B_SetPushPull()        do { ODCONHbits.ODCH3 = 0; } while(0)
#define CLK_B_SetOpenDrain()       do { ODCONHbits.ODCH3 = 1; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/