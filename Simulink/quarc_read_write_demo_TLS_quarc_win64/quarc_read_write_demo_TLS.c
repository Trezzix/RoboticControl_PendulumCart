/*
 * quarc_read_write_demo_TLS.c
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
#include "rtwtypes.h"
#include <math.h>
#include "quarc_read_write_demo_TLS_private.h"
#include "rt_nonfinite.h"
#include <string.h>
#include "quarc_read_write_demo_TLS_dt.h"

/* Block signals (default storage) */
B_quarc_read_write_demo_TLS_T quarc_read_write_demo_TLS_B;

/* Block states (default storage) */
DW_quarc_read_write_demo_TLS_T quarc_read_write_demo_TLS_DW;

/* Real-time model */
static RT_MODEL_quarc_read_write_dem_T quarc_read_write_demo_TLS_M_;
RT_MODEL_quarc_read_write_dem_T *const quarc_read_write_demo_TLS_M =
  &quarc_read_write_demo_TLS_M_;
real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T tmp;
  real_T tmp_0;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Model output function */
void quarc_read_write_demo_TLS_output(void)
{
  /* local block i/o variables */
  real_T rtb_analog_read;
  real_T rtb_Clock_tmp;
  real_T rtb_HILReadEncoder_o1;
  real_T rtb_HILReadEncoder_o2;
  real_T tau;

  /* ManualSwitch: '<Root>/Manual Switch' */
  if (quarc_read_write_demo_TLS_P.ManualSwitch_CurrentSetting == 1) {
    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Constant: '<Root>/Constant'
     */
    quarc_read_write_demo_TLS_B.ManualSwitch =
      quarc_read_write_demo_TLS_P.Constant_Value;
  } else {
    /* ManualSwitch: '<Root>/Manual Switch' incorporates:
     *  Constant: '<Root>/Constant1'
     */
    quarc_read_write_demo_TLS_B.ManualSwitch =
      quarc_read_write_demo_TLS_P.Constant1_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual Switch' */

  /* Clock: '<Root>/Clock' incorporates:
   *  SignalGenerator: '<Root>/Signal Generator'
   */
  rtb_Clock_tmp = quarc_read_write_demo_TLS_M->Timing.t[0];

  /* MATLAB Function: '<Root>/safety_envelope' incorporates:
   *  Clock: '<Root>/Clock'
   *  SignalGenerator: '<Root>/Signal Generator'
   */
  /* MATLAB Function 'safety_envelope': '<S3>:1' */
  if (quarc_read_write_demo_TLS_B.ManualSwitch != 0.0) {
    if (quarc_read_write_demo_TLS_DW.t0 == 0.0) {
      /* '<S3>:1:11' */
      /* '<S3>:1:12' */
      quarc_read_write_demo_TLS_DW.t0 = rtb_Clock_tmp;
    }

    /* '<S3>:1:14' */
    tau = (rtb_Clock_tmp - quarc_read_write_demo_TLS_DW.t0) / 2.0;
    if (!(tau >= 0.0)) {
      tau = 0.0;
    }

    if (!(tau <= 1.0)) {
      tau = 1.0;
    }

    /* '<S3>:1:15' */
    quarc_read_write_demo_TLS_B.out = sin(6.2831853071795862 * rtb_Clock_tmp *
      quarc_read_write_demo_TLS_P.SignalGenerator_Frequency) *
      quarc_read_write_demo_TLS_P.SignalGenerator_Amplitude * (tau * tau * 3.0 -
      2.0 * rt_powd_snf(tau, 3.0));
  } else {
    /* '<S3>:1:17' */
    quarc_read_write_demo_TLS_B.out = 0.0;

    /* '<S3>:1:18' */
    quarc_read_write_demo_TLS_DW.t0 = 0.0;
  }

  /* End of MATLAB Function: '<Root>/safety_envelope' */

  /* S-Function (hil_write_analog_block): '<Root>/HIL Write Analog' */

  /* S-Function Block: quarc_read_write_demo_TLS/HIL Write Analog (hil_write_analog_block) */
  {
    t_error result;
    result = hil_write_analog(quarc_read_write_demo_TLS_DW.HILInitialize1_Card,
      &quarc_read_write_demo_TLS_P.HILWriteAnalog_channels, 1,
      &quarc_read_write_demo_TLS_B.out);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(quarc_read_write_demo_TLS_M, _rt_error_message);
    }
  }

  /* S-Function (hil_read_analog_block): '<Root>/HIL Read Analog' */

  /* S-Function Block: quarc_read_write_demo_TLS/HIL Read Analog (hil_read_analog_block) */
  {
    t_error result = hil_read_analog
      (quarc_read_write_demo_TLS_DW.HILInitialize1_Card,
       &quarc_read_write_demo_TLS_P.HILReadAnalog_channels, 1,
       &quarc_read_write_demo_TLS_DW.HILReadAnalog_Buffer);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(quarc_read_write_demo_TLS_M, _rt_error_message);
    }

    rtb_analog_read = quarc_read_write_demo_TLS_DW.HILReadAnalog_Buffer;
  }

  /* S-Function (hil_read_encoder_block): '<Root>/HIL Read Encoder' */

  /* S-Function Block: quarc_read_write_demo_TLS/HIL Read Encoder (hil_read_encoder_block) */
  {
    t_error result = hil_read_encoder
      (quarc_read_write_demo_TLS_DW.HILInitialize1_Card,
       quarc_read_write_demo_TLS_P.HILReadEncoder_channels, 2,
       &quarc_read_write_demo_TLS_DW.HILReadEncoder_Buffer[0]);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(quarc_read_write_demo_TLS_M, _rt_error_message);
    } else {
      rtb_HILReadEncoder_o1 =
        quarc_read_write_demo_TLS_DW.HILReadEncoder_Buffer[0];
      rtb_HILReadEncoder_o2 =
        quarc_read_write_demo_TLS_DW.HILReadEncoder_Buffer[1];
    }
  }

  /* Gain: '<Root>/[m] to [mm]' incorporates:
   *  Gain: '<Root>/[counts] to [m]'
   */
  quarc_read_write_demo_TLS_B.cart_pos_mm =
    quarc_read_write_demo_TLS_P.countstom_Gain * rtb_HILReadEncoder_o1 *
    quarc_read_write_demo_TLS_P.mtomm_Gain;

  /* Gain: '<S2>/Gain' incorporates:
   *  Gain: '<Root>/[counts] to [rad]'
   */
  quarc_read_write_demo_TLS_B.Gain =
    quarc_read_write_demo_TLS_P.countstorad_Gain * rtb_HILReadEncoder_o2 *
    quarc_read_write_demo_TLS_P.Gain_Gain;
}

