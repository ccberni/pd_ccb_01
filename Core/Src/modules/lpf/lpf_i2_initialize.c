/*
 * File: lpf_i2_initialize.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 11-Jul-2022 20:52:52
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "lpf_i2.h"
#include "lpf_i2_initialize.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void lpf_i2_initialize(void)
{
  rt_InitInfAndNaN(8U);
  Hd_not_empty_init_i2();
}

/*
 * File trailer for lpf_i2_initialize.c
 *
 * [EOF]
 */
