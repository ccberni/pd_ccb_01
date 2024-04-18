//==================================================================================
//==                                                                              ==
//== Dac module header															  ==
//==                                                                              ==
//==================================================================================

//==================================================================================
//== INCLUDES                                                                     ==
//==================================================================================
#ifndef DAC_H
#define DAC_H

#include "common_def.h"

//==================================================================================
//== DEFINITIONS                                                                  ==
//==================================================================================
#define DAC_VREF				2500		// 2500 mV
#define DAC_RANGE				4095		// dac unities
#define DAC_MIN_VOLTAGE 		0.0			// 0.0 V
#define DAC_MAX_VOLTAGE 		10.0		// 10.0 V
#define DAC_MAX_LIMITED_VOLTAGE	8.5		 	// 8.5 V

// Importante: limiter de tens�o no dac, para
// evitar estrangulamento da v�lvula de grafite FV-11.
// Embora o patamar te�rico de 100% de fechamento seja 10V,
// com 8,33 V a v�lvula quase estrangula (regi�o linear).
#define USA_LIMITER_DAC			SIM

//==================================================================================
//== PUBLIC DATA TYPES                                                            ==
//==================================================================================

//==================================================================================
//== PUBLIC FUNCTIONS PROTOTYPES                                                  ==
//==================================================================================
// Init
void dac_init( void );
// Setter
void dac_set_value( uint16_t value );
// Conversion from voltage to dac unities
uint16_t dac_voltage_to_unities( double value );

//==================================================================================
//== PUBLIC VARIABLES (extern directive)                                          ==
//==================================================================================

//==================================================================================
//== MACROS                                                                       ==
//==================================================================================

#endif // DAC_H