/* Model update function */
void quarc_read_write_demo_TLS_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++quarc_read_write_demo_TLS_M->Timing.clockTick0)) {
    ++quarc_read_write_demo_TLS_M->Timing.clockTickH0;
  }

  quarc_read_write_demo_TLS_M->Timing.t[0] =
    quarc_read_write_demo_TLS_M->Timing.clockTick0 *
    quarc_read_write_demo_TLS_M->Timing.stepSize0 +
    quarc_read_write_demo_TLS_M->Timing.clockTickH0 *
    quarc_read_write_demo_TLS_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++quarc_read_write_demo_TLS_M->Timing.clockTick1)) {
      ++quarc_read_write_demo_TLS_M->Timing.clockTickH1;
    }

    quarc_read_write_demo_TLS_M->Timing.t[1] =
      quarc_read_write_demo_TLS_M->Timing.clockTick1 *
      quarc_read_write_demo_TLS_M->Timing.stepSize1 +
      quarc_read_write_demo_TLS_M->Timing.clockTickH1 *
      quarc_read_write_demo_TLS_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void quarc_read_write_demo_TLS_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize1' */

  /* S-Function Block: quarc_read_write_demo_TLS/HIL Initialize1 (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q2_usb", "0",
                      &quarc_read_write_demo_TLS_DW.HILInitialize1_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(quarc_read_write_demo_TLS_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (quarc_read_write_demo_TLS_DW.HILInitialize1_Card,
       "d0=digital;d1=digital;led=auto;update_rate=normal;decimation=1", 63);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(quarc_read_write_demo_TLS_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(quarc_read_write_demo_TLS_DW.HILInitialize1_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(quarc_read_write_demo_TLS_M, _rt_error_message);
      return;
    }

    if ((quarc_read_write_demo_TLS_P.HILInitialize1_AIPStart && !is_switching) ||
        (quarc_read_write_demo_TLS_P.HILInitialize1_AIPEnter && is_switching)) {
      quarc_read_write_demo_TLS_DW.HILInitialize1_AIMinimums[0] =
        (quarc_read_write_demo_TLS_P.HILInitialize1_AILow);
      quarc_read_write_demo_TLS_DW.HILInitialize1_AIMinimums[1] =
        (quarc_read_write_demo_TLS_P.HILInitialize1_AILow);
      quarc_read_write_demo_TLS_DW.HILInitialize1_AIMaximums[0] =
        quarc_read_write_demo_TLS_P.HILInitialize1_AIHigh;
      quarc_read_write_demo_TLS_DW.HILInitialize1_AIMaximums[1] =
        quarc_read_write_demo_TLS_P.HILInitialize1_AIHigh;
      result = hil_set_analog_input_ranges
        (quarc_read_write_demo_TLS_DW.HILInitialize1_Card,
         quarc_read_write_demo_TLS_P.HILInitialize1_AIChannels, 2U,
         &quarc_read_write_demo_TLS_DW.HILInitialize1_AIMinimums[0],
         &quarc_read_write_demo_TLS_DW.HILInitialize1_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(quarc_read_write_demo_TLS_M, _rt_error_message);
        return;
      }
    }

    if ((quarc_read_write_demo_TLS_P.HILInitialize1_AOPStart && !is_switching) ||
        (quarc_read_write_demo_TLS_P.HILInitialize1_AOPEnter && is_switching)) {
      quarc_read_write_demo_TLS_DW.HILInitialize1_AOMinimums[0] =
        (quarc_read_write_demo_TLS_P.HILInitialize1_AOLow);
      quarc_read_write_demo_TLS_DW.HILInitialize1_AOMinimums[1] =
        (quarc_read_write_demo_TLS_P.HILInitialize1_AOLow);
      quarc_read_write_demo_TLS_DW.HILInitialize1_AOMaximums[0] =
        quarc_read_write_demo_TLS_P.HILInitialize1_AOHigh;
      quarc_read_write_demo_TLS_DW.HILInitialize1_AOMaximums[1] =
        quarc_read_write_demo_TLS_P.HILInitialize1_AOHigh;
      result = hil_set_analog_output_ranges
        (quarc_read_write_demo_TLS_DW.HILInitialize1_Card,
         quarc_read_write_demo_TLS_P.HILInitialize1_AOChannels, 2U,
         &quarc_read_write_demo_TLS_DW.HILInitialize1_AOMinimums[0],
         &quarc_read_write_demo_TLS_DW.HILInitialize1_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(quarc_read_write_demo_TLS_M, _rt_error_message);
        return;
      }
    }

    if ((quarc_read_write_demo_TLS_P.HILInitialize1_AOStart && !is_switching) ||
        (quarc_read_write_demo_TLS_P.HILInitialize1_AOEnter && is_switching)) {
      quarc_read_write_demo_TLS_DW.HILInitialize1_AOVoltages[0] =
        quarc_read_write_demo_TLS_P.HILInitialize1_AOInitial;
      quarc_read_write_demo_TLS_DW.HILInitialize1_AOVoltages[1] =
        quarc_read_write_demo_TLS_P.HILInitialize1_AOInitial;
      result = hil_write_analog(quarc_read_write_demo_TLS_DW.HILInitialize1_Card,
        quarc_read_write_demo_TLS_P.HILInitialize1_AOChannels, 2U,
        &quarc_read_write_demo_TLS_DW.HILInitialize1_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(quarc_read_write_demo_TLS_M, _rt_error_message);
        return;
      }
    }

    if (quarc_read_write_demo_TLS_P.HILInitialize1_AOReset) {
      quarc_read_write_demo_TLS_DW.HILInitialize1_AOVoltages[0] =
        quarc_read_write_demo_TLS_P.HILInitialize1_AOWatchdog;
      quarc_read_write_demo_TLS_DW.HILInitialize1_AOVoltages[1] =
        quarc_read_write_demo_TLS_P.HILInitialize1_AOWatchdog;
      result = hil_watchdog_set_analog_expiration_state
        (quarc_read_write_demo_TLS_DW.HILInitialize1_Card,
         quarc_read_write_demo_TLS_P.HILInitialize1_AOChannels, 2U,
         &quarc_read_write_demo_TLS_DW.HILInitialize1_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(quarc_read_write_demo_TLS_M, _rt_error_message);
        return;
      }
    }

    if ((quarc_read_write_demo_TLS_P.HILInitialize1_EIPStart && !is_switching) ||
        (quarc_read_write_demo_TLS_P.HILInitialize1_EIPEnter && is_switching)) {
      quarc_read_write_demo_TLS_DW.HILInitialize1_QuadratureModes[0] =
        quarc_read_write_demo_TLS_P.HILInitialize1_EIQuadrature;
      quarc_read_write_demo_TLS_DW.HILInitialize1_QuadratureModes[1] =
        quarc_read_write_demo_TLS_P.HILInitialize1_EIQuadrature;
      result = hil_set_encoder_quadrature_mode
        (quarc_read_write_demo_TLS_DW.HILInitialize1_Card,
         quarc_read_write_demo_TLS_P.HILInitialize1_EIChannels, 2U,
         (t_encoder_quadrature_mode *)
         &quarc_read_write_demo_TLS_DW.HILInitialize1_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(quarc_read_write_demo_TLS_M, _rt_error_message);
        return;
      }
    }

    if ((quarc_read_write_demo_TLS_P.HILInitialize1_EIStart && !is_switching) ||
        (quarc_read_write_demo_TLS_P.HILInitialize1_EIEnter && is_switching)) {
      quarc_read_write_demo_TLS_DW.HILInitialize1_InitialEICounts[0] =
        quarc_read_write_demo_TLS_P.HILInitialize1_EIInitial;
      quarc_read_write_demo_TLS_DW.HILInitialize1_InitialEICounts[1] =
        quarc_read_write_demo_TLS_P.HILInitialize1_EIInitial;
      result = hil_set_encoder_counts
        (quarc_read_write_demo_TLS_DW.HILInitialize1_Card,
         quarc_read_write_demo_TLS_P.HILInitialize1_EIChannels, 2U,
         &quarc_read_write_demo_TLS_DW.HILInitialize1_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(quarc_read_write_demo_TLS_M, _rt_error_message);
        return;
      }
    }
  }

  /* SystemInitialize for MATLAB Function: '<Root>/safety_envelope' */
  quarc_read_write_demo_TLS_DW.t0 = 0.0;
}

