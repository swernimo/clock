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

// get/set Display_One aliases
#define Display_One_TRIS                 TRISAbits.TRISA0
#define Display_One_LAT                  LATAbits.LATA0
#define Display_One_PORT                 PORTAbits.RA0
#define Display_One_WPU                  WPUAbits.WPUA0
#define Display_One_OD                   ODCONAbits.ODCA0
#define Display_One_ANS                  ANSELAbits.ANSELA0
#define Display_One_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define Display_One_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define Display_One_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define Display_One_GetValue()           PORTAbits.RA0
#define Display_One_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define Display_One_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define Display_One_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define Display_One_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define Display_One_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define Display_One_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define Display_One_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define Display_One_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set Display_2a aliases
#define Display_2a_TRIS                 TRISAbits.TRISA1
#define Display_2a_LAT                  LATAbits.LATA1
#define Display_2a_PORT                 PORTAbits.RA1
#define Display_2a_WPU                  WPUAbits.WPUA1
#define Display_2a_OD                   ODCONAbits.ODCA1
#define Display_2a_ANS                  ANSELAbits.ANSELA1
#define Display_2a_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define Display_2a_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define Display_2a_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define Display_2a_GetValue()           PORTAbits.RA1
#define Display_2a_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define Display_2a_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define Display_2a_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define Display_2a_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define Display_2a_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define Display_2a_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define Display_2a_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define Display_2a_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set Display_2b aliases
#define Display_2b_TRIS                 TRISAbits.TRISA2
#define Display_2b_LAT                  LATAbits.LATA2
#define Display_2b_PORT                 PORTAbits.RA2
#define Display_2b_WPU                  WPUAbits.WPUA2
#define Display_2b_OD                   ODCONAbits.ODCA2
#define Display_2b_ANS                  ANSELAbits.ANSELA2
#define Display_2b_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define Display_2b_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define Display_2b_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define Display_2b_GetValue()           PORTAbits.RA2
#define Display_2b_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define Display_2b_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define Display_2b_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define Display_2b_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define Display_2b_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define Display_2b_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define Display_2b_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define Display_2b_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set Display_2c aliases
#define Display_2c_TRIS                 TRISAbits.TRISA3
#define Display_2c_LAT                  LATAbits.LATA3
#define Display_2c_PORT                 PORTAbits.RA3
#define Display_2c_WPU                  WPUAbits.WPUA3
#define Display_2c_OD                   ODCONAbits.ODCA3
#define Display_2c_ANS                  ANSELAbits.ANSELA3
#define Display_2c_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define Display_2c_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define Display_2c_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define Display_2c_GetValue()           PORTAbits.RA3
#define Display_2c_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define Display_2c_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define Display_2c_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define Display_2c_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define Display_2c_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define Display_2c_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define Display_2c_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define Display_2c_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set Display_2d aliases
#define Display_2d_TRIS                 TRISAbits.TRISA4
#define Display_2d_LAT                  LATAbits.LATA4
#define Display_2d_PORT                 PORTAbits.RA4
#define Display_2d_WPU                  WPUAbits.WPUA4
#define Display_2d_OD                   ODCONAbits.ODCA4
#define Display_2d_ANS                  ANSELAbits.ANSELA4
#define Display_2d_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define Display_2d_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define Display_2d_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define Display_2d_GetValue()           PORTAbits.RA4
#define Display_2d_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define Display_2d_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define Display_2d_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define Display_2d_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define Display_2d_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define Display_2d_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define Display_2d_SetAnalogMode()      do { ANSELAbits.ANSELA4 = 1; } while(0)
#define Display_2d_SetDigitalMode()     do { ANSELAbits.ANSELA4 = 0; } while(0)

