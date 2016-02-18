/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test_asus.c
 *
 * Code generated for Simulink model 'test_asus'.
 *
 * Model version                  : 1.4
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Mon Feb 08 10:03:03 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test_asus.h"
#include "test_asus_private.h"

/* user code (top of source file) */
C:

\Users\Amanda\Documents\Documents\LTH\Exjobb\Camera_8Februari\camera_rgbd\src\
  wrapper.c
  /* Block signals (auto storage) */
  B_test_asus_T test_asus_B;

/* Real-time model */
RT_MODEL_test_asus_T test_asus_M_;
RT_MODEL_test_asus_T *const test_asus_M = &test_asus_M_;

/* Model output function */
void test_asus_output(void)
{
  /* S-Function (asus_capture_sfcn): '<Root>/asus_capture_sfcn1' */
  asusCapture( &test_asus_B.asus_capture_sfcn1[0]);
}

/* Model update function */
void test_asus_update(void)
{
  /* (no update code required) */
}

/* Model initialize function */
void test_asus_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(test_asus_M, (NULL));

  /* S-Function (asus_capture_sfcn): <Root>/asus_capture_sfcn1 */
  asusInit();
}

/* Model terminate function */
void test_asus_terminate(void)
{
  /* S-Function (asus_capture_sfcn): <Root>/asus_capture_sfcn1 */
  asusTerminate();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
