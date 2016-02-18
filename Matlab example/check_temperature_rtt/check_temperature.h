/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: check_temperature.h
 *
 * Code generated for Simulink model 'check_temperature'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Thu Feb 04 13:25:14 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_check_temperature_h_
#define RTW_HEADER_check_temperature_h_
#include <stddef.h>
#ifndef check_temperature_COMMON_INCLUDES_
# define check_temperature_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "arduino_analoginput_lct.h"
#include "arduino_analogoutput_lct.h"
#endif                                 /* check_temperature_COMMON_INCLUDES_ */

#include "check_temperature_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Parameters (auto storage) */
struct P_check_temperature_T_ {
  uint32_T PWM_pinNumber;              /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S2>/PWM'
                                        */
  uint32_T AnalogInput_p1;             /* Computed Parameter: AnalogInput_p1
                                        * Referenced by: '<Root>/Analog Input'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_check_temperature_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_check_temperature_T check_temperature_P;

/* Model entry point functions */
extern void check_temperature_initialize(void);
extern void check_temperature_output(void);
extern void check_temperature_update(void);
extern void check_temperature_terminate(void);

/* Real-time Model object */
extern RT_MODEL_check_temperature_T *const check_temperature_M;

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
 * '<Root>' : 'check_temperature'
 * '<S1>'   : 'check_temperature/MATLAB Function'
 * '<S2>'   : 'check_temperature/PWM'
 */
#endif                                 /* RTW_HEADER_check_temperature_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
