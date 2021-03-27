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

static void DisplayMinuteTens_Zero() {
    Display_3a_LAT = HIGH;
    Display_3b_LAT = HIGH;
    Display_3c_LAT = HIGH;
    Display_3d_LAT = HIGH;
    Display_3e_LAT = HIGH;
    Display_3f_LAT = HIGH;
    Display_3g_LAT = LOW;
}

static void DisplayMinuteTens_One() {
    Display_3a_LAT = LOW;
    Display_3b_LAT = HIGH;
    Display_3c_LAT = HIGH;
    Display_3d_LAT = LOW;
    Display_3e_LAT = LOW;
    Display_3f_LAT = LOW;
    Display_3g_LAT = LOW;
}

static void DisplayMinuteTens_Two() {
    Display_3a_LAT = HIGH;
    Display_3b_LAT = HIGH;
    Display_3c_LAT = LOW;
    Display_3d_LAT = HIGH;
    Display_3e_LAT = HIGH;
    Display_3f_LAT = LOW;
    Display_3g_LAT = HIGH;
}

static void DisplayMinuteTens_Three() {
    Display_3a_LAT = HIGH;
    Display_3b_LAT = HIGH;
    Display_3c_LAT = HIGH;
    Display_3d_LAT = HIGH;
    Display_3e_LAT = LOW;
    Display_3f_LAT = LOW;
    Display_3g_LAT = HIGH;
}

static void DisplayMinuteTens_Four() {
    Display_3a_LAT = LOW;
    Display_3b_LAT = HIGH;
    Display_3c_LAT = HIGH;
    Display_3d_LAT = LOW;
    Display_3e_LAT = LOW;
    Display_3f_LAT = HIGH;
    Display_3g_LAT = HIGH;
}

static void DisplayMinuteTens_Five() {
    Display_3a_LAT = HIGH;
    Display_3b_LAT = LOW;
    Display_3c_LAT = HIGH;
    Display_3d_LAT = HIGH;
    Display_3e_LAT = LOW;
    Display_3f_LAT = HIGH;
    Display_3g_LAT = HIGH;
}

static void DisplayMinuteOnes_Zero() {
    Display_4a_LAT = HIGH;
    Display_4b_LAT = HIGH;
    Display_4c_LAT = HIGH;
    Display_4d_LAT = HIGH;
    Display_4e_LAT = HIGH;
    Display_4f_LAT = HIGH;
    Display_4g_LAT = LOW;
}

static void DisplayMinuteOnes_One() {
    Display_4a_LAT = LOW;
    Display_4b_LAT = HIGH;
    Display_4c_LAT = HIGH;
    Display_4d_LAT = LOW;
    Display_4e_LAT = LOW;
    Display_4f_LAT = LOW;
    Display_4g_LAT = LOW;
}

static void DisplayMinuteOnes_Two() {
    Display_4a_LAT = HIGH;
    Display_4b_LAT = HIGH;
    Display_4c_LAT = LOW;
    Display_4d_LAT = HIGH;
    Display_4e_LAT = HIGH;
    Display_4f_LAT = LOW;
    Display_4g_LAT = HIGH;
}

static void DisplayMinuteOnes_Three() {
    Display_4a_LAT = HIGH;
    Display_4b_LAT = HIGH;
    Display_4c_LAT = HIGH;
    Display_4d_LAT = HIGH;
    Display_4e_LAT = LOW;
    Display_4f_LAT = LOW;
    Display_4g_LAT = HIGH;
}

static void DisplayMinuteOnes_Four() {
    Display_4a_LAT = LOW;
    Display_4b_LAT = HIGH;
    Display_4c_LAT = HIGH;
    Display_4d_LAT = LOW;
    Display_4e_LAT = LOW;
    Display_4f_LAT = HIGH;
    Display_4g_LAT = HIGH;
}

static void DisplayMinuteOnes_Five() {
    Display_4a_LAT = HIGH;
    Display_4b_LAT = LOW;
    Display_4c_LAT = HIGH;
    Display_4d_LAT = HIGH;
    Display_4e_LAT = LOW;
    Display_4f_LAT = HIGH;
    Display_4g_LAT = HIGH;
}

static void DisplayMinuteOnes_Six() {
    Display_4a_LAT = LOW;
    Display_4b_LAT = LOW;
    Display_4c_LAT = HIGH;
    Display_4d_LAT = HIGH;
    Display_4e_LAT = HIGH;
    Display_4f_LAT = HIGH;
    Display_4g_LAT = HIGH;
}

static void DisplayMinuteOnes_Seven() {
    Display_4a_LAT = HIGH;
    Display_4b_LAT = HIGH;
    Display_4c_LAT = HIGH;
    Display_4d_LAT = LOW;
    Display_4e_LAT = LOW;
    Display_4f_LAT = LOW;
    Display_4g_LAT = LOW;
}

static void DisplayMinuteOnes_Eight() {
    Display_4a_LAT = HIGH;
    Display_4b_LAT = HIGH;
    Display_4c_LAT = HIGH;
    Display_4d_LAT = HIGH;
    Display_4e_LAT = HIGH;
    Display_4f_LAT = HIGH;
    Display_4g_LAT = HIGH;
}

static void DisplayMinuteOnes_Nine() {
    Display_4a_LAT = HIGH;
    Display_4b_LAT = HIGH;
    Display_4c_LAT = HIGH;
    Display_4d_LAT = LOW;
    Display_4e_LAT = LOW;
    Display_4f_LAT = HIGH;
    Display_4g_LAT = HIGH;
}

