/*
 * File: ismc_code.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 22-Jun-2022 18:08:33
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "ismc_code.h"
#include "ismc_code_data.h"

/* Function Definitions */

/*
 * Variáveis globais
 * Arguments    : double sp
 *                double x
 *                const double param[13]
 * Return Type  : double
 */
double ismc_code(double sp, double x, const double param[13])
{
  double u;
  double ad;
  double bd;
  double ai;
  double e;
  double ed;
  double xd;
  double spd;
  double spdd;
  double ei;
  double y;
  double sc;
  double b_sc;

  /*  Parâmetros de modelamento */
  /*  [Pa/V] */
  /*  [m2] */
  /*  [N/m] */
  /*  [N] */
  /*  [N] */
  /*  [m/s] */
  /*  (adim) */
  /*  [kg] */
  /*  Parâmetros do controlador */
  /*  [1/s] */
  /*  [m/s] */
  /*  (adim) */
  /*  Intervalo de amostragem */
  /*  [s] */
  /*  Saturação de sp e da saída u */
  /*  [V] */
  /*  Parâmetros da derivada D(Z) e da integral I(z) */
  if (param[11] == 0.01) {
    ad = 0.8824;
    bd = 11.76;
    ai = 0.005;
  } else if (param[11] == 0.001) {
    ad = 0.9876;
    bd = 12.42;
    ai = 0.0005;
  } else {
    ad = 0.0;
    bd = 0.0;
    ai = 0.0;
  }

  /*  Código do algoritmo */
  /*  Garante sp dentro da faixa */
  if (sp > param[12]) {
    sp = param[12];
  } else {
    if (sp < 0.0) {
      sp = 0.0;
    }
  }

  /*  Converte sp e pos. atual em metros */
  /*  Região total do conversor V-I-P: 0 ~ 10.0 V ==> */
  /*  6 ~ 30 psi ==> 0 ~ 28.58 mm */
  sp *= 0.002858;
  x *= 0.002858;

  /*  Erro atual */
  e = x - sp;

  /*  Derivada do erro */
  ed = ad * ed_n1 + bd * (e - e_n1);

  /*  Derivada da sa?da */
  xd = ad * xd_n1 + bd * (x - x_n1);

  /*  Derivada do set point */
  spd = ad * spd_n1 + bd * (sp - sp_n1);

  /*  Derivada de 2a ordem do set point */
  spdd = ad * spdd_n1 + bd * (spd - spd_n1);

  /*  Integral do erro */
  ei = ei_n1 + ai * (e + e_n1);

  /*  Superfície de escorregamento */
  /*  Parcela u1 da lei de controle linearizante */
  y = xd / param[5];

  /*  Parcela u2 da lei de controle linearizante */
  /*  Termo u da lei de controle linearizante */
  /*  Limitação do chattering na superfície de escorregamento */
  sc = ((ed + 2.0 * param[8] * e) + param[8] * param[8] * ei) / param[9];

  /*  Saturação da superfície de escorregamento limitada */
  /*  Lei de controle final */
  if (sc >= 1.0) {
    b_sc = 1.0;
  } else if (sc <= -1.0) {
    b_sc = -1.0;
  } else {
    b_sc = sc;
  }

  u = (1.0 / (param[0] * param[1]) * (param[2] * x + (param[3] + (param[4] -
          param[3]) * exp(-(y * y))) * tanh(param[6] * xd)) + param[7] / (param
        [0] * param[1]) * ((spdd - 2.0 * param[8] * ed) - param[8] * param[8] *
        e)) - param[10] * b_sc;

  /*  Garante saída com saturação */
  if (u > param[12]) {
    u = param[12];
  } else {
    if (u < 0.0) {
      u = 0.0;
    }
  }

  /*  Atualização de regressores */
  e_n1 = e;
  ed_n1 = ed;
  x_n1 = x;
  xd_n1 = xd;
  sp_n1 = sp;
  spd_n1 = spd;
  spdd_n1 = spdd;
  ei_n1 = ei;
  return u;
}

/*
 * File trailer for ismc_code.c
 *
 * [EOF]
 */
