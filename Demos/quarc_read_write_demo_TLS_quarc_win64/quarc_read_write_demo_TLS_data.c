/*
 * quarc_read_write_demo_TLS_data.c
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

#include "quarc_read_write_demo_TLS.h"

/* Block parameters (default storage) */
P_quarc_read_write_demo_TLS_T quarc_read_write_demo_TLS_P = {
  /* Mask Parameter: HILWriteAnalog_channels
   * Referenced by: '<Root>/HIL Write Analog'
   */
  0U,

  /* Mask Parameter: HILReadAnalog_channels
   * Referenced by: '<Root>/HIL Read Analog'
   */
  0U,

  /* Mask Parameter: HILReadEncoder_channels
   * Referenced by: '<Root>/HIL Read Encoder'
   */
  { 0U, 1U },

  /* Expression: 0
   * Referenced by: '<Root>/Constant'
   */
  0.0,

  /* Expression: 1
   * Referenced by: '<Root>/Constant1'
   */
  1.0,

  /* Expression: set_other_outputs_at_terminate
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_out
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: set_other_outputs_at_start
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: set_other_outputs_at_switch_in
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: final_analog_outputs
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: final_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: analog_input_maximums
   * Referenced by: '<Root>/HIL Initialize1'
   */
  10.0,

  /* Expression: analog_input_minimums
   * Referenced by: '<Root>/HIL Initialize1'
   */
  -10.0,

  /* Expression: analog_output_maximums
   * Referenced by: '<Root>/HIL Initialize1'
   */
  10.0,

  /* Expression: analog_output_minimums
   * Referenced by: '<Root>/HIL Initialize1'
   */
  -10.0,

  /* Expression: initial_analog_outputs
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: watchdog_analog_outputs
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: pwm_frequency
   * Referenced by: '<Root>/HIL Initialize1'
   */
  50.0,

  /* Expression: initial_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: watchdog_pwm_outputs
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0.0,

  /* Expression: 2
   * Referenced by: '<Root>/Signal Generator'
   */
  2.0,

  /* Expression: 0.5
   * Referenced by: '<Root>/Signal Generator'
   */
  0.5,

  /* Expression: 2.2749e-05
   * Referenced by: '<Root>/[counts] to [m]'
   */
  2.2749E-5,

  /* Expression:  1e3
   * Referenced by: '<Root>/[m] to [mm]'
   */
  1000.0,

  /* Expression: 2*pi/(4*1024)
   * Referenced by: '<Root>/[counts] to [rad]'
   */
  0.0015339807878856412,

  /* Expression: 180/pi
   * Referenced by: '<S2>/Gain'
   */
  57.295779513082323,

  /* Computed Parameter: HILInitialize1_CKChannels
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_DOWatchdog
   * Referenced by: '<Root>/HIL Initialize1'
   */
  1,

  /* Computed Parameter: HILInitialize1_EIInitial
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_POModes
   * Referenced by: '<Root>/HIL Initialize1'
   */
  0,

  /* Computed Parameter: HILInitialize1_AIChannels
   * Referenced by: '<Root>/HIL Initialize1'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize1_AOChannels
   * Referenced by: '<Root>/HIL Initialize1'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize1_EIChannels
   * Referenced by: '<Root>/HIL Initialize1'
   */
  { 0U, 1U },

  /* Computed Parameter: HILInitialize1_EIQuadrature
   * Referenced by: '<Root>/HIL Initialize1'
   */
  4U,

  /* Computed Parameter: HILInitialize1_Active
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_AOTerminate
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_AOExit
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_DOTerminate
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_DOExit
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_POTerminate
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_POExit
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_CKPStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_CKPEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_CKStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_CKEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_AIPStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_AIPEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_AOPStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_AOPEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_AOStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_AOEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_AOReset
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_DOPStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_DOPEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_DOStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_DOEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_DOReset
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_EIPStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_EIPEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_EIStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_EIEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_POPStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_POPEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_POStart
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_POEnter
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_POReset
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_OOReset
   * Referenced by: '<Root>/HIL Initialize1'
   */
  false,

  /* Computed Parameter: HILInitialize1_DOFinal
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILInitialize1_DOInitial
   * Referenced by: '<Root>/HIL Initialize1'
   */
  true,

  /* Computed Parameter: HILWriteAnalog_Active
   * Referenced by: '<Root>/HIL Write Analog'
   */
  true,

  /* Computed Parameter: HILReadAnalog_Active
   * Referenced by: '<Root>/HIL Read Analog'
   */
  true,

  /* Computed Parameter: HILReadEncoder_Active
   * Referenced by: '<Root>/HIL Read Encoder'
   */
  true,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  1U
};
