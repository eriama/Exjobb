/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: amanda_blinkingblink.c
 *
 * Code generated for Simulink model 'amanda_blinkingblink'.
 *
 * Model version                  : 1.15
 * Simulink Coder version         : 8.8 (R2015a) 09-Feb-2015
 * C/C++ source code generated on : Wed Feb 17 11:09:09 2016
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "amanda_blinkingblink.h"
#include "amanda_blinkingblink_private.h"
#include "amanda_blinkingblink_dt.h"

/* Block signals (auto storage) */
B_amanda_blinkingblink_T amanda_blinkingblink_B;

/* Block states (auto storage) */
DW_amanda_blinkingblink_T amanda_blinkingblink_DW;

/* Real-time model */
RT_MODEL_amanda_blinkingblink_T amanda_blinkingblink_M_;
RT_MODEL_amanda_blinkingblink_T *const amanda_blinkingblink_M =
  &amanda_blinkingblink_M_;

/* Model step function */
void amanda_blinkingblink_step(void)
{
  uint32_T tmp;
  boolean_T tmp_0;

  /* S-Function (armcortexa_analogInput_sfcn): '<Root>/Analog Input' */
  tmp = amanda_blinkingblink_P.AnalogInput_p1;
  amanda_blinkingblink_B.AnalogInput = MW_analogInputRead(&tmp);

  /* Switch: '<Root>/Switch' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   */
  if (amanda_blinkingblink_B.AnalogInput >
      amanda_blinkingblink_P.Switch_Threshold) {
    tmp_0 = amanda_blinkingblink_P.Constant_Value;
  } else {
    tmp_0 = amanda_blinkingblink_P.Constant1_Value;
  }

  /* End of Switch: '<Root>/Switch' */

  /* S-Function (armcortexa_LedWrite_sfcn): '<Root>/LED' */
  MW_ledWrite(amanda_blinkingblink_P.LED_p1, tmp_0);

  /* Matfile logging */
  rt_UpdateTXYLogVars(amanda_blinkingblink_M->rtwLogInfo,
                      (&amanda_blinkingblink_M->Timing.taskTime0));

  /* External mode */
  rtExtModeUploadCheckTrigger(1);

  {                                    /* Sample time: [0.1s, 0.0s] */
    rtExtModeUpload(0, amanda_blinkingblink_M->Timing.taskTime0);
  }

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(amanda_blinkingblink_M)!=-1) &&
        !((rtmGetTFinal(amanda_blinkingblink_M)-
           amanda_blinkingblink_M->Timing.taskTime0) >
          amanda_blinkingblink_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(amanda_blinkingblink_M, "Simulation finished");
    }

    if (rtmGetStopRequested(amanda_blinkingblink_M)) {
      rtmSetErrorStatus(amanda_blinkingblink_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++amanda_blinkingblink_M->Timing.clockTick0)) {
    ++amanda_blinkingblink_M->Timing.clockTickH0;
  }

  amanda_blinkingblink_M->Timing.taskTime0 =
    amanda_blinkingblink_M->Timing.clockTick0 *
    amanda_blinkingblink_M->Timing.stepSize0 +
    amanda_blinkingblink_M->Timing.clockTickH0 *
    amanda_blinkingblink_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void amanda_blinkingblink_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)amanda_blinkingblink_M, 0,
                sizeof(RT_MODEL_amanda_blinkingblink_T));
  rtmSetTFinal(amanda_blinkingblink_M, -1);
  amanda_blinkingblink_M->Timing.stepSize0 = 0.1;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    amanda_blinkingblink_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(amanda_blinkingblink_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(amanda_blinkingblink_M->rtwLogInfo, (NULL));
    rtliSetLogT(amanda_blinkingblink_M->rtwLogInfo, "tout");
    rtliSetLogX(amanda_blinkingblink_M->rtwLogInfo, "");
    rtliSetLogXFinal(amanda_blinkingblink_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(amanda_blinkingblink_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(amanda_blinkingblink_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(amanda_blinkingblink_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(amanda_blinkingblink_M->rtwLogInfo, 1);
    rtliSetLogY(amanda_blinkingblink_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(amanda_blinkingblink_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(amanda_blinkingblink_M->rtwLogInfo, (NULL));
  }

  /* External mode info */
  amanda_blinkingblink_M->Sizes.checksums[0] = (3429714542U);
  amanda_blinkingblink_M->Sizes.checksums[1] = (3533580598U);
  amanda_blinkingblink_M->Sizes.checksums[2] = (1533323063U);
  amanda_blinkingblink_M->Sizes.checksums[3] = (3634880746U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    amanda_blinkingblink_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(amanda_blinkingblink_M->extModeInfo,
      &amanda_blinkingblink_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(amanda_blinkingblink_M->extModeInfo,
                        amanda_blinkingblink_M->Sizes.checksums);
    rteiSetTPtr(amanda_blinkingblink_M->extModeInfo, rtmGetTPtr
                (amanda_blinkingblink_M));
  }

  /* block I/O */
  (void) memset(((void *) &amanda_blinkingblink_B), 0,
                sizeof(B_amanda_blinkingblink_T));

  /* states (dwork) */
  (void) memset((void *)&amanda_blinkingblink_DW, 0,
                sizeof(DW_amanda_blinkingblink_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    amanda_blinkingblink_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(amanda_blinkingblink_M->rtwLogInfo, 0.0,
    rtmGetTFinal(amanda_blinkingblink_M),
    amanda_blinkingblink_M->Timing.stepSize0, (&rtmGetErrorStatus
    (amanda_blinkingblink_M)));

  /* Start for S-Function (armcortexa_analogInput_sfcn): '<Root>/Analog Input' */
  MW_analogInputInit();

  /* Start for S-Function (armcortexa_LedWrite_sfcn): '<Root>/LED' */
  MW_ledInit(amanda_blinkingblink_P.LED_p1);
}

/* Model terminate function */
void amanda_blinkingblink_terminate(void)
{
  /* Terminate for S-Function (armcortexa_LedWrite_sfcn): '<Root>/LED' */
  MW_ledTerminate(amanda_blinkingblink_P.LED_p1);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