// get/set Display_2e aliases
#define Display_2e_TRIS                 TRISAbits.TRISA5
#define Display_2e_LAT                  LATAbits.LATA5
#define Display_2e_PORT                 PORTAbits.RA5
#define Display_2e_WPU                  WPUAbits.WPUA5
#define Display_2e_OD                   ODCONAbits.ODCA5
#define Display_2e_ANS                  ANSELAbits.ANSELA5
#define Display_2e_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define Display_2e_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define Display_2e_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define Display_2e_GetValue()           PORTAbits.RA5
#define Display_2e_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define Display_2e_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define Display_2e_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define Display_2e_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define Display_2e_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define Display_2e_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define Display_2e_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define Display_2e_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set Display_2f aliases
#define Display_2f_TRIS                 TRISAbits.TRISA6
#define Display_2f_LAT                  LATAbits.LATA6
#define Display_2f_PORT                 PORTAbits.RA6
#define Display_2f_WPU                  WPUAbits.WPUA6
#define Display_2f_OD                   ODCONAbits.ODCA6
#define Display_2f_ANS                  ANSELAbits.ANSELA6
#define Display_2f_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define Display_2f_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define Display_2f_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define Display_2f_GetValue()           PORTAbits.RA6
#define Display_2f_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define Display_2f_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define Display_2f_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define Display_2f_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define Display_2f_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define Display_2f_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define Display_2f_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define Display_2f_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set Display_2g aliases
#define Display_2g_TRIS                 TRISAbits.TRISA7
#define Display_2g_LAT                  LATAbits.LATA7
#define Display_2g_PORT                 PORTAbits.RA7
#define Display_2g_WPU                  WPUAbits.WPUA7
#define Display_2g_OD                   ODCONAbits.ODCA7
#define Display_2g_ANS                  ANSELAbits.ANSELA7
#define Display_2g_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define Display_2g_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define Display_2g_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define Display_2g_GetValue()           PORTAbits.RA7
#define Display_2g_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define Display_2g_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define Display_2g_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define Display_2g_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define Display_2g_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define Display_2g_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define Display_2g_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define Display_2g_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set Display_3a aliases
#define Display_3a_TRIS                 TRISBbits.TRISB0
#define Display_3a_LAT                  LATBbits.LATB0
#define Display_3a_PORT                 PORTBbits.RB0
#define Display_3a_WPU                  WPUBbits.WPUB0
#define Display_3a_OD                   ODCONBbits.ODCB0
#define Display_3a_ANS                  ANSELBbits.ANSELB0
#define Display_3a_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define Display_3a_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define Display_3a_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define Display_3a_GetValue()           PORTBbits.RB0
#define Display_3a_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define Display_3a_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define Display_3a_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define Display_3a_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define Display_3a_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define Display_3a_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define Display_3a_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define Display_3a_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set Display_3b aliases
#define Display_3b_TRIS                 TRISBbits.TRISB1
#define Display_3b_LAT                  LATBbits.LATB1
#define Display_3b_PORT                 PORTBbits.RB1
#define Display_3b_WPU                  WPUBbits.WPUB1
#define Display_3b_OD                   ODCONBbits.ODCB1
#define Display_3b_ANS                  ANSELBbits.ANSELB1
#define Display_3b_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define Display_3b_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define Display_3b_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define Display_3b_GetValue()           PORTBbits.RB1
#define Display_3b_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define Display_3b_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define Display_3b_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define Display_3b_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define Display_3b_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define Display_3b_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define Display_3b_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define Display_3b_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set Display_3c aliases
#define Display_3c_TRIS                 TRISBbits.TRISB2
#define Display_3c_LAT                  LATBbits.LATB2
#define Display_3c_PORT                 PORTBbits.RB2
#define Display_3c_WPU                  WPUBbits.WPUB2
#define Display_3c_OD                   ODCONBbits.ODCB2
#define Display_3c_ANS                  ANSELBbits.ANSELB2
#define Display_3c_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define Display_3c_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define Display_3c_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define Display_3c_GetValue()           PORTBbits.RB2
#define Display_3c_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define Display_3c_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define Display_3c_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define Display_3c_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define Display_3c_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define Display_3c_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define Display_3c_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define Display_3c_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set Display_3d aliases
#define Display_3d_TRIS                 TRISBbits.TRISB3
#define Display_3d_LAT                  LATBbits.LATB3
#define Display_3d_PORT                 PORTBbits.RB3
#define Display_3d_WPU                  WPUBbits.WPUB3
#define Display_3d_OD                   ODCONBbits.ODCB3
#define Display_3d_ANS                  ANSELBbits.ANSELB3
#define Display_3d_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define Display_3d_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define Display_3d_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define Display_3d_GetValue()           PORTBbits.RB3
#define Display_3d_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define Display_3d_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define Display_3d_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define Display_3d_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define Display_3d_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define Display_3d_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define Display_3d_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define Display_3d_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set Display_3e aliases
#define Display_3e_TRIS                 TRISBbits.TRISB4
#define Display_3e_LAT                  LATBbits.LATB4
#define Display_3e_PORT                 PORTBbits.RB4
#define Display_3e_WPU                  WPUBbits.WPUB4
#define Display_3e_OD                   ODCONBbits.ODCB4
#define Display_3e_ANS                  ANSELBbits.ANSELB4
#define Display_3e_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define Display_3e_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define Display_3e_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define Display_3e_GetValue()           PORTBbits.RB4
#define Display_3e_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define Display_3e_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define Display_3e_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define Display_3e_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define Display_3e_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define Display_3e_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define Display_3e_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define Display_3e_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set Display_3f aliases
#define Display_3f_TRIS                 TRISBbits.TRISB5
#define Display_3f_LAT                  LATBbits.LATB5
#define Display_3f_PORT                 PORTBbits.RB5
#define Display_3f_WPU                  WPUBbits.WPUB5
#define Display_3f_OD                   ODCONBbits.ODCB5
#define Display_3f_ANS                  ANSELBbits.ANSELB5
#define Display_3f_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define Display_3f_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define Display_3f_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define Display_3f_GetValue()           PORTBbits.RB5
#define Display_3f_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define Display_3f_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define Display_3f_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define Display_3f_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define Display_3f_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define Display_3f_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define Display_3f_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define Display_3f_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set Display_3g aliases
#define Display_3g_TRIS                 TRISBbits.TRISB6
#define Display_3g_LAT                  LATBbits.LATB6
#define Display_3g_PORT                 PORTBbits.RB6
#define Display_3g_WPU                  WPUBbits.WPUB6
#define Display_3g_OD                   ODCONBbits.ODCB6
#define Display_3g_ANS                  ANSELBbits.ANSELB6
#define Display_3g_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define Display_3g_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define Display_3g_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define Display_3g_GetValue()           PORTBbits.RB6
#define Display_3g_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define Display_3g_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define Display_3g_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define Display_3g_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define Display_3g_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define Display_3g_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define Display_3g_SetAnalogMode()      do { ANSELBbits.ANSELB6 = 1; } while(0)
#define Display_3g_SetDigitalMode()     do { ANSELBbits.ANSELB6 = 0; } while(0)

