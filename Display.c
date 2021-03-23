#include "Display.h"
#include <stdint.h>
#include "./mcc_generated_files/mcc.h"
#include <string.h>

//order for all display arrays is ABCDEFG
int displayArray[10][7] = {
    { 1, 1, 1, 1, 1, 1, 0 },
    { 0, 1, 1, 0, 0, 0, 0 },
    { 1, 1, 0, 1, 1, 0, 1 },
    { 1, 1, 1, 0, 0, 1, 1 },
    { 0, 1, 1, 0, 0, 1, 1 },
    { 1, 0, 1, 1, 0, 1, 1 },
    { 0, 0, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 0, 0, 0, 0 },
    { 1, 1, 1, 1, 1, 1, 1 },
    { 1, 1, 1, 0, 0, 1, 1 }
};

//int minuteTens[6][7] = {
//    { 1, 1, 1, 1, 1, 1, 0 },
//    { 0, 1, 1, 0, 0, 0, 0 },
//    { 1, 1, 0, 1, 1, 0, 1 },
//    { 1, 1, 1, 0, 0, 1, 1 },
//    { 0, 1, 1, 0, 0, 1, 1 },
//    { 1, 0, 1, 1, 0, 1, 1 },
//};
//
//int minuteOnes[10][7] = {
//    { 1, 1, 1, 1, 1, 1, 0 },
//    { 0, 1, 1, 0, 0, 0, 0 },
//    { 1, 1, 0, 1, 1, 0, 1 },
//    { 1, 1, 1, 0, 0, 1, 1 },
//    { 0, 1, 1, 0, 0, 1, 1 },
//    { 1, 0, 1, 1, 0, 1, 1 },
//    { 0, 0, 1, 1, 1, 1, 1 },
//    { 1, 1, 1, 0, 0, 0, 0 },
//    { 1, 1, 1, 1, 1, 1, 1 },
//    { 1, 1, 1, 0, 0, 1, 1 }    
//};

static void DisplayHourOnes(int hour) {
    int reminder = hour % 10;
    int values[7];
    memcpy(values, displayArray[reminder], 7);
    Display_2a_LAT = values[0];
    Display_2b_LAT = values[1];
    Display_2c_LAT = values[2];
    Display_2d_LAT = values[3];
    Display_2e_LAT = values[4];
    Display_2f_LAT = values[5];
    Display_2g_LAT = values[6];
}

static void DisplayTensMinute(int minute) {
    int tensMin = minute / 10;
    int values[7];
    memcpy(values, displayArray[tensMin], 7);
    Display_3a_LAT = values[0];
    Display_3b_LAT = values[1];
    Display_3c_LAT = values[2];
    Display_3d_LAT = values[3];
    Display_3e_LAT = values[4];
    Display_3f_LAT = values[5];
    Display_3g_LAT = values[6];
}

static void DisplayOneMinute(int minute) {
    int reminder = minute % 10;
    int values[7];
    memcpy(values, displayArray[reminder], 7);
    Display_4a_LAT = values[0];
    Display_4b_LAT = values[1];
    Display_4c_LAT = values[2];
    Display_4d_LAT = values[3];
    Display_4e_LAT = values[4];
    Display_4f_LAT = values[5];
    Display_4g_LAT = values[6];
}

void DisplayTime(int hour, int minute, bool isPm){
    if (hour >= 10) {
        Display_One_SetHigh();
    } else {
        Display_One_SetLow();        
    }
    DisplayHourOnes(hour);
    DisplayTensMinute(minute);
    DisplayOneMinute(minute);
    LED_PM_LAT = isPm;
}