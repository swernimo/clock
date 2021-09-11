#include <stdint.h>
#include <string.h>
#include "RTCC.h"
#include "mcc_generated_files/mcc.h"
#include "I2C.h"
#include "Utilities.h"

#define EEADDR 0x64
#define RTCC_ADDR 0x6F //0x57


/*********************** RTCC Register Addresses ***************************/

#define RTCC_SECONDS                0x00
#define RTCC_MINUTES                0x01
#define RTCC_HOUR                   0x02
#define RTCC_DAY                    0x03
#define RTCC_DATE                   0x04
#define RTCC_MONTH                  0x05
#define RTCC_YEAR                   0x06

#define CONTROL_REG                 0x07
#define CALIBRATION                 0x08

#define ALARM0_SECONDS              0x0A
#define ALARM0_MINUTES              0x0B
#define ALARM0_HOUR                 0x0C
#define ALARM0_DAY                  0x0D
#define ALARM0_DATE                 0x0E
#define ALARM0_MONTH                0x0F

#define ALARM1_SECONDS              0x11
#define ALARM1_MINUTES              0x12
#define ALARM1_HOUR                 0x13
#define ALARM1_DAY                  0x14
#define ALARM1_DATE                 0x15
#define ALARM1_MONTH                0x16

#define PWR_DOWN_MINUTES            0x18
#define PWR_DOWN_HOUR               0x19
#define PWR_DOWN_DATE               0x1A
#define PWR_DOWN_MONTH              0x1B

#define PWR_UP_MINUTES              0x1C
#define PWR_UP_HOUR                 0x1D
#define PWR_UP_DATE                 0x1E
#define PWR_UP_MONTH                0x1F

#define MAC_ADDR_48                 0x02
#define MAC_ADDR_64                 0x00


/******************************************************************************/

#define  SQWE                       0x40            //  Square Wave Enable BIT
#define  ALM_NO                     0x00            //  no alarm activated
#define  MFP_01H                    0x00            //  MFP = SQWAV(01 HERZ)
#define  OSCON                      0x20            //  state of the oscillator(running or not)
#define  VBATEN                     0x08            //  enable battery for back-up
#define  VBAT_CLR                   0xEF            //  Mask to clear VBAT flag BIT
#define  EXTOSC                     0x08            //  enable external 32khz signal
#define  ST_SET                     0x80            //  start oscillator

#define EEPROM_LOCK 0x0C
#define EEPROM_UNLOCK 0x00

#define EEPR_PAGE_SIZE               8

#define Program_Set_Reg 0x21
#define Program_Mode_Reg 0x20

/******************************************************************************/

static void rtcc_write(uint8_t addr, uint8_t data);
static uint8_t rtcc_read(uint8_t addr);
static void rtc6_EEPRWriteLatchEnable(void);
static void rtc6_EEPRWriteLatchDisable(void);
static uint8_t rtc6_EEPRReadStatusRegister(void);

/******************************************************************************/

DateTime_t dateTime;

static uint8_t rtcc_read(uint8_t addr) {
    return I2C_Read(RTCC_ADDR, addr);
}

static void rtcc_write(uint8_t addr, uint8_t data) {
    I2C_Write(RTCC_ADDR, addr, data);
}

void rtc6_Initialize(void) {
    //Configure Control Register - SQWE=1, ALM0 = 00 {No Alarms Activated},
    //                             RS2, RS1, RS0 = 000 {1 HZ}
    rtcc_write(CONTROL_REG, ALM_NO + SQWE + MFP_01H);

    // Start the external crystal and check OSCON to know when it is running
    rtcc_write(RTCC_SECONDS, dateTime.sec | ST_SET);
    uint8_t reg;
    while (!reg) {
        reg = rtcc_read(RTCC_DAY);
        reg &= OSCON;
    }

    // Configure external battery enable BIT and clear the VBAT flag
    rtcc_write(RTCC_DAY, dateTime.day | (VBATEN & VBAT_CLR));
    rtcc_write(Program_Mode_Reg, 0x00);
    /*
     check if device has been programmed already
     * if not default time to midnight
     * clear the alarms
     * if yes no need to do anything
     */
    bool clockProgrammed = rtcc_clock_programmed();
    if(!clockProgrammed) {
        rtcc_write(Program_Mode_Reg, 0x00);
        rtc6_ClearAlarm0();
        rtc6_ClearAlarm1();
        //disable both alarms 
//        struct tm midnight = { 0, 0, 12, 1, 0, 121 }; 
//        time_t now = time(NULL);
//        now.tm_hour = 12;
//        time_t rawtime = mktime(&midnight);
//        rtc6_SetTime(rawtime);
    }
}

void rtc6_EnableAlarms(bool alarm0, bool alarm1){
    uint8_t reg = rtcc_read(CONTROL_REG);
    reg = (reg & 0xCF) | (alarm0 << 4) | (alarm1 << 5);
    rtcc_write(CONTROL_REG, reg);
}

