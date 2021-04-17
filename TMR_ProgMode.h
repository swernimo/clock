#ifndef TMR_ProgMode_H
#define TMR_ProgMode_H

#include <stdbool.h>
#include <stdint.h>

void TMR_ProgMode_Initialize(void);

void TMR_ProgMode_StartTimer(void);

void TMR_ProgMode_StopTimer(void);

bool TMR_ProgMode_HasOverflowOccured(void);

bool TMR_ProgMode_IsRunning(void);

void TMR_ProgMode_Restart(void);
#endif
