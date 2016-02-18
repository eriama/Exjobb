/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: blinking_led.h
 *
 * Code generated for Simulink model 'blinking_led'.
 *
 * Model version                  : 1.5
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Wed Feb 10 15:30:02 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_blinking_led_h_
#define RTW_HEADER_blinking_led_h_
#include <stddef.h>
#include <string.h>
#ifndef blinking_led_COMMON_INCLUDES_
# define blinking_led_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* blinking_led_COMMON_INCLUDES_ */

#include "blinking_led_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  int32_T clockTickCounter;            /* '<Root>/Pulse Generator' */
} DW_blinking_led_T;

/* Parameters (auto storage) */
struct P_blinking_led_T_ {
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S1>/PWM'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 250
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_blinking_led_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_blinking_led_T blinking_led_P;

/* Block states (auto storage) */
extern DW_blinking_led_T blinking_led_DW;

/* Model entry point functions */
extern void blinking_led_initialize(void);
extern void blinking_led_output(void);
extern void blinking_led_update(void);
extern void blinking_led_terminate(void);

/* Real-time Model object */
extern RT_MODEL_blinking_led_T *const blinking_led_M;

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
 * '<Root>' : 'blinking_led'
 * '<S1>'   : 'blinking_led/PWM'
 */
#endif                                 /* RTW_HEADER_blinking_led_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
