/*
 * File:   I2C.c
 * Author: swern
 *
 * Created on February 26, 2021, 6:57 AM
 */


#include <xc.h>
#include "I2C.h"
#include "mcc_generated_files/pin_manager.h"

void I2C_Initialize()
{
    //  SDA_DIR=1;
   // SCK_DIR=1;
//    SSP1STAT = 0x80;
//    SSP1CON1 = 0x28;
//    SSP1CON2 = 0x00;
//    SSP1ADD  = 0x19;// intially 19
//    SSP1CON1bits.SSPEN = 0;
}

void I2C_Master_Idle (void)
{
//  while ((SSP1STATbits.RW) || (SSP1CON2 & 0x1F)); // Transmit is in progress
}

void I2C_Master_Wait (void)
{
//    while(!SSP1IF);                              //wait till SSPIF flag is set
//    SSP1IF=0;
}

void I2C_Master_Start(void)
{
//  I2C_Master_Idle();    
//  SSP1CON2bits.SEN = 1;  // Initiate start condition
//  I2C_Master_Wait();
}

void I2C_Master_Restart(void)
{
//  SSP1CON2bits.RSEN = 1; // Initiate repeated start condition
//  I2C_Master_Wait();
}

void I2C_Master_Stop (void)
{
//  SSP1CON2bits.PEN = 1; //Initiate stop condition
//  I2C_Master_Wait();
//  SSP1CON1bits.SSPEN = 0;
}

void I2C_Master_NAK (void)
{
//    SSP1CON2bits.ACKDT = 1; //Set as negative acknowledgement
//    SSP1CON2bits.ACKEN=1;  //Initiate negative acknowledgement signal
//    I2C_Master_Wait();
}

void I2C_Master_Write (uint8_t data)
{
//    while (1)
//    {
//        SSP1BUF = data;    //Write data to SSPBUF
//        I2C_Master_Wait(); // Wait
//        if (SSP1CON2bits.ACKSTAT) // Check for ack
//        {
//            I2C_Master_Restart(); // Restart if nak
//        } else break; 
//    }
}

uint8_t I2C_Master_Read (void)
{
//  SSP1CON2bits.RCEN = 1;  // Enable reception
//  while (!SSP1STATbits.BF) {}
//  SSP1CON2bits.RCEN = 0; // Disable reception
//  return SSP1BUF;  // Read data
}

