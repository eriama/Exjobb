/*
 * amanda_blinkingblink_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "amanda_blinkingblink".
 *
 * Model version              : 1.15
 * Simulink Coder version : 8.8 (R2015a) 09-Feb-2015
 * C source code generated on : Wed Feb 17 11:09:09 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&amanda_blinkingblink_B.AnalogInput), 0, 0, 1 }
  ,

  { (char_T *)(&amanda_blinkingblink_DW.Scope_PWORK.LoggedData), 11, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  2U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&amanda_blinkingblink_P.Switch_Threshold), 0, 0, 1 },

  { (char_T *)(&amanda_blinkingblink_P.AnalogInput_p1), 7, 0, 1 },

  { (char_T *)(&amanda_blinkingblink_P.LED_p1[0]), 3, 0, 22 },

  { (char_T *)(&amanda_blinkingblink_P.Constant1_Value), 8, 0, 2 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  4U,
  rtPTransitions
};

/* [EOF] amanda_blinkingblink_dt.h */
