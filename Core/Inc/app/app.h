//==================================================================================
//==                                                                              ==
//== App logic header                                                             ==
//==                                                                              ==
//==================================================================================

//==================================================================================
//== INCLUDES                                                                     ==
//==================================================================================
#ifndef APP_H
#define APP_H

#include "common_def.h"
#include "params.h"

// App modules
#include "adc.h"
#include "dac.h"
#include "timer.h"
#include "serial.h"

#include "rtwtypes.h"
#include "pid_code_types.h"
#include "ismc_code_types.h"
#include "cr2_code_types.h"
#include "lpf_i1_types.h"
#include "lpf_i2_types.h"
#include "lpf_i3_types.h"
#include "lpf_o1_types.h"

#include "rt_nonfinite.h"

#include "pid_code_initialize.h"
#include "pid_code.h"
#include "pid_code_terminate.h"

#include "ismc_code_initialize.h"
#include "ismc_code.h"
#include "ismc_code_terminate.h"

#include "cr2_code_initialize.h"
#include "cr2_code.h"
#include "cr2_code_terminate.h"

#include "lpf_i1_initialize.h"
#include "lpf_i1.h"
#include "lpf_i1_terminate.h"

#include "lpf_i2_initialize.h"
#include "lpf_i2.h"
#include "lpf_i2_terminate.h"

#include "lpf_i3_initialize.h"
#include "lpf_i3.h"
#include "lpf_i3_terminate.h"

#include "lpf_o1_initialize.h"
#include "lpf_o1.h"
#include "lpf_o1_terminate.h"

//==================================================================================
//== DEFINITIONS                                                                  ==
//==================================================================================
// Lpf filter usage for iscm i1 input (position)
#define ISMC_LPF_INPUT_I1	NAO
// Lpf filter usage for iscm output
#define ISMC_LPF_OUTPUT		NAO

//==================================================================================
//== DATA TYPES                                                                   ==
//==================================================================================
typedef struct an_data_t {
	double i1;
	double i1f;
	double i2;
	double i2f;
	double i3;
	double i3f;
	double o1;
	double o1f;
} an_data;

//==================================================================================
//== PUBLIC FUNCTIONS PROTOTYPES                                                  ==
//==================================================================================
void app_setup( void );
void app_loop( void );

//==================================================================================
//== VARIABLES (extern directive)                                                 ==
//==================================================================================

//==================================================================================
//== MACROS                                                                       ==
//==================================================================================

#endif // APP_H