static void rtc6_SetComponent(uint8_t location, uint8_t mask, uint8_t time){
    uint8_t inMemory = rtcc_read(location) & mask;
    rtcc_write(location, inMemory | (time % 10) | ((time / 10) << 4)); 
}

void rtc6_SetTime(int hour, int minute, bool isAM) {
    rtc6_SetComponent(RTCC_MINUTES, 0x00, minute);
    rtc6_SetComponent(RTCC_SECONDS, 0x80, 0);
    rtc6_SetComponent(RTCC_HOUR, 0x00, hour);
    //set AM/PM flag
}

static uint8_t rtc6_GetComponent(uint8_t location, uint8_t mask){
    uint8_t working = rtcc_read(location) & mask;
    return (working & 0x0F) + (((working & (mask & 0xF0)) >> 4) * 10);
}

DateTime_t rtc6_GetTime(void) {
    
    DateTime_t datetime = {
        .sec = rtc6_GetComponent(RTCC_SECONDS, 0x7F),
        .min = rtc6_GetComponent(RTCC_MINUTES, 0x7F),
        .hr = rtc6_GetComponent(RTCC_HOUR, 0x3F),
        .year = rtc6_GetComponent(RTCC_YEAR, 0xFF) + 100,
        .month = rtc6_GetComponent(RTCC_MONTH, 0x1F),
        .date = rtc6_GetComponent(RTCC_DATE, 0x3F)
    };
    
    return datetime;
//    struct tm tm_t;
//    memset(&tm_t, 0, sizeof (tm_t));
//    
//    tm_t.tm_year = rtc6_GetComponent(RTCC_YEAR, 0xFF) + 100; // Result only has two digits, this assumes 20xx
//    tm_t.tm_mon = rtc6_GetComponent(RTCC_MONTH, 0x1F) - 1; // time.h expects January as zero, clock gives 1
//    tm_t.tm_mday = rtc6_GetComponent(RTCC_DATE, 0x3F);
//    tm_t.tm_hour = rtc6_GetComponent(RTCC_HOUR, 0x3F);
//    tm_t.tm_min = rtc6_GetComponent(RTCC_MINUTES, 0x7F);
//    tm_t.tm_sec = rtc6_GetComponent(RTCC_SECONDS, 0x7F);
//
//    return mktime(&tm_t);
}

void rtc6_SetAlarm0(struct tm tm_t, bool almpol, uint8_t mask){
    rtcc_write(ALARM0_SECONDS, tm_t.tm_sec);
    rtcc_write(ALARM0_MINUTES, tm_t.tm_min);
    rtcc_write(ALARM0_HOUR, tm_t.tm_hour);
    rtcc_write(ALARM0_DATE, tm_t.tm_mday);
    rtcc_write(ALARM0_MONTH, tm_t.tm_mon + 1); // time.h gives January as zero, clock expects 1
    rtcc_write(ALARM0_DAY, tm_t.tm_wday | almpol << 7 | mask << 4);
}

void rtc6_ClearAlarm0(void){
    uint8_t reg = rtcc_read(ALARM0_DAY);
    rtcc_write(ALARM0_DAY, reg);
}

void rtc6_SetAlarm1(struct tm tm_t, bool almpol, uint8_t mask){
    rtcc_write(ALARM1_SECONDS, tm_t.tm_sec);
    rtcc_write(ALARM1_MINUTES, tm_t.tm_min);
    rtcc_write(ALARM1_HOUR, tm_t.tm_hour);
    rtcc_write(ALARM1_DATE, tm_t.tm_mday);
    rtcc_write(ALARM1_MONTH, tm_t.tm_mon + 1); // time.h gives January as zero, clock expects 1
    rtcc_write(ALARM1_DAY, tm_t.tm_wday | almpol << 7 | mask << 4);
}

void rtc6_ClearAlarm1(void){
    uint8_t reg = rtcc_read(ALARM1_DAY);
    rtcc_write(ALARM1_DAY, reg);
}

bool rtcc_clock_programmed(){
    uint8_t progSetReg = rtcc_read(Program_Set_Reg);
    bool result = CHECK_BIT(progSetReg, 0);
    return result;
}

bool rtcc_alarm0_programmed(){
    uint8_t progSetReg = rtcc_read(Program_Set_Reg);
    bool result = CHECK_BIT(progSetReg, 1);
    return result;
}

bool rtcc_alarm1_programmed(){
    uint8_t progSetReg = rtcc_read(Program_Set_Reg);
    bool result = CHECK_BIT(progSetReg, 2);
    return result;
}

void rtcc_set_clock_programmed() {
    uint8_t reg = rtcc_read(Program_Mode_Reg);
    reg |= (0x01);
    rtcc_write(Program_Mode_Reg, reg);
}