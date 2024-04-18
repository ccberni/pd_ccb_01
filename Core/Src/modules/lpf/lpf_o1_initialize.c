/*
 * File: lpf_o1_initialize.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 13-Jul-2022 17:09:12
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "lpf_o1.h"
#include "lpf_o1_initialize.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void lpf_o1_initialize(void)
{
  rt_InitInfAndNaN(8U);
  Hd_not_empty_init();
}

/*
 * File trailer for lpf_o1_initialize.c
 *
 * [EOF]
 */
