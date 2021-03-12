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

// get/set RTC6_INT aliases
#define RTC6_INT_TRIS                 TRISBbits.TRISB5
#define RTC6_INT_LAT                  LATBbits.LATB5
#define RTC6_INT_PORT                 PORTBbits.RB5
#define RTC6_INT_WPU                  WPUBbits.WPUB5
#define RTC6_INT_OD                   ODCONBbits.ODCB5
#define RTC6_INT_ANS                  ANSELBbits.ANSELB5
#define RTC6_INT_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define RTC6_INT_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define RTC6_INT_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RTC6_INT_GetValue()           PORTBbits.RB5
#define RTC6_INT_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define RTC6_INT_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define RTC6_INT_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define RTC6_INT_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define RTC6_INT_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define RTC6_INT_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define RTC6_INT_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define RTC6_INT_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()             do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()           do { WPUCbits.WPUC5 = 0; } while(0)

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