
#include <xc.h>
#include <stdbool.h>
#include <stdlib.h>
#include "I2C_Master.h"
#include "I2C_Types.h"
#include "I2C1_Driver.h"

static void setCallBack(i2c_callbackIndex idx, i2c_callback cb, void *p);
static i2c_operations_t returnStop(void *p);
static i2c_operations_t returnReset(void *p);

inline void i2c_poller(void);


void i2c_setDataCompleteCallback(i2c_callback cb, void *p)
{
    setCallBack(i2c_dataComplete,cb,p);
}

void i2c_setWriteCollisionCallback(i2c_callback cb, void *p)
{
    setCallBack(i2c_writeCollision,cb,p);
}

void i2c_setAddressNACKCallback(i2c_callback cb, void *p)
{
    setCallBack(i2c_addressNACK,cb,p);
}

void i2c_setDataNACKCallback(i2c_callback cb, void *p)
{
    setCallBack(i2c_dataNACK,cb,p);
}

void i2c_setTimeOutCallback(i2c_callback cb, void *p)
{
    setCallBack(i2c_timeOut,cb,p);    
}

// when you call open, you supply a device address.
// if you get the bus, the function returns true
i2c_error_t i2c_open(i2c_address_t address)
{
    i2c_error_t ret = I2C_BUSY;
    
    if(!i2c_status.inUse)
    {
        i2c_status.address = address;
        i2c_status.busy = 0;
        i2c_status.inUse = 1;
        i2c_status.addressNACKCheck = 0;
        i2c_status.state = I2C_RESET;
        i2c_status.time_out_value = 500; // MCC should determine a reasonable starting value here.
        i2c_status.bufferFree = 1;

        // set all the call backs to a default of sending stop
        i2c_status.callbackTable[i2c_dataComplete]=returnStop;
        i2c_status.callbackPayload[i2c_dataComplete] = NULL;
        i2c_status.callbackTable[i2c_writeCollision]=returnStop;
        i2c_status.callbackPayload[i2c_writeCollision] = NULL;
        i2c_status.callbackTable[i2c_addressNACK]=returnStop;
        i2c_status.callbackPayload[i2c_addressNACK] = NULL;
        i2c_status.callbackTable[i2c_dataNACK]=returnStop;
        i2c_status.callbackPayload[i2c_dataNACK] = NULL;
        i2c_status.callbackTable[i2c_timeOut]=returnReset;
        i2c_status.callbackPayload[i2c_timeOut] = NULL;
        
        i2c1_driver_open();
        mssp1_clearIRQ();
        
        i2c1_driver_setBusCollisionISR(i2c_busCollisionISR);
        i2c1_driver_setI2cISR(i2c_ISR);
        
        // uncomment the IRQ enable for an interrupt driven driver.
//        mssp1_enableIRQ();

        ret = I2C_NOERR;
    }
    return ret;
}

void i2c_setAddress(i2c_address_t address)
{
    i2c_status.address = address;
}

// close the bus if it is not busy and it is my address
i2c_error_t i2c_close(void)
{
    i2c_error_t ret = I2C_BUSY;
    if(!i2c_status.busy)
    {
        i2c_status.inUse = 0;
        // close it down
        i2c_status.address = 0xff; // 8-bit address is invalid so this is FREE
        mssp1_clearIRQ();
        mssp1_disableIRQ();
        ret = i2c_status.error;
    }
    return ret;
}

void i2c_setTimeOut(uint8_t to)
{
    mssp1_disableIRQ();
    i2c_status.time_out_value = to;
    mssp1_enableIRQ();
}

void i2c_setBuffer(void *buffer, size_t bufferSize)
{
    if(i2c_status.bufferFree)
    {
        i2c_status.data_ptr = buffer;
        i2c_status.data_length = bufferSize;
        i2c_status.bufferFree = false;
    }
}
i2c_error_t i2c_masterOperation(bool read)
{
    i2c_error_t ret = I2C_BUSY;
    if(!i2c_status.busy)
    {
        i2c_status.busy = true;
        ret = I2C_NOERR;
        
        if(read)
        {
            i2c_status.state = I2C_SEND_ADR_READ;
        }
        else
        {
            i2c_status.state = I2C_SEND_ADR_WRITE;
        }
        i2c1_driver_start();
        
        if(! mssp1_IRQisEnabled())
            i2c_poller();
    }
    return ret;
}

