//==================================================================================
//==                                                                              ==
//== Timer module header														  ==
//==                                                                              ==
//==================================================================================

//==================================================================================
//== INCLUDES                                                                     ==
//==================================================================================
#ifndef TIMER_H
#define TIMER_H

#include "common_def.h"

//==================================================================================
//== DEFINITIONS                                                                  ==
//==================================================================================

//==================================================================================
//== PUBLIC DATA TYPES                                                            ==
//==================================================================================

//==================================================================================
//== PUBLIC FUNCTIONS PROTOTYPES                                                  ==
//==================================================================================
void timer_init( void );
void timer_counting_bases( void );

//==================================================================================
//== PUBLIC VARIABLES (extern directive)                                          ==
//==================================================================================
extern bool tmr_1ms;
extern bool tmr_10ms;
extern bool tmr_100ms;
extern bool tmr_1000ms;

//==================================================================================
//== MACROS                                                                       ==
//==================================================================================

#endif // TIMER_H
