/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: amanda.h
 *
 * Code generated for Simulink model 'amanda'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * C/C++ source code generated on : Mon Feb 08 09:16:51 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_amanda_h_
#define RTW_HEADER_amanda_h_
#include <stddef.h>
#ifndef amanda_COMMON_INCLUDES_
# define amanda_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "asus_capture.h"
#include "NI.h"
#include "wrapper.h"
#endif                                 /* amanda_COMMON_INCLUDES_ */

#include "amanda_types.h"

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
} B_amanda_T;

/* Real-time Model Data Structure */
struct tag_RTM_amanda_T {
  const char_T * volatile errorStatus;
};

/* Block signals (auto storage) */
extern B_amanda_T amanda_B;

/* Model entry point functions */
extern void amanda_initialize(void);
extern void amanda_step(void);
extern void amanda_terminate(void);

/* Real-time Model object */
extern RT_MODEL_amanda_T *const amanda_M;

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
 * '<Root>' : 'amanda'
 */
#endif                                 /* RTW_HEADER_amanda_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