i2c_error_t i2c_masterRead(void)
{
    return i2c_masterOperation(true);
}

i2c_error_t i2c_masterWrite(void)
{
    return i2c_masterOperation(false);
}

/************************************************************************/
/* Helper Functions                                                     */
/************************************************************************/
inline void i2c_poller(void)
{
    while(i2c_status.busy)
    {
        mssp1_waitForEvent(NULL);
        i2c_ISR();
    }
}

static i2c_fsm_states_t do_I2C_RESET(void)
{
    i2c1_driver_resetBus();
    i2c_status.busy = false; // Bus Free
    i2c_status.error = I2C_NOERR;
    return I2C_RESET; // park the FSM on reset
}

static i2c_fsm_states_t do_I2C_IDLE(void)
{
    i2c_status.busy = false; // Bus Free
    i2c_status.error = I2C_NOERR;
    return I2C_RESET; // park the FSM on reset
}

static i2c_fsm_states_t do_I2C_SEND_RESTART_READ(void)
{
    i2c1_driver_restart();
    return I2C_SEND_ADR_READ;
}

static i2c_fsm_states_t do_I2C_SEND_RESTART_WRITE(void)
{
    i2c1_driver_restart();
    return I2C_SEND_ADR_WRITE;
}

static i2c_fsm_states_t do_I2C_SEND_RESTART(void)
{
    i2c1_driver_restart();
    return I2C_SEND_ADR_READ;
}

static i2c_fsm_states_t do_I2C_SEND_STOP(void)
{
    i2c1_driver_stop();
    return I2C_IDLE;
}

static i2c_fsm_states_t do_I2C_SEND_ADR_READ(void)
{
    i2c_status.addressNACKCheck = 1;
    i2c1_driver_TXData(i2c_status.address << 1 | 1);
    return I2C_RCEN;
}

static i2c_fsm_states_t do_I2C_SEND_ADR_WRITE(void)
{
    i2c_status.addressNACKCheck = 1;
    i2c1_driver_TXData(i2c_status.address << 1);
    return I2C_TX;
}

static i2c_fsm_states_t do_I2C_RCEN(void)
{
    i2c_status.addressNACKCheck = 0;
    i2c1_driver_startRX();
    return I2C_RX;
}

static i2c_fsm_states_t do_I2C_DO_ACK(void)
{
    i2c1_driver_sendACK();
    return I2C_RCEN;
}

static i2c_fsm_states_t do_I2C_DO_NACK_STOP(void)
{
    i2c1_driver_sendNACK();
    return I2C_SEND_STOP;
}

static i2c_fsm_states_t do_I2C_DO_NACK_RESTART(void)
{
    i2c1_driver_sendNACK();
    return I2C_SEND_RESTART;
}

// TODO: probably need 2 addressNACK's one from read and one from write.
//       the do NACK before RESTART or STOP is a special case that a new state simplifies.
static i2c_fsm_states_t do_I2C_DO_ADDRESS_NACK(void)
{
    i2c_status.addressNACKCheck = 0;
    i2c_status.error = I2C_FAIL;
    switch(i2c_status.callbackTable[i2c_addressNACK](i2c_status.callbackPayload[i2c_addressNACK]))
    {
        case i2c_restart_read:
        case i2c_restart_write:
            return do_I2C_SEND_RESTART();
        default:
            return do_I2C_SEND_STOP();
    }
}

static i2c_fsm_states_t do_I2C_TX(void)
{
    if(i2c1_driver_isNACK())
    {
        switch(i2c_status.callbackTable[i2c_dataNACK](i2c_status.callbackPayload[i2c_dataNACK]))
        {
            case i2c_restart_read:
                return do_I2C_SEND_RESTART_READ();
            case i2c_restart_write:
                return do_I2C_SEND_RESTART_WRITE();
            default:
            case i2c_continue:
            case i2c_stop:
                return do_I2C_SEND_STOP();
        }
    }
    else
    {
        i2c_status.addressNACKCheck = 0;
        i2c1_driver_TXData(*i2c_status.data_ptr++);
        return (--i2c_status.data_length)?I2C_TX:I2C_TX_EMPTY;
    }
}

