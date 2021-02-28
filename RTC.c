#include <xc.h>
#include <stdint.h>
#include <string.h>
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/device_config.h"
#include "RTC.h"

static void rtcc_write(uint8_t addr, uint8_t data);
static uint8_t rtcc_read(uint8_t addr);
static void rtc6_EEPRWriteLatchEnable(void);
static void rtc6_EEPRWriteLatchDisable(void);
static uint8_t rtc6_EEPRReadStatusRegister(void);

/******************************************************************************/

DateTime_t dateTime;

static uint8_t rtcc_read(uint8_t addr) {
    return i2c_read1ByteRegister(RTCC_ADDR, addr);
}

static void rtcc_write(uint8_t addr, uint8_t data) {
    i2c_write1ByteRegister(RTCC_ADDR, addr, data);
    __delay_ms(5);
}

void rtc6_Initialize(void) {
    uint8_t reg = 0;

    dateTime.day = (rtcc_read(RTCC_DAY) & 0x07);
    rtcc_write(RTCC_DAY, (dateTime.day | 0x08));
    dateTime.sec = rtcc_read(RTCC_SECONDS);

    //Configure Control Register - SQWE=1, ALM0 = 00 {No Alarms Activated},
    //                             RS2, RS1, RS0 = 000 {1 HZ}
    rtcc_write(CONTROL_REG, ALM_NO + SQWE + MFP_01H);

    // Start the external crystal and check OSCON to know when it is running
    rtcc_write(RTCC_SECONDS, dateTime.sec | ST_SET);
    while (!reg) {
        reg = rtcc_read(RTCC_DAY);
        reg &= OSCON;
    }

    // Configure external battery enable BIT and clear the VBAT flag
    rtcc_write(RTCC_DAY, dateTime.day | (VBATEN & VBAT_CLR));

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

void rtc6_SetTime(time_t t) {

    struct tm *tm_t;
    memset(tm_t, 0, sizeof (tm_t));

    tm_t = localtime(&t);
    rtc6_SetComponent(RTCC_YEAR, 0x00, tm_t->tm_year % 100); // RTC only has two digits for year
    rtc6_SetComponent(RTCC_MONTH, 0xD0, tm_t->tm_mon + 1); // time.h gives January as zero, clock expects 1
    rtc6_SetComponent(RTCC_DATE, 0x00, tm_t->tm_mday);
    rtc6_SetComponent(RTCC_MINUTES, 0x00, tm_t->tm_min);
    rtc6_SetComponent(RTCC_SECONDS, 0x80, tm_t->tm_sec);
    rtc6_SetComponent(RTCC_HOUR, 0x00, tm_t->tm_hour);
}

static uint8_t rtc6_GetComponent(uint8_t location, uint8_t mask){
    uint8_t working = rtcc_read(location) & mask;
    return (working & 0x0F) + (((working & (mask & 0xF0)) >> 4) * 10);
}

time_t rtc6_GetTime(void) {
    struct tm tm_t;
    memset(&tm_t, 0, sizeof (tm_t));
    
    tm_t.tm_year = rtc6_GetComponent(RTCC_YEAR, 0xFF) + 100; // Result only has two digits, this assumes 20xx
    tm_t.tm_mon = rtc6_GetComponent(RTCC_MONTH, 0x1F) - 1; // time.h expects January as zero, clock gives 1
    tm_t.tm_mday = rtc6_GetComponent(RTCC_DATE, 0x3F);
    tm_t.tm_hour = rtc6_GetComponent(RTCC_HOUR, 0x3F);
    tm_t.tm_min = rtc6_GetComponent(RTCC_MINUTES, 0x7F);
    tm_t.tm_sec = rtc6_GetComponent(RTCC_SECONDS, 0x7F);

    return mktime(&tm_t);
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

/******************************************************************************/

static void rtc6_EEPRWriteLatchEnable(void) {
    i2c_write1ByteRegister(EEADDR, STATUS, EEPROM_UNLOCK);
}

static void rtc6_EEPRWriteLatchDisable(void) {
    i2c_write1ByteRegister(EEADDR, STATUS, EEPROM_LOCK);
}

static uint8_t rtc6_EEPRReadStatusRegister(void) {
    i2c_read1ByteRegister(EEADDR, STATUS);
}

uint8_t rtc6_ReadByteEEPROM(uint8_t addr) {
    uint8_t stat_reg;

    rtc6_EEPRWriteLatchDisable(); //Disable write latch

    do {
        stat_reg = rtc6_EEPRReadStatusRegister(); //Read Status Register
    } while ((stat_reg & 0x03) != 0x00);

    return i2c_read1ByteRegister(EEADDR, addr);
}

void rtc6_WriteByteEEPROM(uint8_t addr, uint8_t data) {
    uint8_t stat_reg;

    rtc6_EEPRWriteLatchEnable(); //Enable write latch

    do {
        stat_reg = rtc6_EEPRReadStatusRegister(); //Read Status Register
    } while ((stat_reg & 0x03) != 0x02);

    i2c_write1ByteRegister(EEADDR, addr, data);

    rtc6_EEPRWriteLatchDisable(); //Disable write latch
}