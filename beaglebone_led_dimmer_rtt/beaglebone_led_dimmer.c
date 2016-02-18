/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: beaglebone_led_dimmer.c
 *
 * Code generated for Simulink model 'beaglebone_led_dimmer'.
 *
 * Model version                  : 1.10
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Fri Feb 12 10:26:11 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "beaglebone_led_dimmer.h"
#include "beaglebone_led_dimmer_private.h"

/* Real-time model */
RT_MODEL_beaglebone_led_dimme_T beaglebone_led_dimmer_M_;
RT_MODEL_beaglebone_led_dimme_T *const beaglebone_led_dimmer_M =
  &beaglebone_led_dimmer_M_;

/* Model output function */
void beaglebone_led_dimmer_output(void)
{
  uint32_T tmp;

  /* S-Function (armcortexa_analogInput_sfcn): '<Root>/Analog Input' */
  tmp = beaglebone_led_dimmer_P.AnalogInput_p1;
  MW_analogInputRead(&tmp);
}

/* Model update function */
void beaglebone_led_dimmer_update(void)
{
  /* (no update code required) */
}

/* Model initialize function */
void beaglebone_led_dimmer_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(beaglebone_led_dimmer_M, (NULL));

  /* Start for S-Function (armcortexa_analogInput_sfcn): '<Root>/Analog Input' */
  MW_analogInputInit();
}

/* Model terminate function */
void beaglebone_led_dimmer_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
