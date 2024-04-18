/*
 * params.h
 *
 *  Created on: Apr 22, 2022
 *      Author: Cassio
 */

#ifndef INC_APP_PARAMS_H_
#define INC_APP_PARAMS_H_

// Sampling time (sec)
#define TS				0.001

// Select kp in Pa/% or Pa/V
// Note: KP unit is Pa/%, which is 10x lower than the same value in Pa/V!!!
// 6 ~ 26 psi <=> 0 ~ 8.33 V == 6 ~ 30 psi <=> 0 ~ 10 V
#define	KP_PA_PERCENT	1654.742	// [Pa/%]
#define	KP_PA_V			16547.42    // [Pa/V]

// Process parameters (Ismc)
#define KP				KP_PA_V
#define SA				0.0445     	// [m2] = 445 cm2
#define K				176643.91  	// [N/m] Constante elástica da mola
#define FC				993.35     	// [N]
#define FS				1084.66		// [N]
#define VS				2.54e-4		// [m/s]
#define SIGMA			10000.0		// (adim)
#define M				1.6         // [kg]

// Ctr parameters
// Pid
// Sintonia por Ziegler-Nichols - curva de reação
#define KP_Z			5.62
#define TI_Z			0.6
#define TD_Z			0.15
// Sintonia por Síntese Direta / SIMC
#define KP_S			2.34
#define TI_S			1.38
#define TD_S			0.0

#define PID_KP			KP_S
#define PID_TI			TI_S
#define PID_TD			TD_S
#define PID_N			20.0
#define PID_SAT			10.0
#define PID_TT			10.0

// Ismc
#define ISMC_LAMBDA		1.0  		// (adim)
#define ISMC_PHI		0.035 		// (adim)
#define ISMC_KC			50.17		// (adim)
#define ISMC_SAT		10.0  		// Saturação de sp e da saída u [V]

// Cr2
// Parâmetro S da válvula FV-11, segundo o modelo de Kano
// O fator x 10 para o atuador é aplicado em app.c.
#define CR2_S			(28.22 / 100)
// Tempo para entrada em congelamento, em seg.
#define	CR2_TI			2.0
// Tempo para saída do congelamento, em seg.
#define CR2_TO			5.0
// Erro máximo de 3% da vazão máxima (18 m3/h)
#define CR2_DT			(0.03 * 18)

#endif /* INC_APP_PARAMS_H_ */
