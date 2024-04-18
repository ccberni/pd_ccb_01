/*
 * File: cr2_code.c
 *
 * MATLAB Coder version            : 2.8
 * C/C++ source code generated on  : 02-Apr-2022 18:24:01
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "cr2_code.h"
#include "cr2_code_data.h"

/* Variable Definitions */
static double cnt_ti;
static double cnt_to;
static double f_cong;

/* Function Definitions */

/*
 * Regressor
 * Arguments    : double e
 *                const double param_cr2[5]
 * Return Type  : double
 */
double cr2_code(double e, const double param_cr2[5])
{
  double uk;

  /*  Variáveis locais estáticas */
  /*  Contadores para congelamento e descongelamento do algoritmo cr2, */
  /*  e flag marcadora de estados de congelamento/descongelamento. */
  /*  Caso a inicialização não seja garantida em zero, usar global. */
  /*  Parâmetros */
  /*  Inicialização de variaveis locais */
  /*  Checagem de congelamento e descongelamento */
  /*  |erro| é menor que um delta? */
  if (fabs(e) <= param_cr2[3]) {
    /*  Sim, reseta timer de descongelamento */
    cnt_to = 0.0;

    /*  Em congelamento? */
    if (f_cong == 1.0) {
      /*  Sim, mantém uk anterior */
      uk = uk_n1;
    } else {
      /*  Não, conta tempo para congelamento */
      cnt_ti++;

      /*  Checa se já atingiu tempo de congelamento */
      if (cnt_ti > param_cr2[1] / param_cr2[4]) {
        /*  Sim, marca estado */
        f_cong = 1.0;

        /*  Mantém uk anterior */
        uk = uk_n1;
      } else {
        /*  Não, faz Cr2 */
        /*  Cr2 */
        /* %%%%%%%%%%%%%%%%%%%%%%%% */
        /*  Função local - alg. Cr2 */
        if (e < 0.0) {
          uk = -param_cr2[0] / 2.0;
        } else if (e > 0.0) {
          uk = param_cr2[0] / 2.0;
        } else {
          uk = 0.0;
        }

        /* %%%%%%%%%%%%%%%%%%%%%%%% */
      }
    }

    /*  Não, |erro| > delta */
  } else {
    /*  Reseta timer de congelamento */
    cnt_ti = 0.0;

    /*  Em descongelamento? */
    if (f_cong == 0.0) {
      /*  Sim, faz Cr2 */
      /*  Cr2 */
      /* %%%%%%%%%%%%%%%%%%%%%%%% */
      /*  Função local - alg. Cr2 */
      if (e < 0.0) {
        uk = -param_cr2[0] / 2.0;
      } else if (e > 0.0) {
        uk = param_cr2[0] / 2.0;
      } else {
        uk = 0.0;
      }

      /* %%%%%%%%%%%%%%%%%%%%%%%% */
    } else {
      /*  Não, conta tempo para descongelamento */
      cnt_to++;

      /*  Checa se já atingiu tempo de descongelamento */
      if (cnt_to > param_cr2[2] / param_cr2[4]) {
        /*  Sim, marca estado */
        f_cong = 0.0;

        /*  Faz Cr2 */
        /*  Cr2 */
        /* %%%%%%%%%%%%%%%%%%%%%%%% */
        /*  Função local - alg. Cr2 */
        if (e < 0.0) {
          uk = -param_cr2[0] / 2.0;
        } else if (e > 0.0) {
          uk = param_cr2[0] / 2.0;
        } else {
          uk = 0.0;
        }

        /* %%%%%%%%%%%%%%%%%%%%%%%% */
      } else {
        /*  Não, mantém uk anterior */
        uk = uk_n1;
      }
    }
  }

  /*  Atualiza regressor */
  uk_n1 = uk;
  return uk;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void cr2_code_init(void)
{
  cnt_ti = 0.0;
  cnt_to = 0.0;
  f_cong = 0.0;
}

/*
 * File trailer for cr2_code.c
 *
 * [EOF]
 */
