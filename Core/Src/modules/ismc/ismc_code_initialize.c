/*
 * File: ismc_code_initialize.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 22-Jun-2022 18:08:33
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "ismc_code.h"
#include "ismc_code_initialize.h"
#include "ismc_code_data.h"

/* Named Constants */
#define b_ed_n1                        (0.0)
#define b_e_n1                         (0.0)
#define b_xd_n1                        (0.0)
#define b_x_n1                         (0.0)
#define b_spd_n1                       (0.0)
#define b_sp_n1                        (0.0)
#define b_spdd_n1                      (0.0)
#define b_ei_n1                        (0.0)

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void ismc_code_initialize(void)
{
  rt_InitInfAndNaN(8U);
  ei_n1 = b_ei_n1;
  spdd_n1 = b_spdd_n1;
  sp_n1 = b_sp_n1;
  spd_n1 = b_spd_n1;
  x_n1 = b_x_n1;
  xd_n1 = b_xd_n1;
  e_n1 = b_e_n1;
  ed_n1 = b_ed_n1;
}

/*
 * File trailer for ismc_code_initialize.c
 *
 * [EOF]
 */
