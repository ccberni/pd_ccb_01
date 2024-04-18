/*
 * common_def.h
 *
 *  Created on: 29 de jan de 2022
 *      Author: Cassio
 */

#ifndef INC_COMMON_DEF_H_
#define INC_COMMON_DEF_H_

#include "main.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>

#define SIM 	1
#define NAO 	0

// Debugs
// Timer 1 - 1 ms base time
#define	DGB_TMR_1MS_BASE_TIME			NAO
// Adc conversion time
#define	DGB_ADC_CONV_TIME				NAO
// Evaluation of ismc variability when using adc measurements
#define DBG_VAR_ADC_ISMC_SP_POS_CTE		NAO
#define DBG_VAR_ADC_ISMC_SP_CTE			NAO
#define DBG_VAR_ADC_ISMC_POS_CTE		NAO

// Pid execution time
#define DBG_PID_EXEC_TIME				NAO
// Cr2 execution time
#define DBG_CR2_EXEC_TIME				NAO
// Ismc execution time
#define DBG_ISMC_EXEC_TIME				NAO
// Pid + Cr2 execution time
#define DBG_PID_CR2_EXEC_TIME			NAO
// Ismc + Cr2 execution time
#define DBG_ISMC_CR2_EXEC_TIME			NAO

// Trace serial
#define DBG_TRACE_SERIAL				NAO

#endif /* INC_COMMON_DEF_H_ */
