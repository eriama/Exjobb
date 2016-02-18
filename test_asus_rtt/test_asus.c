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
 * TLC version                    : 8.8 (Jan 20 2015)
 * C/C++ source code generated on : Fri Feb 12 15:46:57 2016
 *
 * Target selection: realtime.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "test_asus.h"
#include "test_asus_private.h"
#include "test_asus_dt.h"

/* Block signals (auto storage) */
B_test_asus_T test_asus_B;

/* Block states (auto storage) */
DW_test_asus_T test_asus_DW;

/* Real-time model */
RT_MODEL_test_asus_T test_asus_M_;
RT_MODEL_test_asus_T *const test_asus_M = &test_asus_M_;

/* Model output function */
void test_asus_output(void)
{
  real_T a;
  real_T i;
  real_T j;
  int32_T b_i;
  int32_T b;
  int32_T b_j;
  int32_T c;
  static const int8_T a_0[16] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1
  };

  /* S-Function (asus_capture_sfcn): '<Root>/asus_capture_sfcn' */
  asusCapture( &test_asus_B.asus_capture_sfcn[0]);

  /* MATLAB Function: '<Root>/get local coordinates' incorporates:
   *  Constant: '<Root>/Camera focal length'
   *  Constant: '<Root>/Center pixel x coordinate'
   *  Constant: '<Root>/Center pixel y coordinate'
   *  Constant: '<Root>/Image pixel interval'
   */
  /* MATLAB Function 'get local coordinates': '<S2>:1' */
  /* '<S2>:1:3' */
  a = 1.0;

  /* '<S2>:1:4' */
  /* 12288 */
  /* '<S2>:1:5' */
  /* '<S2>:1:6' */
  for (b = 0; b < 3072; b++) {
    test_asus_B.x[b] = 0.0;
    test_asus_B.y[b] = 0.0;
    test_asus_B.z[b] = 0.0;
  }

  /* '<S2>:1:7' */
  for (b = 0; b < 76800; b++) {
    test_asus_B.D[b] = (real_T)test_asus_B.asus_capture_sfcn[b] / 1000.0;
  }

  /* is in mm */
  /* '<S2>:1:10' */
  b = (int32_T)(((test_asus_P.interval - 1.0) + 240.0) / test_asus_P.interval);

  /* '<S2>:1:10' */
  for (b_i = 0; b_i < b; b_i++) {
    /* '<S2>:1:10' */
    i = (real_T)b_i * test_asus_P.interval + 1.0;

    /* row -> i,  col->j */
    /* '<S2>:1:11' */
    c = (int32_T)(((test_asus_P.interval - 1.0) + 320.0) / test_asus_P.interval);

    /* '<S2>:1:11' */
    for (b_j = 0; b_j < c; b_j++) {
      /* '<S2>:1:11' */
      j = (real_T)b_j * test_asus_P.interval + 1.0;

      /* '<S2>:1:12' */
      if (test_asus_B.D[(((int32_T)j - 1) * 240 + (int32_T)i) - 1] > 0.0) {
        /* '<S2>:1:13' */
        /*  Pinhole camera model */
        /* '<S2>:1:15' */
        /* '<S2>:1:16' */
        /* '<S2>:1:19' */
        /*  To place coordinates in the world frame */
        /* '<S2>:1:21' */
        test_asus_B.x[(int32_T)a - 1] = test_asus_B.D[(((int32_T)j - 1) * 240 +
          (int32_T)i) - 1] * (j - test_asus_P.cx) / test_asus_P.focal;

        /* '<S2>:1:22' */
        test_asus_B.y[(int32_T)a - 1] = test_asus_B.D[(((int32_T)j - 1) * 240 +
          (int32_T)i) - 1] * (i - test_asus_P.cy) / test_asus_P.focal;

        /* '<S2>:1:23' */
        test_asus_B.z[(int32_T)a - 1] = test_asus_B.D[(((int32_T)j - 1) * 240 +
          (int32_T)i) - 1];

        /* '<S2>:1:24' */
        a++;
      }

      /* '<S2>:1:11' */
    }

    /* '<S2>:1:10' */
  }

  /* '<S2>:1:29' */
  for (b = 0; b < 3072; b++) {
    test_asus_B.locals[3 * b] = test_asus_B.x[b];
  }

  for (b = 0; b < 3072; b++) {
    test_asus_B.locals[1 + 3 * b] = test_asus_B.y[b];
  }

  for (b = 0; b < 3072; b++) {
    test_asus_B.locals[2 + 3 * b] = test_asus_B.z[b];
  }

  /* End of MATLAB Function: '<Root>/get local coordinates' */

  /* MATLAB Function: '<Root>/MATLAB Function' */
  /* MATLAB Function 'MATLAB Function': '<S1>:1' */
  /*  Transformed cloud */
  /* '<S1>:1:18' */
  /* '<S1>:1:19' */
  for (b = 0; b < 3072; b++) {
    test_asus_B.dv0[b << 2] = test_asus_B.locals[3 * b];
    test_asus_B.dv0[1 + (b << 2)] = test_asus_B.locals[3 * b + 1];
    test_asus_B.dv0[2 + (b << 2)] = test_asus_B.locals[3 * b + 2];
  }

  for (b = 0; b < 3072; b++) {
    test_asus_B.dv0[3 + (b << 2)] = 1.0;
  }

  for (b = 0; b < 4; b++) {
    for (b_i = 0; b_i < 3072; b_i++) {
      test_asus_B.a[b + (b_i << 2)] = 0.0;
      test_asus_B.a[b + (b_i << 2)] += test_asus_B.dv0[b_i << 2] * (real_T)a_0[b];
      test_asus_B.a[b + (b_i << 2)] += test_asus_B.dv0[(b_i << 2) + 1] * (real_T)
        a_0[b + 4];
      test_asus_B.a[b + (b_i << 2)] += test_asus_B.dv0[(b_i << 2) + 2] * (real_T)
        a_0[b + 8];
      test_asus_B.a[b + (b_i << 2)] += test_asus_B.dv0[(b_i << 2) + 3] * (real_T)
        a_0[b + 12];
    }
  }

  for (b = 0; b < 3072; b++) {
    test_asus_B.globals[3 * b] = test_asus_B.a[b << 2];
    test_asus_B.globals[1 + 3 * b] = test_asus_B.a[(b << 2) + 1];
    test_asus_B.globals[2 + 3 * b] = test_asus_B.a[(b << 2) + 2];
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */
}

