#include "I2C_Simple_Master.h"
#include "I2C_Master.h"

/****************************************************************/
static i2c_operations_t wr1RegCompleteHandler(void *p)
{
    i2c_setBuffer(p,1);
    i2c_setDataCompleteCallback(NULL,NULL);
    return i2c_continue;
}

void i2c_write1ByteRegister(i2c_address_t address, uint8_t reg, uint8_t data)
{
    while(!i2c_open(address)); // sit here until we get the bus..
    i2c_setDataCompleteCallback(wr1RegCompleteHandler,&data);
    i2c_setBuffer(&reg,1);
    i2c_setAddressNACKCallback(i2c_restartWrite,NULL); //NACK polling?
    i2c_masterWrite();
    while(I2C_BUSY == i2c_close()); // sit here until finished.
}

void i2c_writeNBytes(i2c_address_t address, void* data, size_t len)
{
    while(!i2c_open(address)); // sit here until we get the bus..
    i2c_setBuffer(data,len);
    i2c_setAddressNACKCallback(i2c_restartWrite,NULL); //NACK polling?
    i2c_masterWrite();
    while(I2C_BUSY == i2c_close()); // sit here until finished.
}

/****************************************************************/
static i2c_operations_t rd1RegCompleteHandler(void *p)
{
    i2c_setBuffer(p,1);
    i2c_setDataCompleteCallback(NULL,NULL);
    return i2c_restart_read;
}

uint8_t i2c_read1ByteRegister(i2c_address_t address, uint8_t reg)
{
    uint8_t    d2=42;
    i2c_error_t e;
    int x;

    for(x = 2; x != 0; x--)
    {
        while(!i2c_open(address)); // sit here until we get the bus..
        i2c_setDataCompleteCallback(rd1RegCompleteHandler,&d2);
        i2c_setBuffer(&reg,1);
        i2c_setAddressNACKCallback(i2c_restartWrite,NULL); //NACK polling?
        i2c_masterWrite();
        while(I2C_BUSY == (e = i2c_close())); // sit here until finished.
        if(e==I2C_NOERR) break;
    }
    

    return d2;
}

/****************************************************************/
static i2c_operations_t rd2RegCompleteHandler(void *p)
{
    i2c_setBuffer(p,2);
    i2c_setDataCompleteCallback(NULL,NULL);
    return i2c_restart_read;
}

uint16_t i2c_read2ByteRegister(i2c_address_t address, uint8_t reg)
{
    // result is little endian
    uint16_t    result;

    while(!i2c_open(address)); // sit here until we get the bus..
    i2c_setDataCompleteCallback(rd2RegCompleteHandler,&result);
    i2c_setBuffer(&reg,1);
    i2c_setAddressNACKCallback(i2c_restartWrite,NULL); //NACK polling?
    i2c_masterWrite();
    while(I2C_BUSY == i2c_close()); // sit here until finished.
    
    return (result << 8 | result >> 8);
}

/****************************************************************/
static i2c_operations_t wr2RegCompleteHandler(void *p)
{
    i2c_setBuffer(p,2);
    i2c_setDataCompleteCallback(NULL,NULL);
    return i2c_continue;
}

void i2c_write2ByteRegister(i2c_address_t address, uint8_t reg, uint16_t data)
{
    while(!i2c_open(address)); // sit here until we get the bus..
    i2c_setDataCompleteCallback(wr2RegCompleteHandler,&data);
    i2c_setBuffer(&reg,1);
    i2c_setAddressNACKCallback(i2c_restartWrite,NULL); //NACK polling?
    i2c_masterWrite();
    while(I2C_BUSY == i2c_close()); // sit here until finished.
}

/****************************************************************/
typedef struct
{
    size_t len;
    char *data;
}buf_t;

static i2c_operations_t rdBlkRegCompleteHandler(void *p)
{
    i2c_setBuffer(((buf_t *)p)->data,((buf_t*)p)->len);
    i2c_setDataCompleteCallback(NULL,NULL);
    return i2c_restart_read;
}

void i2c_readDataBlock(i2c_address_t address, uint8_t reg, void *data, size_t len)
{
    // result is little endian
    buf_t    d;
    d.data = data;
    d.len = len;

    while(!i2c_open(address)); // sit here until we get the bus..
    i2c_setDataCompleteCallback(rdBlkRegCompleteHandler,&d);
    i2c_setBuffer(&reg,1);
    i2c_setAddressNACKCallback(i2c_restartWrite,NULL); //NACK polling?
    i2c_masterWrite();
    while(I2C_BUSY == i2c_close()); // sit here until finished.
}

void i2c_readNBytes(i2c_address_t address, void *data, size_t len)
{
    while(!i2c_open(address)); // sit here until we get the bus..
    i2c_setBuffer(data,len);
    i2c_masterRead();
    while(I2C_BUSY == i2c_close()); // sit here until finished.
}