#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/tmr0.h"
//#include "I2C.h"
//#include "RTC.h"
//
//#define OSC_ON 0x80
//#define MCP7940_ADDR 0x6F
//#define ADDR_SEC 0x00 
//#define ADDR_MIN 0x01
//#define ADDR_HOUR 0x02
//
//unsigned char sec, min, hr,day, dat, mon, yr ; // time variables, BCD format
//unsigned char rtcc_buf       ;   // global data buffer for the RTCC
//unsigned char err_cnt = 0x00 ;   // error counter ; slave's I2C_NACK
//unsigned char err_flg = 0x00 ;   // error flag ; reacts at slave's NACK & MSSP1IF  
//
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

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();
//    I2C_Initialize();
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    TMR0_StartTimer();
    
//    MCP7940_Write(MCP7940_ADDR, ADDR_SEC, 0x0 | OSC_ON); // sec to zero BUT osc on
//    MCP7940_Write(MCP7940_ADDR, ADDR_MIN, 0x59); //  min to 59
//    MCP7940_Write(MCP7940_ADDR, ADDR_HOUR, 0x12); //  hour to 12
    while (1)
    {
        // Add your application code
        if(TMR0_HasOverflowOccured()){
//            sec = MCP7940_Read(MCP7940_ADDR, ADDR_SEC);        
//            min = MCP7940_Read(MCP7940_ADDR, ADDR_MIN);
            TMR0_StopTimer();
            PIR0bits.TMR0IF = 0;
            LED_Toggle();
            TMR0_StartTimer();
        }
    }
}