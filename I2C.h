// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef I2C_H
#define	I2C_H

#include <xc.h> // include processor files - each processor file is guarded. 
#include <stdint.h>

void I2C_Initialize();
void I2C_Master_Idle (void);
void I2C_Master_Wait (void);
void I2C_Master_Start(void);
void I2C_Master_Restart(void);
void I2C_Master_Stop (void);
void I2C_Master_NAK (void);
void I2C_Master_Write (uint8_t data);
uint8_t I2C_Master_Read (void);

#endif

