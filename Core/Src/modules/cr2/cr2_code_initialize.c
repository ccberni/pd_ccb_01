/*
 * File: cr2_code_initialize.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 02-Apr-2022 18:24:01
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "cr2_code.h"
#include "cr2_code_initialize.h"
#include "cr2_code_data.h"

/* Named Constants */
#define b_uk_n1                        (0.0)

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void cr2_code_initialize(void)
{
  rt_InitInfAndNaN(8U);
  uk_n1 = b_uk_n1;
  cr2_code_init();
}

/*
 * File trailer for cr2_code_initialize.c
 *
 * [EOF]
 */
