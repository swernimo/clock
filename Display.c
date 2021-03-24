#include "Display.h"
#include <stdint.h>
#include "./mcc_generated_files/mcc.h"
#include <string.h>

static void DisplayHour_1() {
    Display_2a_LAT = LOW;
    Display_2b_LAT = HIGH;
    Display_2c_LAT = HIGH;
    Display_2d_LAT = LOW;
    Display_2e_LAT = LOW;
    Display_2f_LAT = LOW;
    Display_2g_LAT = LOW;
}

static void DisplayHour_2() {
    Display_2a_LAT = HIGH;
    Display_2b_LAT = HIGH;
    Display_2c_LAT = LOW;
    Display_2d_LAT = HIGH;
    Display_2e_LAT = HIGH;
    Display_2f_LAT = LOW;
    Display_2g_LAT = HIGH;
}

static void DisplayHour_3() {
    Display_2a_LAT = HIGH;
    Display_2b_LAT = HIGH;
    Display_2c_LAT = HIGH;
    Display_2d_LAT = HIGH;
    Display_2e_LAT = LOW;
    Display_2f_LAT = LOW;
    Display_2g_LAT = HIGH;
}

static void DisplayHour_4() {
    Display_2a_LAT = LOW;
    Display_2b_LAT = HIGH;
    Display_2c_LAT = HIGH;
    Display_2d_LAT = LOW;
    Display_2e_LAT = LOW;
    Display_2f_LAT = HIGH;
    Display_2g_LAT = HIGH;
}

static void DisplayHour_5() {
    Display_2a_LAT = HIGH;
    Display_2b_LAT = LOW;
    Display_2c_LAT = HIGH;
    Display_2d_LAT = HIGH;
    Display_2e_LAT = LOW;
    Display_2f_LAT = HIGH;
    Display_2g_LAT = HIGH;
}

static void DisplayHour_6() {
    Display_2a_LAT = LOW;
    Display_2b_LAT = LOW;
    Display_2c_LAT = HIGH;
    Display_2d_LAT = HIGH;
    Display_2e_LAT = HIGH;
    Display_2f_LAT = HIGH;
    Display_2g_LAT = HIGH;
}

static void DisplayHour_7() {
    Display_2a_LAT = HIGH;
    Display_2b_LAT = HIGH;
    Display_2c_LAT = HIGH;
    Display_2d_LAT = LOW;
    Display_2e_LAT = LOW;
    Display_2f_LAT = LOW;
    Display_2g_LAT = LOW;
}

static void DisplayHour_8() {
    Display_2a_LAT = HIGH;
    Display_2b_LAT = HIGH;
    Display_2c_LAT = HIGH;
    Display_2d_LAT = HIGH;
    Display_2e_LAT = HIGH;
    Display_2f_LAT = HIGH;
    Display_2g_LAT = HIGH;
}

static void DisplayHour_9() {
    Display_2a_LAT = HIGH;
    Display_2b_LAT = HIGH;
    Display_2c_LAT = HIGH;
    Display_2d_LAT = LOW;
    Display_2e_LAT = LOW;
    Display_2f_LAT = HIGH;
    Display_2g_LAT = HIGH;
}

static void DisplayHour_0() {
    Display_2a_LAT = HIGH;
    Display_2b_LAT = HIGH;
    Display_2c_LAT = HIGH;
    Display_2d_LAT = HIGH;
    Display_2e_LAT = HIGH;
    Display_2f_LAT = HIGH;
    Display_2g_LAT = LOW;
}

static void DisplayHour(int hour) {
    Display_One_SetLow();
    switch(hour) {
        case 1:
            DisplayHour_1();
            break;
        case 2:
            DisplayHour_2();
            break;
        case 3:
            DisplayHour_3();
            break;
        case 4:
            DisplayHour_4();
            break;
        case 5:
            DisplayHour_5();
            break;
        case 6:
            DisplayHour_6();
            break;
        case 7:
            DisplayHour_7();
            break;
        case 8:
            DisplayHour_8();
            break;
        case 9:
            DisplayHour_9();
            break;
        case 10:
            Display_One_SetHigh();
            DisplayHour_0();
            break;
        case 11:
            Display_One_SetHigh();
            DisplayHour_1();
            break;
        case 12:
            Display_One_SetHigh();
            DisplayHour_2();
            break;
    }
}

void DisplayTime(int hour, int minute, bool isPm){
    DisplayHour(hour);
    LED_PM_LAT = isPm;
}