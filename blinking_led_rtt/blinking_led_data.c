/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: blinking_led_data.c
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

#include "blinking_led.h"
#include "blinking_led_private.h"

/* Block parameters (auto storage) */
P_blinking_led_T blinking_led_P = {
  5U,                                  /* Mask Parameter: PWM_pinNumber
                                        * Referenced by: '<S1>/PWM'
                                        */
  250.0,                               /* Expression: 250
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  20.0,                                /* Computed Parameter: PulseGenerator_Period
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  1.0,                                 /* Computed Parameter: PulseGenerator_Duty
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
  0.0                                  /* Expression: 0
                                        * Referenced by: '<Root>/Pulse Generator'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
