/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: test_asus.c
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

#include "test_asus.h"
#include "test_asus_private.h"

/* Block signals (auto storage) */
B_test_asus_T test_asus_B;

/* Real-time model */
RT_MODEL_test_asus_T test_asus_M_;
RT_MODEL_test_asus_T *const test_asus_M = &test_asus_M_;

/* Model step function */
void test_asus_step(void)
{
  /* S-Function (asus_capture_sfcn): '<Root>/asus_capture_sfcn' */
  asusCapture( &test_asus_B.asus_capture_sfcn[0]);

  /* MATLAB Function 'get local coordinates': '<S2>:1' */
  /* '<S2>:1:3' */
  /* '<S2>:1:4' */
  /* 12288 */
  /* '<S2>:1:5' */
  /* '<S2>:1:6' */
  /* '<S2>:1:7' */
  /* is in mm */
  /* '<S2>:1:10' */
  /* '<S2>:1:29' */
  /* MATLAB Function 'MATLAB Function': '<S1>:1' */
  /*  Transformed cloud */
  /* '<S1>:1:18' */
  /* '<S1>:1:19' */
}

/* Model initialize function */
void test_asus_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(test_asus_M, (NULL));

  /* S-Function (asus_capture_sfcn): <Root>/asus_capture_sfcn */
  asusInit();
}

/* Model terminate function */
void test_asus_terminate(void)
{
  /* S-Function (asus_capture_sfcn): <Root>/asus_capture_sfcn */
  asusTerminate();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
