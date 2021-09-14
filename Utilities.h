#ifndef Utilities
#define	Utilities

#include <xc.h>
#include <stdint.h>
#include "mcc_generated_files/pin_manager.h"

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
#define SET_BIT(reg, pos) ((reg) |= 1 << pos)
#define CLEAR_BIT(reg, pos) ((reg) &= ~(1 << pos))
#define SW_On_Pressed  (SW_On_GetValue() == LOW)
#define SW_Led_Pressed  (SW_Led_GetValue() == LOW)
#define SW_Prog_Pressed  (SW_Prog_GetValue() == LOW)
#define SW_Hr_Pressed  (SW_Hr_GetValue() == LOW)
#define SW_Min_Pressed  (SW_Min_GetValue() == LOW)

#endif
