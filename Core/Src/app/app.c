//==================================================================================
//==                                                                              ==
//== App logic source                                                             ==
//==                                                                              ==
//==================================================================================

//==================================================================================
//== INCLUDES                                                                     ==
//==================================================================================
#include "app.h"

//==================================================================================
//== GLOBAL APP VARIABLES                                                         ==
//==================================================================================
// Analog data - internal ctr algorithms
an_data		data;
// Adc readings buffer
uint16_t	adc_value[ 3 ] = { 0 };
// Dac writing buffer
uint16_t	dac_value = 0 ;
// Serial trace buffer
char		buf_tx[ 70 ] = { 0 };
// Button state
bool		bt_pressed = false;
// Selected algorithm number
uint8_t		sel_alg;
// Mode state: stop (false) / run (true)
bool		mode  = false;

//==================================================================================
//== PRIVATE FUNCTIONS PROTOTYPES                                                 ==
//==================================================================================
static void app_init( void );
static void mode_read( void );
static void app_bt_alg_selection( void );
static double sm_pid( double sp, double x );
static double sm_ismc( double sp, double x );
static double sm_cr2( double e );

//==================================================================================
//== PUBLIC FUNCTIONS                                                             ==
//==================================================================================
void app_setup( void )
{
	// Init dac
	dac_init();

	// Init adc - isr + conversion triggered by tmr1 @ 1 ms
	adc_init();

	// Init timer
	timer_init();

	// App init
	app_init();
}

