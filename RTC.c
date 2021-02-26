/*
 * File:   RTC.c
 * Author: swern
 *
 * Created on February 26, 2021, 7:12 AM
 */


#include <xc.h>
#include "mcc_generated_files/device_config.h"
#include "I2C.h"
#include "RTC.h"

//void MCP7940_Write (uint8_t dev_addr, uint8_t reg_addr, uint8_t reg_data)
//{
// 
//    I2C_Master_Start();  // Send START condition
//    I2C_Master_Write((dev_addr << 1) & 0xfe );// Send address with R/W cleared for write
//    I2C_Master_Write(reg_addr);  // Write reg_addr
//    I2C_Master_Write(reg_data);  // Write reg_data    
//    I2C_Master_Stop(); //Stop condition
//    __delay_ms(200);
//}
//
//uint8_t MCP7940_Read (uint8_t dev_addr, uint8_t reg_addr)
//{
//    I2C_Master_Start();           //Start condition
//    I2C_Master_Write((dev_addr << 1) | 0x01); //7 bit address + Read
//    I2C_Master_Write(reg_addr);  // Write reg_addr
//    uint8_t temp = I2C_Master_Read(); // read data t
//    I2C_Master_NAK();           // Send NAK
//    I2C_Master_Stop();          //Stop condition
//    __delay_ms(200);
//    return temp;
//}