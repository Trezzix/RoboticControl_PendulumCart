/*
 * quarc_read_write_demo_TLS_dt.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "quarc_read_write_demo_TLS".
 *
 * Model version              : 14.24
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Thu Oct 16 10:36:47 2025
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86-64 (Windows64)
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
  2*sizeof(uint32_T),
  sizeof(int32_T),
  sizeof(t_card),
  sizeof(uint_T),
  sizeof(char_T),
  sizeof(uchar_T),
  sizeof(time_T)
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
  "timer_uint32_pair_T",
  "physical_connection",
  "t_card",
  "uint_T",
  "char_T",
  "uchar_T",
  "time_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&quarc_read_write_demo_TLS_B.ManualSwitch), 0, 0, 4 }
  ,

  { (char_T *)(&quarc_read_write_demo_TLS_DW.HILInitialize1_AIMinimums[0]), 0, 0,
    14 },

  { (char_T *)(&quarc_read_write_demo_TLS_DW.HILInitialize1_Card), 15, 0, 1 },

  { (char_T *)(&quarc_read_write_demo_TLS_DW.HILWriteAnalog_PWORK), 11, 0, 6 },

  { (char_T *)(&quarc_read_write_demo_TLS_DW.HILInitialize1_ClockModes), 6, 0, 7
  }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  5U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&quarc_read_write_demo_TLS_P.HILWriteAnalog_channels), 7, 0, 4 },

  { (char_T *)(&quarc_read_write_demo_TLS_P.Constant_Value), 0, 0, 23 },

  { (char_T *)(&quarc_read_write_demo_TLS_P.HILInitialize1_CKChannels), 6, 0, 4
  },

  { (char_T *)(&quarc_read_write_demo_TLS_P.HILInitialize1_AIChannels[0]), 7, 0,
    7 },

  { (char_T *)(&quarc_read_write_demo_TLS_P.HILInitialize1_Active), 8, 0, 38 },

  { (char_T *)(&quarc_read_write_demo_TLS_P.ManualSwitch_CurrentSetting), 3, 0,
    1 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  6U,
  rtPTransitions
};

/* [EOF] quarc_read_write_demo_TLS_dt.h */