void app_loop( void )
{
	volatile double cr2_i = 0;
	volatile double cr2_o = 0;

	//! [Tasks with no time base - highest priority]

	//! [Adc readings]
	if ( adc_data_ready ) {
		adc_data_ready = 0;
		adc_get_values( adc_value );
	}
	//! [Adc readings]


	//! [Tasks with no time base - highest priority]

	//! [Tasks with 1 ms time base]
	if ( tmr_1ms ) {
		tmr_1ms = 0;

		//!	[Ctr algorithm]
		// Inputs update
		data.i1 = adc_to_voltage( adc_value[ 0 ] );
		data.i2 = adc_to_voltage( adc_value[ 1 ] );
		data.i3 = adc_to_voltage( adc_value[ 2 ] );

		// Ctr alg selection
		switch ( sel_alg ) {

		// None - keep output quiet (= 0)
		case 0:
			data.o1 = 0;
			break;

		// Bypass - transfer input i2 to output o1
		// i2 is the set-point from PI-Flow to pid and ismc
		case 1:
			if ( mode ) {
				data.o1 = data.i2;
			}
			else {
				data.o1 = 0;
			}
			break;

		// Pid
		case 2:
			// Pid execution time
#if ( DBG_PID_EXEC_TIME == SIM )
			HAL_GPIO_WritePin(PIN_DEBUG_GPIO_Port, PIN_DEBUG_Pin, GPIO_PIN_SET);
#endif
			data.o1 = sm_pid( data.i2, data.i1 );
			// Pid execution time
#if ( DBG_PID_EXEC_TIME == SIM )
			HAL_GPIO_WritePin(PIN_DEBUG_GPIO_Port, PIN_DEBUG_Pin, GPIO_PIN_RESET);
#endif
			break;

		// Ismc
		case 3:
			// Ismc execution time
#if ( DBG_ISMC_EXEC_TIME == SIM )
			HAL_GPIO_WritePin(PIN_DEBUG_GPIO_Port, PIN_DEBUG_Pin, GPIO_PIN_SET);
#endif
			// Lpf - input i1
#if ( ISMC_LPF_INPUT_I1 == SIM )
			data.i1f = lpf_i1( data.i1 );
#else
			data.i1f = data.i1;
#endif
			// Evaluation of ismc variability when using adc measurements
#if ( DBG_VAR_ADC_ISMC_SP_POS_CTE == SIM )
			data.o1 = sm_ismc( 4.0, 4.0 );
#elif ( DBG_VAR_ADC_ISMC_SP_CTE == SIM )
			data.o1 = sm_ismc( 4.0, data.i1f );
#elif ( DBG_VAR_ADC_ISMC_POS_CTE == SIM )
			data.o1 = sm_ismc( data.i2, 4.0 );
#else
			data.o1 = sm_ismc( data.i2, data.i1f );
#endif
			// Lpf - output
#if ( ISMC_LPF_OUTPUT == SIM )
			data.o1f = lpf_o1( data.o1 );
			data.o1  = data.o1f;
#endif
			// Ismc execution time
#if ( DBG_ISMC_EXEC_TIME == SIM )
			HAL_GPIO_WritePin(PIN_DEBUG_GPIO_Port, PIN_DEBUG_Pin, GPIO_PIN_RESET);
#endif
			break;

		// Cr2
		case 4:
			// Cr2 execution time
#if ( DBG_CR2_EXEC_TIME == SIM )
			HAL_GPIO_WritePin(PIN_DEBUG_GPIO_Port, PIN_DEBUG_Pin, GPIO_PIN_SET);
#endif
			// Cr2 input conditioning (m3/h)
			cr2_i = ( data.i3 * 3.6 ) - 18;
			// Cr2 alg
			cr2_o = sm_cr2( cr2_i );
			// Cr2 output conditioning --> % to voltage
			if ( mode ) {
				data.o1 = ( cr2_o + ( CR2_S / 2 ) ) * DAC_MAX_VOLTAGE;
			}
			else {
				data.o1 = 0;
			}
			// Cr2 execution time
#if ( DBG_CR2_EXEC_TIME == SIM )
			HAL_GPIO_WritePin(PIN_DEBUG_GPIO_Port, PIN_DEBUG_Pin, GPIO_PIN_RESET);
#endif
			break;

		// Pid + Cr2
		case 5:
			// Pid + cr2 execution time
#if ( DBG_PID_CR2_EXEC_TIME == SIM )
			HAL_GPIO_WritePin(PIN_DEBUG_GPIO_Port, PIN_DEBUG_Pin, GPIO_PIN_SET);
#endif
			// Input conditioning (m3/h)
			cr2_i = ( data.i3 * 3.6 ) - 18;
			// Cr2 alg
			cr2_o = sm_cr2( cr2_i );
			// Cr2 output conditioning --> % to voltage
			cr2_o = cr2_o * DAC_MAX_VOLTAGE;
			// Pid alg
			data.o1 = sm_pid( ( data.i2 + cr2_o ), data.i1 );
			// Pid + cr2 execution time
#if ( DBG_PID_CR2_EXEC_TIME == SIM )
			HAL_GPIO_WritePin(PIN_DEBUG_GPIO_Port, PIN_DEBUG_Pin, GPIO_PIN_RESET);
#endif
			break;

		// Ismc + Cr2
		case 6:
			// Ismc + cr2 execution time
#if ( DBG_ISMC_CR2_EXEC_TIME == SIM )
			HAL_GPIO_WritePin(PIN_DEBUG_GPIO_Port, PIN_DEBUG_Pin, GPIO_PIN_SET);
#endif
			// Input conditioning (m3/h)
			cr2_i = ( data.i3 * 3.6 ) - 18;
			// Cr2 alg
			cr2_o = sm_cr2( cr2_i );
			// Cr2 output conditioning --> % to voltage
			cr2_o = cr2_o * DAC_MAX_VOLTAGE;
			// Ismc alg
			// Lpf - inputs
#if ( ISMC_LPF_INPUT_I1 == SIM )
			data.i1f = lpf_i1( data.i1 );
#else
			data.i1f = data.i1;
#endif
			data.o1 = sm_ismc( ( data.i2 + cr2_o ), data.i1f );
#if ( ISMC_LPF_OUTPUT == SIM )
			data.o1f = lpf_o1( data.o1 );
			data.o1  = data.o1f;
#endif
			// Ismc + cr2 execution time
#if ( DBG_ISMC_CR2_EXEC_TIME == SIM )
			HAL_GPIO_WritePin(PIN_DEBUG_GPIO_Port, PIN_DEBUG_Pin, GPIO_PIN_RESET);
#endif
			break;

		// (Fractional Pid?)
		case 7:
			break;

		default:
			break;
		}

		// Output update
		dac_value = dac_voltage_to_unities( data.o1 );
		dac_set_value( dac_value );
		//!	[Ctr algorithm]
	}
	//! [Tasks with 1 ms time base]

	//! [Tasks with 10 ms time base]
	if ( tmr_10ms ) {
		tmr_10ms = 0;
	}
	//! [Tasks with 10 ms time base]

	//! [Tasks with 100 ms time base]
	if ( tmr_100ms ) {
		tmr_100ms = 0;

		//! [Mode stop/run reading]
		mode_read();
		//! [Mode stop/run reading]

		//! [Ctr alg button select]
		app_bt_alg_selection();
		//! [Ctr alg button select]
	}
	//! [Tasks with 100 ms time base]

	//! [Tasks with 1000 ms time base - lowest priority]
	if ( tmr_1000ms ) {
		tmr_1000ms = 0;

#if( DBG_TRACE_SERIAL == SIM )
		//! [Serial analog inputs print]
		snprintf( buf_tx, 70, "I1-cpu: %.2f V, I2-cpu: %.2f V, I3-cpu: %.2f V, O1-cpu: %.2f V\r\n", \
				  data.i1, data.i2, data.i3, data.o1 );
		HAL_UART_Transmit( &huart3, (uint8_t *)buf_tx, 64, 100 );
		//! [Serial analog inputs print]
#endif
	}
	//! [Tasks with 1000 ms time base - lowest priority]
}

//==================================================================================
//== PRIVATE FUNCTIONS                                                            ==
//==================================================================================
/**
 * @brief App init function
 */
static void app_init( void )
{
	data.i1  = 0;
	data.i1f = 0;
	data.i2  = 0;
	data.i2f = 0;
	data.i3  = 0;
	data.i3f = 0;
	data.o1  = 0;
	data.o1f = 0;

	bt_pressed	= false;
	sel_alg		= 0;
	mode 		= false;

	lpf_i1_initialize();
	lpf_i2_initialize();
	lpf_i3_initialize();
	lpf_o1_initialize();
}

