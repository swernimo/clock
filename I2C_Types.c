#include "I2C_Types.h"

i2c_operations_t i2c_returnStop(void *p)
{
    return i2c_stop;
}

i2c_operations_t i2c_returnReset(void *p)
{
    return i2c_reset_link;
}

i2c_operations_t i2c_restartWrite(void *p)
{
    return i2c_restart_write;
}

i2c_operations_t i2c_restartRead(void *p)
{
    return i2c_restart_read;
}