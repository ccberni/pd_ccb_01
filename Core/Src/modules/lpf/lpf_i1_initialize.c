/*
 * File: lpf_i1_initialize.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 21-Aug-2022 12:47:05
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "lpf_i1.h"
#include "lpf_i1_initialize.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void lpf_i1_initialize(void)
{
  rt_InitInfAndNaN(8U);
  Hd_not_empty_init_i1();
}

/*
 * File trailer for lpf_i1_initialize.c
 *
 * [EOF]
 */
