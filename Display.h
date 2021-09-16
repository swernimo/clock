#ifndef Display
#define	Display

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

void DisplayTime(int hour, int minute, bool isPm);
void FlashMidnight();

#endif