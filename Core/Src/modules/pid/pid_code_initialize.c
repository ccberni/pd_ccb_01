/*
 * File: pid_code_initialize.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 02-Apr-2022 17:42:47
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "pid_code.h"
#include "pid_code_initialize.h"
#include "pid_code_data.h"

/* Named Constants */
#define b_u_ant                        (0.0)
#define b_ui_ant                       (0.0)
#define b_ud_ant                       (0.0)
#define b_x_ant                        (0.0)

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void pid_code_initialize(void)
{
  rt_InitInfAndNaN(8U);
  x_ant = b_x_ant;
  ud_ant = b_ud_ant;
  ui_ant = b_ui_ant;
  u_ant = b_u_ant;
}

/*
 * File trailer for pid_code_initialize.c
 *
 * [EOF]
 */
