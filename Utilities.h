#ifndef Utilities
#define	Utilities

#include <xc.h>
#include <stdint.h>
#include "mcc_generated_files/pin_manager.h"

#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))
#define SW_On_Pressed  (SW_On_GetValue() == LOW)

#endif
