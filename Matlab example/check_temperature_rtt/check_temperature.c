/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: check_temperature.c
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

#include "check_temperature.h"
#include "check_temperature_private.h"

/* Real-time model */
RT_MODEL_check_temperature_T check_temperature_M_;
RT_MODEL_check_temperature_T *const check_temperature_M = &check_temperature_M_;

/* Model output function */
void check_temperature_output(void)
{
  uint16_T rtb_AnalogInput_0;
  int16_T temp;

  /* S-Function (arduinoanaloginput_sfcn): '<Root>/Analog Input' */
  rtb_AnalogInput_0 = MW_analogRead(check_temperature_P.AnalogInput_p1);

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  S-Function (arduinoanaloginput_sfcn): '<Root>/Analog Input'
   */
  /* MATLAB Function 'MATLAB Function': '<S1>:1' */
  if (rtb_AnalogInput_0 == 0U) {
    /* '<S1>:1:3' */
    /* '<S1>:1:4' */
    temp = 0;

    /*  elseif u < 50 */
    /*      temp = 50; */
    /*  elseif u < 100 */
    /*      temp = 100; */
    /*  elseif u < 200 */
    /*      temp = 150; */
    /*  elseif u < 300 */
    /*      temp = 200; */
  } else {
    /* '<S1>:1:14' */
    temp = 250;
  }

  /* S-Function (arduinoanalogoutput_sfcn): '<S2>/PWM' incorporates:
   *  MATLAB Function: '<Root>/MATLAB Function'
   */
  /* '<S1>:1:16' */
  MW_analogWrite(check_temperature_P.PWM_pinNumber, (uint8_T)temp);
}

/* Model update function */
void check_temperature_update(void)
{
  /* (no update code required) */
}

/* Model initialize function */
void check_temperature_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(check_temperature_M, (NULL));

  /* Start for S-Function (arduinoanaloginput_sfcn): '<Root>/Analog Input' */
  MW_pinModeAnalogInput(check_temperature_P.AnalogInput_p1);

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S2>/PWM' */
  MW_pinModeOutput(check_temperature_P.PWM_pinNumber);
}

/* Model terminate function */
void check_temperature_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