static i2c_fsm_states_t do_I2C_RX(void)
{
    *i2c_status.data_ptr++ = i2c1_driver_getRXData();
    if(--i2c_status.data_length)
    {
        i2c1_driver_sendACK();
        return I2C_RCEN;
    }
    else
    {
        i2c_status.bufferFree = true;
        switch(i2c_status.callbackTable[i2c_dataComplete](i2c_status.callbackPayload[i2c_dataComplete]))
        {
            case i2c_restart_write:
            case i2c_restart_read:
                return do_I2C_DO_NACK_RESTART();
            default:
            case i2c_continue:
            case i2c_stop:
                return do_I2C_DO_NACK_STOP();
        }

    }
}

static i2c_fsm_states_t do_I2C_TX_EMPTY(void)
{
    i2c_status.bufferFree = true;
    switch(i2c_status.callbackTable[i2c_dataComplete](i2c_status.callbackPayload[i2c_dataComplete]))
    {
        case i2c_restart_read:
        case i2c_restart_write:
            return do_I2C_SEND_RESTART();
        case i2c_continue:
            mssp1_setIRQ();
            return I2C_TX;
        default:
        case i2c_stop:
            return do_I2C_SEND_STOP();
    }
}

typedef i2c_fsm_states_t (*stateHandlerFunction)(void);
const stateHandlerFunction fsmStateTable[] = {
    do_I2C_IDLE,                //I2C_IDLE
    do_I2C_SEND_ADR_READ,       //I2C_SEND_ADR_READ
    do_I2C_SEND_ADR_WRITE,      //I2C_SEND_ADR_WRITE
    do_I2C_TX,                  //I2C_TX
    do_I2C_RX,                  //I2C_RX
    do_I2C_RCEN,                //I2C_RCEN
    do_I2C_TX_EMPTY,            //I2C_TX_EMPTY
    do_I2C_SEND_RESTART_READ,   //I2C_SEND_RESTART_READ
    do_I2C_SEND_RESTART_WRITE,  //I2C_SEND_RESTART_WRITE
    do_I2C_SEND_RESTART,        //I2C_SEND_RESTART
    do_I2C_SEND_STOP,           //I2C_SEND_STOP
    do_I2C_DO_ACK,              //I2C_RX_DO_ACK
    do_I2C_DO_NACK_STOP,        //I2C_RX_DO_NACK_STOP
    do_I2C_DO_NACK_RESTART,     //I2C_RX_DO_NACK_RESTART
    do_I2C_RESET,               //I2C_RESET
    do_I2C_DO_ADDRESS_NACK      //I2C_ADDRESS_NACK
};

void i2c_ISR(void)
{       
    mssp1_clearIRQ();
    
    // NOTE: We are ignoring the Write Collision flag.
    // the write collision is when SSPBUF is written prematurely (2x in a row without sending)

    // NACK After address override Exception handler
    if(i2c_status.addressNACKCheck && i2c1_driver_isNACK())
    {
        i2c_status.state = I2C_ADDRESS_NACK; // State Override
    }

    i2c_status.state = fsmStateTable[i2c_status.state]();
}

void i2c_busCollisionISR(void)
{
    i2c1_driver_clearBusCollision();
}

/************************************************************************/
/* Helper Functions                                                     */
/************************************************************************/
static i2c_operations_t returnStop(void *p)
{
    return i2c_stop;
}

static i2c_operations_t returnReset(void *p)
{
    return i2c_reset_link;
}

static void setCallBack(i2c_callbackIndex idx, i2c_callback cb, void *p)
{
    if(cb)
    {
        i2c_status.callbackTable[idx] = cb;
        i2c_status.callbackPayload[idx] = p;
    }
    else
    {
        i2c_status.callbackTable[idx] = returnStop;
        i2c_status.callbackPayload[idx] = NULL;
    }
}