#ifndef TMR_775ms_H
#define TMR_775ms_H

#include <stdint.h>
#include <stdbool.h>

void TMR_775ms_Initialize(void);

void TMR_775ms_StartTimer(void);

void TMR_775ms_StopTimer(void);

uint8_t TMR_775ms_ReadTimer(void);

void TMR_775ms_WriteTimer(uint8_t timerVal);

void TMR_775ms_Reload(uint8_t periodVal);

bool TMR_775ms_HasOverflowOccured(void);

#endif