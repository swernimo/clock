#ifndef TMR_3s_H
#define TMR_3s_H

#include <stdint.h>
#include <stdbool.h>

typedef enum
{

	/* Roll-over Pulse mode clears the TMRx upon TMRx = PRx, then continue running.
	ON bit must be set and is not affected by Resets
	*/

   /* Roll-over Pulse mode indicates that Timer starts
   immediately upon ON = 1 (Software Control)
   */
   TMR2_ROP_STARTS_TMRON,

   /* Roll-over Pulse mode indicates that the Timer starts
       when ON = 1 and TMRx_ers = 1. Stops when TMRx_ers = 0
     */
   TMR2_ROP_STARTS_TMRON_ERSHIGH,

   /* Roll-over Pulse mode indicates that the Timer starts
      when ON = 1 and TMRx_ers = 0. Stops when TMRx_ers = 1
     */
   TMR2_ROP_STARTS_TMRON_ERSLOW,

   /* Roll-over Pulse mode indicates that the Timer resets
   upon rising or falling edge of TMRx_ers
     */
   TMR2_ROP_RESETS_ERSBOTHEDGE,

   /* Roll-over Pulse mode indicates that the Timer resets
    upon rising edge of TMRx_ers
     */
   TMR2_ROP_RESETS_ERSRISINGEDGE,

   /* Roll-over Pulse mode indicates that the Timer resets
   upon falling edge of TMRx_ers
     */
   TMR2_ROP_RESETS_ERSFALLINGEDGE,

   /* Roll-over Pulse mode indicates that the Timer resets
   upon TMRx_ers = 0
     */
   TMR2_ROP_RESETS_ERSLOW,

   /* Roll-over Pulse mode indicates that the Timer resets
   upon TMRx_ers = 1
     */
   TMR2_ROP_RESETS_ERSHIGH,

    /*In all One-Shot mode the timer resets and the ON bit is
	cleared when the timer value matches the PRx period
	value. The ON bit must be set by software to start
	another timer cycle.
	*/

   /* One shot mode indicates that the Timer starts
    immediately upon ON = 1 (Software Control)
     */
   TMR2_OS_STARTS_TMRON,

   /* One shot mode indicates that the Timer starts
    when a rising edge is detected on the TMRx_ers
     */
   TMR2_OS_STARTS_ERSRISINGEDGE ,

   /* One shot mode indicates that the Timer starts
    when a falling edge is detected on the TMRx_ers
     */
   TMR2_OS_STARTS_ERSFALLINGEDGE ,

   /* One shot mode indicates that the Timer starts
    when either a rising or falling edge is detected on TMRx_ers
     */
   TMR2_OS_STARTS_ERSBOTHEDGE,

   /* One shot mode indicates that the Timer starts
    upon first TMRx_ers rising edge and resets on all
	subsequent TMRx_ers rising edges
     */
   TMR2_OS_STARTS_ERSFIRSTRISINGEDGE,

   /* One shot mode indicates that the Timer starts
    upon first TMRx_ers falling edge and restarts on all
	subsequent TMRx_ers falling edges
     */
   TMR2_OS_STARTS_ERSFIRSTFALLINGEDGE,

   /* One shot mode indicates that the Timer starts
    when a rising edge is detected on the TMRx_ers,
	resets upon TMRx_ers = 0
     */
   TMR2_OS_STARTS_ERSRISINGEDGEDETECT,
     /* One shot mode indicates that the Timer starts
    when a falling edge is detected on the TMRx_ers,
	resets upon TMRx_ers = 1
     */
   TMR2_OS_STARTS_ERSFALLINGEDGEDETECT,
   
   /* One shot mode indicates that the Timer starts
    when a TMRx_ers = 1,ON =1 and resets upon TMRx_ers =0
    */
   TMR2_OS_STARTS_TMRON_ERSHIGH = 0x16,
           
   /* One shot mode indicates that the Timer starts
     when a TMRx_ers = 0,ON = 1 and resets upon TMRx_ers =1 
    */
   TMR2_OS_STARTS_TMRON_ERSLOW = 0x17,
        
   /*In all Mono-Stable mode the ON bit must be initially set,but
     not cleared upon the TMRx = PRx, and the timer will start upon
     an TMRx_ers start event following TMRx = PRx.*/
               
   /* Mono Stable mode indicates that the Timer starts
      when a rising edge is detected on the TMRx_ers and ON = 1
    */
   TMR2_MS_STARTS_TMRON_ERSRISINGEDGEDETECT = 0x11,
           
   /* Mono Stable mode indicates that the Timer starts
      when a falling edge is detected on the TMRx_ers and ON = 1
    */
   TMR2_MS_STARTS_TMRON_ERSFALLINGEDGEDETECT = 0x12,
           
   /* Mono Stable mode indicates that the Timer starts
      when  either a rising or falling edge is detected on TMRx_ers 
      and ON = 1
    */
   TMR2_MS_STARTS_TMRON_ERSBOTHEDGE = 0x13
           
} TMR2_HLT_MODE;

