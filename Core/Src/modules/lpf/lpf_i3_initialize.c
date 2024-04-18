/*
 * File: lpf_i3_initialize.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 11-Jul-2022 20:55:10
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "lpf_i3.h"
#include "lpf_i3_initialize.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void lpf_i3_initialize(void)
{
  rt_InitInfAndNaN(8U);
  Hd_not_empty_init_i3();
}

/*
 * File trailer for lpf_i3_initialize.c
 *
 * [EOF]
 */