// get/set Display_4a aliases
#define Display_4a_TRIS                 TRISBbits.TRISB7
#define Display_4a_LAT                  LATBbits.LATB7
#define Display_4a_PORT                 PORTBbits.RB7
#define Display_4a_WPU                  WPUBbits.WPUB7
#define Display_4a_OD                   ODCONBbits.ODCB7
#define Display_4a_ANS                  ANSELBbits.ANSELB7
#define Display_4a_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define Display_4a_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define Display_4a_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define Display_4a_GetValue()           PORTBbits.RB7
#define Display_4a_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define Display_4a_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define Display_4a_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define Display_4a_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define Display_4a_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define Display_4a_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define Display_4a_SetAnalogMode()      do { ANSELBbits.ANSELB7 = 1; } while(0)
#define Display_4a_SetDigitalMode()     do { ANSELBbits.ANSELB7 = 0; } while(0)

// get/set Display_4b aliases
#define Display_4b_TRIS                 TRISCbits.TRISC0
#define Display_4b_LAT                  LATCbits.LATC0
#define Display_4b_PORT                 PORTCbits.RC0
#define Display_4b_WPU                  WPUCbits.WPUC0
#define Display_4b_OD                   ODCONCbits.ODCC0
#define Display_4b_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define Display_4b_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define Display_4b_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define Display_4b_GetValue()           PORTCbits.RC0
#define Display_4b_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define Display_4b_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define Display_4b_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define Display_4b_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define Display_4b_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define Display_4b_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)

// get/set Display_4c aliases
#define Display_4c_TRIS                 TRISCbits.TRISC1
#define Display_4c_LAT                  LATCbits.LATC1
#define Display_4c_PORT                 PORTCbits.RC1
#define Display_4c_WPU                  WPUCbits.WPUC1
#define Display_4c_OD                   ODCONCbits.ODCC1
#define Display_4c_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define Display_4c_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define Display_4c_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define Display_4c_GetValue()           PORTCbits.RC1
#define Display_4c_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define Display_4c_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define Display_4c_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define Display_4c_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define Display_4c_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define Display_4c_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)

// get/set Display_4d aliases
#define Display_4d_TRIS                 TRISCbits.TRISC2
#define Display_4d_LAT                  LATCbits.LATC2
#define Display_4d_PORT                 PORTCbits.RC2
#define Display_4d_WPU                  WPUCbits.WPUC2
#define Display_4d_OD                   ODCONCbits.ODCC2
#define Display_4d_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define Display_4d_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define Display_4d_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define Display_4d_GetValue()           PORTCbits.RC2
#define Display_4d_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define Display_4d_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define Display_4d_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define Display_4d_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define Display_4d_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define Display_4d_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)

