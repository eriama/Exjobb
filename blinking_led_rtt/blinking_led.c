/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: blinking_led.c
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

/* Block states (auto storage) */
DW_blinking_led_T blinking_led_DW;

/* Real-time model */
RT_MODEL_blinking_led_T blinking_led_M_;
RT_MODEL_blinking_led_T *const blinking_led_M = &blinking_led_M_;

/* Model output function */
void blinking_led_output(void)
{
  real_T rtb_PulseGenerator;
  uint8_T rtb_PulseGenerator_0;

  /* DiscretePulseGenerator: '<Root>/Pulse Generator' */
  rtb_PulseGenerator = (blinking_led_DW.clockTickCounter <
                        blinking_led_P.PulseGenerator_Duty) &&
    (blinking_led_DW.clockTickCounter >= 0L) ? blinking_led_P.PulseGenerator_Amp
    : 0.0;
  if (blinking_led_DW.clockTickCounter >= blinking_led_P.PulseGenerator_Period -
      1.0) {
    blinking_led_DW.clockTickCounter = 0L;
  } else {
    blinking_led_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Pulse Generator' */

  /* DataTypeConversion: '<S1>/Data Type Conversion' */
  if (rtb_PulseGenerator < 256.0) {
    if (rtb_PulseGenerator >= 0.0) {
      rtb_PulseGenerator_0 = (uint8_T)rtb_PulseGenerator;
    } else {
      rtb_PulseGenerator_0 = 0U;
    }
  } else {
    rtb_PulseGenerator_0 = MAX_uint8_T;
  }

  /* End of DataTypeConversion: '<S1>/Data Type Conversion' */

  /* S-Function (arduinoanalogoutput_sfcn): '<S1>/PWM' */
  MW_analogWrite(blinking_led_P.PWM_pinNumber, rtb_PulseGenerator_0);
}

/* Model update function */
void blinking_led_update(void)
{
  /* (no update code required) */
}

/* Model initialize function */
void blinking_led_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(blinking_led_M, (NULL));

  /* states (dwork) */
  (void) memset((void *)&blinking_led_DW, 0,
                sizeof(DW_blinking_led_T));

  /* Start for DiscretePulseGenerator: '<Root>/Pulse Generator' */
  blinking_led_DW.clockTickCounter = 0L;

  /* Start for S-Function (arduinoanalogoutput_sfcn): '<S1>/PWM' */
  MW_pinModeOutput(blinking_led_P.PWM_pinNumber);
}

/* Model terminate function */
void blinking_led_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
