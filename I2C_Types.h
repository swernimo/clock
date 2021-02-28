#ifndef I2C_Types_H
#define	I2C_Types_H

#include <xc.h> // include processor files - each processor file is guarded.
#include <stdint.h>
#include <stdio.h>

typedef uint8_t i2c_address_t;

// I2C STATES
typedef enum {
    I2C_IDLE = 0,
    I2C_SEND_ADR_READ,
    I2C_SEND_ADR_WRITE,
    I2C_TX,
    I2C_RX,
    I2C_RCEN,
    I2C_TX_EMPTY,
    I2C_SEND_RESTART_READ,
    I2C_SEND_RESTART_WRITE,
    I2C_SEND_RESTART,
    I2C_SEND_STOP,
    I2C_RX_DO_ACK,
    I2C_RX_DO_NACK_STOP,
    I2C_RX_DO_NACK_RESTART,
    I2C_RESET,
    I2C_ADDRESS_NACK
} i2c_fsm_states_t;

// I2C Event Callback List
typedef enum
{
    i2c_dataComplete = 0,
    i2c_writeCollision,
    i2c_addressNACK,
    i2c_dataNACK,
    i2c_timeOut,
    i2c_NULL
} i2c_callbackIndex;

typedef enum {
    I2C_NOERR, // The message was sent.
    I2C_BUSY,  // Message was NOT sent, bus was busy.
    I2C_FAIL   // Message was NOT sent, bus failure
               // If you are interested in the failure reason,
               // Sit on the event call-backs.
} i2c_error_t;

typedef enum
{
    i2c_stop=1,
    i2c_restart_read,
    i2c_restart_write,
    i2c_continue,
    i2c_reset_link
} i2c_operations_t;

typedef i2c_operations_t (*i2c_callback)(void *p);

// I2C Status Structure
typedef struct
{
    unsigned busy:1;
    unsigned inUse:1;
    unsigned bufferFree:1;
    unsigned addressNACKCheck:1;
    i2c_address_t address;       /// The I2C Address
    uint8_t *data_ptr;           /// pointer to a data buffer
    size_t data_length;          /// Bytes in the data buffer
    uint16_t time_out;           /// I2C Timeout Counter between I2C Events.
    uint16_t time_out_value;     /// Reload value for the timeouts
    i2c_fsm_states_t state;      /// Driver State
    i2c_error_t error;
    i2c_callback callbackTable[6];
    void *callbackPayload[6];    ///  each callback can have a payload
} i2c_status_t;

i2c_status_t i2c_status = {0};

i2c_operations_t i2c_returnStop(void *p);
i2c_operations_t i2c_returnReset(void *p);
i2c_operations_t i2c_restartWrite(void *p);
i2c_operations_t i2c_restartRead(void *p);

#endif	/* XC_HEADER_TEMPLATE_H */

