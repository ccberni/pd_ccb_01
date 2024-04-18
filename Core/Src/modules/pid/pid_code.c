/*
 * File: pid_code.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 02-Apr-2022 17:42:47
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "pid_code.h"
#include "pid_code_data.h"

/* Function Definitions */

/*
 * Regressores
 * Arguments    : double sp
 *                double x
 *                const double param[7]
 * Return Type  : double
 */
double pid_code(double sp, double x, const double param[7])
{
  double u;
  double ep;
  double d0;
  double ui;
  double ud;
  double uv;

  /*  Carga de parâmetros recebidos do matlab */
  /*  PID posicional, backward em I e D, com anti-windup v.2 em I, */
  /*  sem kick derivativo, com pólo adicional em D */
  /*  Garante sp dentro da faixa */
  if (sp > param[5]) {
    sp = param[5];
  } else {
    if (sp < 0.0) {
      sp = 0.0;
    }
  }

  /*  Erro */
  ep = sp - x;

  /*  Anti-windup */
  /*  Pid kernel */
  if (u_ant >= param[5]) {
    d0 = u_ant - param[5];
  } else if (u_ant <= -param[5]) {
    d0 = u_ant + param[5];
  } else {
    d0 = 0.0;
  }

  ui = (ui_ant + param[0] * param[4] / param[1] * ep) - param[4] / param[6] * d0;
  ud = param[2] / (param[2] + param[3] * param[4]) * ud_ant - param[0] * param[3]
    * param[2] / (param[2] + param[3] * param[4]) * (x - x_ant);

  /*  Atualiza saída não saturada */
  uv = (param[0] * ep + ui) + ud;

  /*  Atualiza saída saturada */
  if (uv > param[5]) {
    u = param[5];
  } else if (uv < 0.0) {
    u = 0.0;
  } else {
    u = uv;
  }

  /*  Atualiza regressores */
  u_ant = uv;
  x_ant = x;
  ui_ant = ui;
  ud_ant = ud;
  return u;
}

/*
 * File trailer for pid_code.c
 *
 * [EOF]
 */
