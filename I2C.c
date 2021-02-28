#include <xc.h>
#include <stdbool.h>
#include "I2C.h"
#include "I2C_Types.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/device_config.h"
#include "I2C1_Driver.h"
#include "I2C_Master.h"

static i2c_operations_t returnStop(void *p);
static i2c_operations_t returnReset(void *p);

void I2C_Initialize()
{
    SSP1CON1 = 0x38;
    SSP1CON2 = 0x00; 
    SSP1STAT = 0x40; //0x80
    SSP1ADD = 0x19;
    SSP1CON1bits.SSPEN = 0;
}

void I2C_Master_Idle (void)
{
  while ((SSP1STATbits.RW) || (SSP1CON2 & 0x1F)); // Transmit is in progress
}

void I2C_Master_Wait (void)
{
    while(!SSP1IF);                              //wait till SSPIF flag is set
    SSP1IF=0;
}

void I2C_Master_Start(void)
{
    I2C_Master_Idle();
    SSP1CON2bits.SEN = 1; 
    I2C_Master_Wait();
}

void I2C_Master_Restart(void)
{
  SSP1CON2bits.RSEN = 1; // Initiate repeated start condition
  I2C_Master_Wait();
}

void I2C_Master_Stop (void)
{
    I2C_Master_Idle();
    SSP1CON2bits.PEN = 1;
    I2C_Master_Wait();
    SSP1CON1bits.SSPEN = 0;
}

void I2C_Master_NAK (void)
{
    I2C_Master_Idle();
    SSP1CON2bits.ACKDT = 0; //Set as negative acknowledgement
    SSP1CON2bits.ACKEN=1;  //Initiate negative acknowledgement signal
    I2C_Master_Wait();
}

void I2C_Master_Write (uint8_t data)
{
    while (1)
    {
        SSP1BUF = data;    //Write data to SSPBUF
        I2C_Master_Wait(); // Wait
        if (SSP1CON2bits.ACKSTAT) // Check for ack
        {
            I2C_Master_Restart(); // Restart if nak
        } else break; 
    }
    I2C_Master_Idle();
}

uint8_t I2C_Master_Read (void)
{
  SSP1CON2bits.RCEN = 1;  // Enable reception
  while (!SSP1STATbits.BF) {}
  SSP1CON2bits.RCEN = 0; // Disable reception
  return SSP1BUF;  // Read data
}

i2c_error_t I2C_Master_Open(uint8_t addr){
     i2c_error_t ret = I2C_BUSY;
    
    if(!i2c_status.inUse)
    {
        i2c_status.address = addr;
        i2c_status.busy = 0;
        i2c_status.inUse = 1;
        i2c_status.addressNACKCheck = 0;
        i2c_status.state = I2C_RESET;
        i2c_status.time_out_value = 500; // MCC should determine a reasonable starting value here.
        i2c_status.bufferFree = 1;

        // set all the call backs to a default of sending stop
        i2c_status.callbackTable[i2c_dataComplete]=returnStop;
        i2c_status.callbackPayload[i2c_dataComplete] = NULL;
        i2c_status.callbackTable[i2c_writeCollision]=returnStop;
        i2c_status.callbackPayload[i2c_writeCollision] = NULL;
        i2c_status.callbackTable[i2c_addressNACK]=returnStop;
        i2c_status.callbackPayload[i2c_addressNACK] = NULL;
        i2c_status.callbackTable[i2c_dataNACK]=returnStop;
        i2c_status.callbackPayload[i2c_dataNACK] = NULL;
        i2c_status.callbackTable[i2c_timeOut]=returnReset;
        i2c_status.callbackPayload[i2c_timeOut] = NULL;
        
        i2c1_driver_open();
        mssp1_clearIRQ();
        
        i2c1_driver_setBusCollisionISR(i2c_busCollisionISR);
        i2c1_driver_setI2cISR(i2c_ISR);
        
        // uncomment the IRQ enable for an interrupt driven driver.
//        mssp1_enableIRQ();

        ret = I2C_NOERR;
    }
    return ret;
}
