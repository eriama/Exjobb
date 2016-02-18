/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: amanda.c
 *
 * Code generated for Simulink model 'amanda'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Mon Feb 08 09:30:50 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "amanda.h"
#include "amanda_private.h"

/* Block signals (auto storage) */
B_amanda_T amanda_B;

/* Real-time model */
RT_MODEL_amanda_T amanda_M_;
RT_MODEL_amanda_T *const amanda_M = &amanda_M_;

/* Model output function */
void amanda_output(void)
{
  /* S-Function (asus_capture_sfcn): '<Root>/asus_capture_sfcn' */
  asusCapture( &amanda_B.asus_capture_sfcn[0]);
}

/* Model update function */
void amanda_update(void)
{
  /* (no update code required) */
}

/* Model initialize function */
void amanda_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(amanda_M, (NULL));

  /* S-Function (asus_capture_sfcn): <Root>/asus_capture_sfcn */
  asusInit();
}

/* Model terminate function */
void amanda_terminate(void)
{
  /* S-Function (asus_capture_sfcn): <Root>/asus_capture_sfcn */
  asusTerminate();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
