/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: beaglebone_led_dimmer.h
 *
 * Code generated for Simulink model 'beaglebone_led_dimmer'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Fri Feb 12 10:26:11 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_beaglebone_led_dimmer_h_
#define RTW_HEADER_beaglebone_led_dimmer_h_
#include <stddef.h>
#ifndef beaglebone_led_dimmer_COMMON_INCLUDES_
# define beaglebone_led_dimmer_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_analogInput_lct.h"
#endif                                 /* beaglebone_led_dimmer_COMMON_INCLUDES_ */

#include "beaglebone_led_dimmer_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Parameters (auto storage) */
struct P_beaglebone_led_dimmer_T_ {
  uint32_T AnalogInput_p1;             /* Computed Parameter: AnalogInput_p1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_beaglebone_led_dimmer_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_beaglebone_led_dimmer_T beaglebone_led_dimmer_P;

/* Model entry point functions */
extern void beaglebone_led_dimmer_initialize(void);
extern void beaglebone_led_dimmer_output(void);
extern void beaglebone_led_dimmer_update(void);
extern void beaglebone_led_dimmer_terminate(void);

/* Real-time Model object */
extern RT_MODEL_beaglebone_led_dimme_T *const beaglebone_led_dimmer_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'beaglebone_led_dimmer'
 */
#endif                                 /* RTW_HEADER_beaglebone_led_dimmer_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