/* Model update function */
void test_asus_update(void)
{
  /* signal main to stop simulation */
  {                                    /* Sample time: [0.1s, 0.0s] */
    if ((rtmGetTFinal(test_asus_M)!=-1) &&
        !((rtmGetTFinal(test_asus_M)-test_asus_M->Timing.taskTime0) >
          test_asus_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(test_asus_M, "Simulation finished");
    }

    if (rtmGetStopRequested(test_asus_M)) {
      rtmSetErrorStatus(test_asus_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  test_asus_M->Timing.taskTime0 =
    (++test_asus_M->Timing.clockTick0) * test_asus_M->Timing.stepSize0;
}

/* Model initialize function */
void test_asus_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)test_asus_M, 0,
                sizeof(RT_MODEL_test_asus_T));
  rtmSetTFinal(test_asus_M, 5.0);
  test_asus_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  test_asus_M->Sizes.checksums[0] = (3866938853U);
  test_asus_M->Sizes.checksums[1] = (887349193U);
  test_asus_M->Sizes.checksums[2] = (1905133136U);
  test_asus_M->Sizes.checksums[3] = (2722095473U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[3];
    test_asus_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(test_asus_M->extModeInfo,
      &test_asus_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(test_asus_M->extModeInfo, test_asus_M->Sizes.checksums);
    rteiSetTPtr(test_asus_M->extModeInfo, rtmGetTPtr(test_asus_M));
  }

  /* block I/O */
  (void) memset(((void *) &test_asus_B), 0,
                sizeof(B_test_asus_T));

  /* states (dwork) */
  (void) memset((void *)&test_asus_DW, 0,
                sizeof(DW_test_asus_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    test_asus_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

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