/* Model terminate function */
void quarc_read_write_demo_TLS_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize1' */

  /* S-Function Block: quarc_read_write_demo_TLS/HIL Initialize1 (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    hil_task_stop_all(quarc_read_write_demo_TLS_DW.HILInitialize1_Card);
    hil_monitor_stop_all(quarc_read_write_demo_TLS_DW.HILInitialize1_Card);
    is_switching = false;
    if ((quarc_read_write_demo_TLS_P.HILInitialize1_AOTerminate && !is_switching)
        || (quarc_read_write_demo_TLS_P.HILInitialize1_AOExit && is_switching))
    {
      quarc_read_write_demo_TLS_DW.HILInitialize1_AOVoltages[0] =
        quarc_read_write_demo_TLS_P.HILInitialize1_AOFinal;
      quarc_read_write_demo_TLS_DW.HILInitialize1_AOVoltages[1] =
        quarc_read_write_demo_TLS_P.HILInitialize1_AOFinal;
      num_final_analog_outputs = 2U;
    } else {
      num_final_analog_outputs = 0;
    }

    if (num_final_analog_outputs > 0) {
      result = hil_write_analog(quarc_read_write_demo_TLS_DW.HILInitialize1_Card,
        quarc_read_write_demo_TLS_P.HILInitialize1_AOChannels,
        num_final_analog_outputs,
        &quarc_read_write_demo_TLS_DW.HILInitialize1_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(quarc_read_write_demo_TLS_M, _rt_error_message);
      }
    }

    hil_task_delete_all(quarc_read_write_demo_TLS_DW.HILInitialize1_Card);
    hil_monitor_delete_all(quarc_read_write_demo_TLS_DW.HILInitialize1_Card);
    hil_close(quarc_read_write_demo_TLS_DW.HILInitialize1_Card);
    quarc_read_write_demo_TLS_DW.HILInitialize1_Card = NULL;
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  quarc_read_write_demo_TLS_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  quarc_read_write_demo_TLS_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  quarc_read_write_demo_TLS_initialize();
}

void MdlTerminate(void)
{
  quarc_read_write_demo_TLS_terminate();
}

/* Registration function */
RT_MODEL_quarc_read_write_dem_T *quarc_read_write_demo_TLS(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)quarc_read_write_demo_TLS_M, 0,
                sizeof(RT_MODEL_quarc_read_write_dem_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&quarc_read_write_demo_TLS_M->solverInfo,
                          &quarc_read_write_demo_TLS_M->Timing.simTimeStep);
    rtsiSetTPtr(&quarc_read_write_demo_TLS_M->solverInfo, &rtmGetTPtr
                (quarc_read_write_demo_TLS_M));
    rtsiSetStepSizePtr(&quarc_read_write_demo_TLS_M->solverInfo,
                       &quarc_read_write_demo_TLS_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&quarc_read_write_demo_TLS_M->solverInfo,
                          (&rtmGetErrorStatus(quarc_read_write_demo_TLS_M)));
    rtsiSetRTModelPtr(&quarc_read_write_demo_TLS_M->solverInfo,
                      quarc_read_write_demo_TLS_M);
  }

  rtsiSetSimTimeStep(&quarc_read_write_demo_TLS_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&quarc_read_write_demo_TLS_M->solverInfo,
    false);
  rtsiSetSolverName(&quarc_read_write_demo_TLS_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = quarc_read_write_demo_TLS_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "quarc_read_write_demo_TLS_M points to
       static memory which is guaranteed to be non-NULL" */
    quarc_read_write_demo_TLS_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    quarc_read_write_demo_TLS_M->Timing.sampleTimes =
      (&quarc_read_write_demo_TLS_M->Timing.sampleTimesArray[0]);
    quarc_read_write_demo_TLS_M->Timing.offsetTimes =
      (&quarc_read_write_demo_TLS_M->Timing.offsetTimesArray[0]);

    /* task periods */
    quarc_read_write_demo_TLS_M->Timing.sampleTimes[0] = (0.0);
    quarc_read_write_demo_TLS_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    quarc_read_write_demo_TLS_M->Timing.offsetTimes[0] = (0.0);
    quarc_read_write_demo_TLS_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(quarc_read_write_demo_TLS_M,
             &quarc_read_write_demo_TLS_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = quarc_read_write_demo_TLS_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    quarc_read_write_demo_TLS_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(quarc_read_write_demo_TLS_M, 300.0);
  quarc_read_write_demo_TLS_M->Timing.stepSize0 = 0.01;
  quarc_read_write_demo_TLS_M->Timing.stepSize1 = 0.01;

  /* External mode info */
  quarc_read_write_demo_TLS_M->Sizes.checksums[0] = (3552629589U);
  quarc_read_write_demo_TLS_M->Sizes.checksums[1] = (1962794552U);
  quarc_read_write_demo_TLS_M->Sizes.checksums[2] = (1001016096U);
  quarc_read_write_demo_TLS_M->Sizes.checksums[3] = (3173141589U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[4];
    quarc_read_write_demo_TLS_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(quarc_read_write_demo_TLS_M->extModeInfo,
      &quarc_read_write_demo_TLS_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(quarc_read_write_demo_TLS_M->extModeInfo,
                        quarc_read_write_demo_TLS_M->Sizes.checksums);
    rteiSetTPtr(quarc_read_write_demo_TLS_M->extModeInfo, rtmGetTPtr
                (quarc_read_write_demo_TLS_M));
  }

  quarc_read_write_demo_TLS_M->solverInfoPtr =
    (&quarc_read_write_demo_TLS_M->solverInfo);
  quarc_read_write_demo_TLS_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&quarc_read_write_demo_TLS_M->solverInfo, 0.01);
  rtsiSetSolverMode(&quarc_read_write_demo_TLS_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  quarc_read_write_demo_TLS_M->blockIO = ((void *) &quarc_read_write_demo_TLS_B);

  {
    quarc_read_write_demo_TLS_B.ManualSwitch = 0.0;
    quarc_read_write_demo_TLS_B.cart_pos_mm = 0.0;
    quarc_read_write_demo_TLS_B.Gain = 0.0;
    quarc_read_write_demo_TLS_B.out = 0.0;
  }

  /* parameters */
  quarc_read_write_demo_TLS_M->defaultParam = ((real_T *)
    &quarc_read_write_demo_TLS_P);

  /* states (dwork) */
  quarc_read_write_demo_TLS_M->dwork = ((void *) &quarc_read_write_demo_TLS_DW);
  (void) memset((void *)&quarc_read_write_demo_TLS_DW, 0,
                sizeof(DW_quarc_read_write_demo_TLS_T));
  quarc_read_write_demo_TLS_DW.HILInitialize1_AIMinimums[0] = 0.0;
  quarc_read_write_demo_TLS_DW.HILInitialize1_AIMinimums[1] = 0.0;
  quarc_read_write_demo_TLS_DW.HILInitialize1_AIMaximums[0] = 0.0;
  quarc_read_write_demo_TLS_DW.HILInitialize1_AIMaximums[1] = 0.0;
  quarc_read_write_demo_TLS_DW.HILInitialize1_AOMinimums[0] = 0.0;
  quarc_read_write_demo_TLS_DW.HILInitialize1_AOMinimums[1] = 0.0;
  quarc_read_write_demo_TLS_DW.HILInitialize1_AOMaximums[0] = 0.0;
  quarc_read_write_demo_TLS_DW.HILInitialize1_AOMaximums[1] = 0.0;
  quarc_read_write_demo_TLS_DW.HILInitialize1_AOVoltages[0] = 0.0;
  quarc_read_write_demo_TLS_DW.HILInitialize1_AOVoltages[1] = 0.0;
  quarc_read_write_demo_TLS_DW.HILInitialize1_FilterFrequency[0] = 0.0;
  quarc_read_write_demo_TLS_DW.HILInitialize1_FilterFrequency[1] = 0.0;
  quarc_read_write_demo_TLS_DW.HILReadAnalog_Buffer = 0.0;
  quarc_read_write_demo_TLS_DW.t0 = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    quarc_read_write_demo_TLS_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 20;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  quarc_read_write_demo_TLS_M->Sizes.numContStates = (0);/* Number of continuous states */
  quarc_read_write_demo_TLS_M->Sizes.numY = (0);/* Number of model outputs */
  quarc_read_write_demo_TLS_M->Sizes.numU = (0);/* Number of model inputs */
  quarc_read_write_demo_TLS_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  quarc_read_write_demo_TLS_M->Sizes.numSampTimes = (2);/* Number of sample times */
  quarc_read_write_demo_TLS_M->Sizes.numBlocks = (19);/* Number of blocks */
  quarc_read_write_demo_TLS_M->Sizes.numBlockIO = (4);/* Number of block outputs */
  quarc_read_write_demo_TLS_M->Sizes.numBlockPrms = (77);/* Sum of parameter "widths" */
  return quarc_read_write_demo_TLS_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