static void DisplayMinuteZero_Nine(int minute) {
    DisplayMinuteTens_Zero();
    switch(minute) {
        case 0:
            DisplayMinuteOnes_Zero();
            break;
        case 1:
            DisplayMinuteOnes_One();
            break;
        case 2:
            DisplayMinuteOnes_Two();
            break;
        case 3:
            DisplayMinuteOnes_Three();
            break;
        case 4:
            DisplayMinuteOnes_Four();
            break;
        case 5:
            DisplayMinuteOnes_Five();
            break;
        case 6:
            DisplayMinuteOnes_Six();
            break;
        case 7:
            DisplayMinuteOnes_Seven();
            break;
        case 8:
            DisplayMinuteOnes_Eight();
            break;
        case 9:
            DisplayMinuteOnes_Nine();
            break;
    }
}

static void DisplayMinute10_20(int minute) {
    DisplayMinuteTens_One();
    switch(minute) {
        case 10:
            DisplayMinuteOnes_Zero();
            break;
        case 11:
            DisplayMinuteOnes_One();
            break;
        case 12:
            DisplayMinuteOnes_Two();
            break;
        case 13:
            DisplayMinuteOnes_Three();
            break;
        case 14:
            DisplayMinuteOnes_Four();
            break;
        case 15:
            DisplayMinuteOnes_Five();
            break;
        case 16:
            DisplayMinuteOnes_Six();
            break;
        case 17:
            DisplayMinuteOnes_Seven();
            break;
        case 18:
            DisplayMinuteOnes_Eight();
            break;
        case 19:
            DisplayMinuteOnes_Nine();
            break;
    }
}

static void DisplayMinute20_30(int minute) {
    DisplayMinuteTens_Two();
    switch(minute) {
        case 20:
            DisplayMinuteOnes_Zero();
            break;
        case 21:
            DisplayMinuteOnes_One();
            break;
        case 22:
            DisplayMinuteOnes_Two();
            break;
        case 23:
            DisplayMinuteOnes_Three();
            break;
        case 24:
            DisplayMinuteOnes_Four();
            break;
        case 25:
            DisplayMinuteOnes_Five();
            break;
        case 26:
            DisplayMinuteOnes_Six();
            break;
        case 27:
            DisplayMinuteOnes_Seven();
            break;
        case 28:
            DisplayMinuteOnes_Eight();
            break;
        case 29:
            DisplayMinuteOnes_Nine();
            break;
    }
}

static void DisplayMinute30_40(int minute) {
    DisplayMinuteTens_Three();
    switch(minute) {
        case 30:
            DisplayMinuteOnes_Zero();
            break;
        case 31:
            DisplayMinuteOnes_One();
            break;
        case 32:
            DisplayMinuteOnes_Two();
            break;
        case 33:
            DisplayMinuteOnes_Three();
            break;
        case 34:
            DisplayMinuteOnes_Four();
            break;
        case 35:
            DisplayMinuteOnes_Five();
            break;
        case 36:
            DisplayMinuteOnes_Six();
            break;
        case 37:
            DisplayMinuteOnes_Seven();
            break;
        case 38:
            DisplayMinuteOnes_Eight();
            break;
        case 39:
            DisplayMinuteOnes_Nine();
            break;
    }
}

static void DisplayMinute40_50(int minute) {
    DisplayMinuteTens_Four();
    switch(minute) {
        case 40:
            DisplayMinuteOnes_Zero();
            break;
        case 41:
            DisplayMinuteOnes_One();
            break;
        case 42:
            DisplayMinuteOnes_Two();
            break;
        case 43:
            DisplayMinuteOnes_Three();
            break;
        case 44:
            DisplayMinuteOnes_Four();
            break;
        case 45:
            DisplayMinuteOnes_Five();
            break;
        case 46:
            DisplayMinuteOnes_Six();
            break;
        case 47:
            DisplayMinuteOnes_Seven();
            break;
        case 48:
            DisplayMinuteOnes_Eight();
            break;
        case 49:
            DisplayMinuteOnes_Nine();
            break;
    }
}

static void DisplayMinute50_59(int minute) {
    DisplayMinuteTens_Five();
    switch(minute) {
        case 50:
            DisplayMinuteOnes_Zero();
            break;
        case 51:
            DisplayMinuteOnes_One();
            break;
        case 52:
            DisplayMinuteOnes_Two();
            break;
        case 53:
            DisplayMinuteOnes_Three();
            break;
        case 54:
            DisplayMinuteOnes_Four();
            break;
        case 55:
            DisplayMinuteOnes_Five();
            break;
        case 56:
            DisplayMinuteOnes_Six();
            break;
        case 57:
            DisplayMinuteOnes_Seven();
            break;
        case 58:
            DisplayMinuteOnes_Eight();
            break;
        case 59:
            DisplayMinuteOnes_Nine();
            break;
    }
}

static void DisplayMinute(int minute) {
    if (minute >= 0 && minute <= 9) {
        DisplayMinuteZero_Nine(minute);
    } else if (minute >= 10 && minute <= 19) {
        DisplayMinute10_20(minute);
    } else if (minute >= 20 && minute <= 29) {
        DisplayMinute20_30(minute);
    } else if (minute >= 30 && minute <= 39) {
        DisplayMinute30_40(minute);
    } else if (minute >= 40 && minute <= 49) {
        DisplayMinute40_50(minute);
    } else {
        DisplayMinute50_59(minute);
    }
}

void DisplayTime(int hour, int minute, bool isPm){
    DisplayHour(hour);
    DisplayMinute(minute);
    if(isPm) {
        LED_PM_LAT = HIGH;
    } else {
        LED_PM_LAT = LOW;
    }
}