// get/set SCL1 aliases
#define SCL1_TRIS                 TRISCbits.TRISC3
#define SCL1_LAT                  LATCbits.LATC3
#define SCL1_PORT                 PORTCbits.RC3
#define SCL1_WPU                  WPUCbits.WPUC3
#define SCL1_OD                   ODCONCbits.ODCC3
#define SCL1_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define SCL1_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define SCL1_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define SCL1_GetValue()           PORTCbits.RC3
#define SCL1_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define SCL1_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define SCL1_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define SCL1_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define SCL1_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define SCL1_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)

// get/set SDA1 aliases
#define SDA1_TRIS                 TRISCbits.TRISC4
#define SDA1_LAT                  LATCbits.LATC4
#define SDA1_PORT                 PORTCbits.RC4
#define SDA1_WPU                  WPUCbits.WPUC4
#define SDA1_OD                   ODCONCbits.ODCC4
#define SDA1_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define SDA1_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define SDA1_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define SDA1_GetValue()           PORTCbits.RC4
#define SDA1_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define SDA1_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define SDA1_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define SDA1_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define SDA1_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define SDA1_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)

// get/set Display_4e aliases
#define Display_4e_TRIS                 TRISCbits.TRISC5
#define Display_4e_LAT                  LATCbits.LATC5
#define Display_4e_PORT                 PORTCbits.RC5
#define Display_4e_WPU                  WPUCbits.WPUC5
#define Display_4e_OD                   ODCONCbits.ODCC5
#define Display_4e_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define Display_4e_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define Display_4e_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define Display_4e_GetValue()           PORTCbits.RC5
#define Display_4e_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define Display_4e_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define Display_4e_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define Display_4e_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define Display_4e_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define Display_4e_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)

// get/set Display_4f aliases
#define Display_4f_TRIS                 TRISCbits.TRISC6
#define Display_4f_LAT                  LATCbits.LATC6
#define Display_4f_PORT                 PORTCbits.RC6
#define Display_4f_WPU                  WPUCbits.WPUC6
#define Display_4f_OD                   ODCONCbits.ODCC6
#define Display_4f_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define Display_4f_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define Display_4f_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define Display_4f_GetValue()           PORTCbits.RC6
#define Display_4f_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define Display_4f_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define Display_4f_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define Display_4f_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define Display_4f_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define Display_4f_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)

// get/set Display_4g aliases
#define Display_4g_TRIS                 TRISCbits.TRISC7
#define Display_4g_LAT                  LATCbits.LATC7
#define Display_4g_PORT                 PORTCbits.RC7
#define Display_4g_WPU                  WPUCbits.WPUC7
#define Display_4g_OD                   ODCONCbits.ODCC7
#define Display_4g_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define Display_4g_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define Display_4g_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define Display_4g_GetValue()           PORTCbits.RC7
#define Display_4g_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define Display_4g_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define Display_4g_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define Display_4g_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define Display_4g_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define Display_4g_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)

// get/set Display_Col aliases
#define Display_Col_TRIS                 TRISDbits.TRISD0
#define Display_Col_LAT                  LATDbits.LATD0
#define Display_Col_PORT                 PORTDbits.RD0
#define Display_Col_WPU                  WPUDbits.WPUD0
#define Display_Col_OD                   ODCONDbits.ODCD0
#define Display_Col_ANS                  ANSELDbits.ANSELD0
#define Display_Col_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define Display_Col_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define Display_Col_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define Display_Col_GetValue()           PORTDbits.RD0
#define Display_Col_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define Display_Col_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define Display_Col_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define Display_Col_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define Display_Col_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define Display_Col_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define Display_Col_SetAnalogMode()      do { ANSELDbits.ANSELD0 = 1; } while(0)
#define Display_Col_SetDigitalMode()     do { ANSELDbits.ANSELD0 = 0; } while(0)

// get/set LED aliases
#define LED_TRIS                 TRISDbits.TRISD1
#define LED_LAT                  LATDbits.LATD1
#define LED_PORT                 PORTDbits.RD1
#define LED_WPU                  WPUDbits.WPUD1
#define LED_OD                   ODCONDbits.ODCD1
#define LED_ANS                  ANSELDbits.ANSELD1
#define LED_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define LED_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define LED_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define LED_GetValue()           PORTDbits.RD1
#define LED_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define LED_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define LED_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELDbits.ANSELD1 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELDbits.ANSELD1 = 0; } while(0)

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