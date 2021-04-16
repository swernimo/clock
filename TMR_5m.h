 
#ifndef TMR_5m_H
#define	TMR_5m_H

#include <xc.h>
#include <stdbool.h>

void TMR_5m_Initialize(void);

void TMR_5m_StartTimer(void);

void TMR_5m_StopTimer(void);

//uint16_t TMR_5m_ReadTimer(void);
//
//void TMR_5m_WriteTimer(uint16_t timerVal);

//void TMR_5m_Reload(void);

bool TMR_5m_HasOverflowOccured(void);

#endif