/**
 * @brief App button algorithm selection, with leds indication
 */
static void app_bt_alg_selection( void )
{
	if ( !mode ) {
		if ( !bt_pressed ) {
			// Button pressed
			if ( HAL_GPIO_ReadPin( B1_GPIO_Port, B1_Pin ) ) {
				bt_pressed = true;
				// Increase alg number
				sel_alg++;
				if ( sel_alg > 7 ) {
					sel_alg = 0;
				}
			}
		}

		// Button released
		if ( !HAL_GPIO_ReadPin( B1_GPIO_Port, B1_Pin ) ) {
			bt_pressed = false;
		}

		// Leds indication
		HAL_GPIO_WritePin( LD1_GPIO_Port, LD1_Pin, (sel_alg & 0x01) );
		HAL_GPIO_WritePin( LD2_GPIO_Port, LD2_Pin, (sel_alg & 0x02) );
		HAL_GPIO_WritePin( LD3_GPIO_Port, LD3_Pin, (sel_alg & 0x04) );
	}
}

/**
 * @brief Mode (stop/run) read
 */
static void mode_read( void )
{
	// Input open ('1') = stop mode
	if ( HAL_GPIO_ReadPin( BT_RUN_GPIO_Port, BT_RUN_Pin ) ) {
		HAL_GPIO_WritePin( LD_RUN_GPIO_Port, LD_RUN_Pin, 0 );
		mode = false;
	}
	// Input open ('0') = run mode
	else {
		HAL_GPIO_WritePin( LD_RUN_GPIO_Port, LD_RUN_Pin, 1 );
		mode = true;
	}
}

/**
 * @brief Pid ctr alg state machine
 */
static double sm_pid( double sp, double x )
{
	static double u;

	const static double param[7] = {
			PID_KP,
			PID_TI,
			PID_TD,
			PID_N,
			TS,
			PID_SAT,
			PID_TT
	};

	static volatile enum {
        SM_PID_RST = 0,
        SM_PID_START,
        SM_PID_RUN,
        SM_PID_STOP
    } sm = SM_PID_RST;

    switch( sm ) {

    case SM_PID_RST:
    	u = 0;
    	sm = SM_PID_START;
    	break;

    case SM_PID_START:
    	pid_code_initialize();
    	if ( mode ) {
    		sm = SM_PID_RUN;
    	}
    	break;

    case SM_PID_RUN:
    	 u = pid_code( sp, x, param );
    	 if ( !mode ) {
    		 sm = SM_PID_STOP;
    	 }
    	break;

    case SM_PID_STOP:
    	u = 0;
    	pid_code_terminate();
    	sm = SM_PID_RST;
    	break;

    default:
		break;
	}

    return u;
}

/**
 * @brief Ismc ctr alg state machine
 */
static double sm_ismc( double sp, double x )
{
	static double u;

	const static double param[13] = {
			KP,
			SA,
			K,
			FC,
			FS,
			VS,
			SIGMA,
			M,
			ISMC_LAMBDA,
			ISMC_PHI,
			ISMC_KC,
			TS,
			ISMC_SAT
	};

	static volatile enum {
        SM_ISMC_RST = 0,
        SM_ISMC_START,
        SM_ISMC_RUN,
        SM_ISMC_STOP
    } sm = SM_ISMC_RST;

    switch( sm ) {

    case SM_ISMC_RST:
    	u = 0;
    	sm = SM_ISMC_START;
    	break;

    case SM_ISMC_START:
    	ismc_code_initialize();
    	if ( mode ) {
    		sm = SM_ISMC_RUN;
    	}
    	break;

    case SM_ISMC_RUN:
    	 u = ismc_code( sp, x, param );
    	 if ( !mode ) {
    		 sm = SM_ISMC_STOP;
    	 }
    	break;

    case SM_ISMC_STOP:
    	u = 0;
    	ismc_code_terminate();
    	sm = SM_ISMC_RST;
    	break;

    default:
		break;
	}

    return u;
}

/**
 * @brief Cr2 ctr alg state machine
 */
static double sm_cr2( double e )
{
	static double u;

	const static double param[5] = {
			CR2_S,
			CR2_TI,
			CR2_TO,
			CR2_DT,
			TS
	};

	static volatile enum {
        SM_CR2_RST = 0,
        SM_CR2_START,
        SM_CR2_RUN,
        SM_CR2_STOP
    } sm = SM_CR2_RST;

    switch( sm ) {

    case SM_CR2_RST:
    	u = 0;
    	sm = SM_CR2_START;
    	break;

    case SM_CR2_START:
    	cr2_code_initialize();
    	if ( mode ) {
    		sm = SM_CR2_RUN;
    	}
    	break;

    case SM_CR2_RUN:
    	 u = cr2_code( e, param );
    	 if ( !mode ) {
    		 sm = SM_CR2_STOP;
    	 }
    	break;

    case SM_CR2_STOP:
    	u = 0;
    	cr2_code_terminate();
    	sm = SM_CR2_RST;
    	break;

    default:
		break;
	}

    return u;
}
