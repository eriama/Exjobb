/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test_asus.h
 *
 * Code generated for Simulink model 'test_asus'.
 *
 * Model version                  : 1.19
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * C/C++ source code generated on : Fri Feb 12 15:45:57 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_test_asus_h_
#define RTW_HEADER_test_asus_h_
#include <stddef.h>
#ifndef test_asus_COMMON_INCLUDES_
# define test_asus_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "asus_capture.h"
#include "NI.h"
#include "wrapper.h"
#endif                                 /* test_asus_COMMON_INCLUDES_ */

#include "test_asus_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (auto storage) */
typedef struct {
  uint16_T asus_capture_sfcn[76800];   /* '<Root>/asus_capture_sfcn' */
} B_test_asus_T;

/* Parameters (auto storage) */
struct P_test_asus_T_ {
  real_T cx;                           /* Variable: cx
                                        * Referenced by: '<Root>/Center pixel x coordinate'
                                        */
  real_T cy;                           /* Variable: cy
                                        * Referenced by: '<Root>/Center pixel y coordinate'
                                        */
  real_T focal;                        /* Variable: focal
                                        * Referenced by: '<Root>/Camera focal length'
                                        */
  real_T interval;                     /* Variable: interval
                                        * Referenced by: '<Root>/Image pixel interval'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_test_asus_T {
  const char_T * volatile errorStatus;
};

/* Block parameters (auto storage) */
extern P_test_asus_T test_asus_P;

/* Block signals (auto storage) */
extern B_test_asus_T test_asus_B;

/* Model entry point functions */
extern void test_asus_initialize(void);
extern void test_asus_step(void);
extern void test_asus_terminate(void);

/* Real-time Model object */
extern RT_MODEL_test_asus_T *const test_asus_M;

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
 * '<Root>' : 'test_asus'
 * '<S1>'   : 'test_asus/MATLAB Function'
 * '<S2>'   : 'test_asus/get local coordinates'
 */
#endif                                 /* RTW_HEADER_test_asus_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
