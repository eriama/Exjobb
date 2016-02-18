/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ert_main.c
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
#include "Arduino.h"
#include "io_wrappers.h"
#define INIT_TIMER_VAL                 131
#define SETUP_PRESCALER                TCCR2B |= ((1<<CS22) | (1<<CS21)); TCCR2B &= ~(1<<CS20)
#define INTERRUPT_VECTOR               TIMER2_OVF_vect
#define DISABLE_TIMER                  TIMSK2 &= ~(1<<TOIE2)
#define ENABLE_TIMER                   TIMSK2 |= (1<<TOIE2)
#define TIMER_NORMAL_MODE              TCCR2A &= ~((1<<WGM21) | (1<<WGM20)); TCCR2B &= ~(1<<WGM22)
#define RESET_TIMER                    TCNT2 = INIT_TIMER_VAL

volatile uint8_T scheduler_counter = 0;

#define SCHEDULER_COUNTER_TARGET       5

volatile int IsrOverrun = 0;
boolean_T isRateRunning[1] = { 0 };

boolean_T need2runFlags[1] = { 0 };

/*
 * The timer interrupt handler (gets invoked on every counter overflow).
 */
ISR(INTERRUPT_VECTOR)
{
  RESET_TIMER;
  if ((++scheduler_counter) == SCHEDULER_COUNTER_TARGET) {
    scheduler_counter = 0;
    rt_OneStep();
  }
}

/*
 * Configures the base rate interrupt timer
 */
static void arduino_Timer_Setup()
{
  // Sets up the timer overflow interrupt.
  RESET_TIMER;

  // Initially disable the overflow interrupt (before configuration).
  DISABLE_TIMER;

  // Set the timer to normal mode.
  TIMER_NORMAL_MODE;

  // Set the prescaler.
  SETUP_PRESCALER;

  // Everything configured, so enable the overflow interrupt.
  ENABLE_TIMER;
}

void rt_OneStep(void)
{
  boolean_T eventFlags[1];

  /* Check base rate for overrun */
  if (isRateRunning[0]++) {
    IsrOverrun = 1;
    isRateRunning[0]--;                /* allow future iterations to succeed*/
    return;
  }

  sei();

  /*
   * For a bare-board target (i.e., no operating system), the
   * following code checks whether any subrate overruns,
   * and also sets the rates that need to run this time step.
   */
  check_temperature_output();

  /* Get model outputs here */
  check_temperature_update();
  cli();
  isRateRunning[0]--;
  if (eventFlags[0]) {
    if (need2runFlags[0]++) {
      IsrOverrun = 1;
      need2runFlags[0]--;              /* allow future iterations to succeed*/
      return;
    }
  }

  if (need2runFlags[0]) {
    if (isRateRunning[1]) {
      /* Yield to higher priority*/
      return;
    }

    isRateRunning[0]++;
    sei();
    switch (0) {
     default:
      break;
    }

    cli();
    need2runFlags[0]--;
    isRateRunning[0]--;
  }
}

int_T main(void)
{
  init();

#ifdef _RTT_USE_SERIAL0_

  Serial_begin(0, 9600);
  Serial_write(0, "***starting the model***", 26);

#endif

  check_temperature_initialize();
  arduino_Timer_Setup();

  /* The main step loop */
  while (rtmGetErrorStatus(check_temperature_M) == (NULL)) {
  }

  check_temperature_terminate();

  /* Disable Interrupts */
  cli();
  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
