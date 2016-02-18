/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: untitled.c
 *
 * Code generated for Simulink model 'untitled'.
 *
 * Model version                  : 1.0
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Mon Feb 08 09:14:19 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "untitled.h"
#include "untitled_private.h"

/* Block signals (auto storage) */
B_untitled_T untitled_B;

/* Real-time model */
RT_MODEL_untitled_T untitled_M_;
RT_MODEL_untitled_T *const untitled_M = &untitled_M_;

/* Model output function */
void untitled_output(void)
{
  /* S-Function (asus_capture_sfcn): '<Root>/asus_capture_sfcn' */
  asusCapture( &untitled_B.asus_capture_sfcn[0]);
}

/* Model update function */
void untitled_update(void)
{
  /* (no update code required) */
}

/* Model initialize function */
void untitled_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(untitled_M, (NULL));

  /* S-Function (asus_capture_sfcn): <Root>/asus_capture_sfcn */
  asusInit();
}

/* Model terminate function */
void untitled_terminate(void)
{
  /* S-Function (asus_capture_sfcn): <Root>/asus_capture_sfcn */
  asusTerminate();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
