#include "Utilities.h"

typedef enum {
    AllOff = 0x00,
    AllOn = 0xFF,
    SeventhBitOn = 0x01,
    SixBitOn = 0x02,
    FifthBitOn = 0x04,
    FourBitOn = 0x08,
    ThirdBitOn = 0x10,
    SecondBitOn = 0x20,
    FirstBitOn = 0x40,
    ZeroBitOn = 0x80
} ByteValues;