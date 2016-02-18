/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: amanda_blinkingblink_data.c
 *
 * Code generated for Simulink model 'amanda_blinkingblink'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Tue Feb 16 09:00:45 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "amanda_blinkingblink.h"
#include "amanda_blinkingblink_private.h"

/* Block parameters (auto storage) */
P_amanda_blinkingblink_T amanda_blinkingblink_P = {
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<Root>/Switch'
                                        */
  0U,                                  /* Computed Parameter: AnalogInput_p1
                                        * Referenced by: '<Root>/Analog Input'
                                        */

  /*  Expression: deviceFile
   * Referenced by: '<Root>/LED'
   */
  { 98U, 101U, 97U, 103U, 108U, 101U, 98U, 111U, 110U, 101U, 58U, 103U, 114U,
    101U, 101U, 110U, 58U, 117U, 115U, 114U, 49U, 0U },
  0,                                   /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<Root>/Constant1'
                                        */
  1                                    /* Computed Parameter: Constant_Value
                                        * Referenced by: '<Root>/Constant'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