/**
  HLT Reset Source Enumeration

  @Summary
    Defines the different reset source of the HLT.

  @Description
    This source can control starting and stopping of the
	timer, as well as resetting the timer, depending on
	which mode the timer is in. The mode of the timer is
	controlled by the HLT_MODE
*/

typedef enum
{
    /* T2INPPS is the Timer external reset source
    */
    TMR2_T2INPPS,

    /* Reserved enum cannot be used 
     */
    TMR2_RESERVED,
    
    /* Timer4 Postscale is the Timer external reset source 
     */
    TMR2_T4POSTSCALED,
    
    /* Timer6 Postscale is the Timer external reset source 
     */
    TMR2_T6POSTSCALED,

    /* Timer6 Postscale is the Timer external reset source 
     */
    TMR2_T8POSTSCALED,
     /* CCP1_OUT is the Timer external reset source 
     */
    TMR2_CCP1_OUT,

    /* CCP2_OUT is the Timer external reset source 
     */
    TMR2_CCP2_OUT,
    
    /* CCP3_OUT is the Timer external reset source 
     */
    TMR2_CCP3_OUT,

    /* CCP4_OUT is the Timer external reset source 
     */
    TMR2_CCP4_OUT,

    /* CCP5_OUT is the Timer external reset source 
     */
    TMR2_CCP5_OUT,

    /* PWM6_out is the Timer external reset source 
     */
    TMR2_PWM6_OUT,

     /* PWM7_out is the Timer external reset source 
     */
    TMR2_PWM7_OUT,

    /* C1_OUT_SYNC is the Timer external reset source 
     */
    TMR2_C1_OUT_SYNC,	

    /* C2_OUT_SYNC is the Timer external reset source 
     */
    TMR2_C2_OUT_SYNC,

    /* C3_OUT_SYNC is the Timer external reset source 
     */
    TMR2_C3_OUT_SYNC,

    /* ZCD_Output is the Timer external reset source 
     */
    TMR2_ZCD_OUTPUT


} TMR2_HLT_EXT_RESET_SOURCE;


void TMR_3s_Initialize(void);

//void TMR_3s_ModeSet(TMR2_HLT_MODE mode);
//
//void TMR_3s_ExtResetSourceSet(TMR2_HLT_EXT_RESET_SOURCE reset);

//void TMR_3s_Start(void);

void TMR_3s_StartTimer(void);

//void TMR_3s_Stop(void);

void TMR_3s_StopTimer(void);

//uint8_t TMR_3s_Counter8BitGet(void);
//
//uint8_t TMR_3s_ReadTimer(void);
//
//void TMR_3s_Counter8BitSet(uint8_t timerVal);
//
//void TMR_3s_WriteTimer(uint8_t timerVal);
//
//void TMR_3s_Period8BitSet(uint8_t periodVal);
//
//void TMR_3s_LoadPeriodRegister(uint8_t periodVal);

bool TMR_3s_HasOverflowOccured(void);

#endif