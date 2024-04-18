//==================================================================================
//==                                                                              ==
//== Adc module source                                                            ==
//==                                                                              ==
//==================================================================================

//==================================================================================
//== INCLUDES                                                                     ==
//==================================================================================
#include "adc.h"

//==================================================================================
//== PUBLIC VARIABLES                                                             ==
//==================================================================================
bool adc_data_ready = false;

//==================================================================================
//== PRIVATE VARIABLES                                                            ==
//==================================================================================
static uint8_t canal = 0;
static uint16_t adc_buf[ 3 ] = { 0 };

//==================================================================================
//== PRIVATE FUNCTIONS PROTOTYPES                                                 ==
//==================================================================================

//==================================================================================
//== PUBLIC FUNCTIONS                                                             ==
//==================================================================================
/**
 * @brief  Adc init
 */
void adc_init( void )
{
	adc_data_ready = false;

	HAL_ADC_Stop_IT( &hadc1 );

	// Run the ADC calibration in single-ended mode
	if ( HAL_ADCEx_Calibration_Start( &hadc1, ADC_CALIB_OFFSET, ADC_SINGLE_ENDED ) != HAL_OK ) {
		// Calibration Error
		Error_Handler();
	}

	HAL_ADC_Start_IT( &hadc1 );
}

/**
 * @brief  ADC IRQ handler for end of conversion and start of sampling
 */
void adc_handler( void )
{
    if ( __HAL_ADC_GET_FLAG( &hadc1, ADC_FLAG_EOC ) ) {
    	adc_buf[ canal ] = HAL_ADC_GetValue( &hadc1 );

        if ( __HAL_ADC_GET_FLAG( &hadc1, ADC_FLAG_EOS ) ) {
            canal = 0;
            adc_data_ready = true;
            // Adc full conversion time
#if ( DGB_ADC_CONV_TIME == SIM )
            HAL_GPIO_TogglePin(PIN_DEBUG_GPIO_Port, PIN_DEBUG_Pin);
#endif
        }
        else {
            canal++;
        }
    }
    __HAL_ADC_CLEAR_FLAG( &hadc1, ADC_FLAG_EOC );
    __HAL_ADC_CLEAR_FLAG( &hadc1, ADC_FLAG_EOS );
}

/**
 * @brief Adc readings getter function
 */
void adc_get_values( uint16_t *p_buf )
{
	*p_buf++ = adc_buf[ 0 ];
	*p_buf++ = adc_buf[ 1 ];
	*p_buf   = adc_buf[ 2 ];
}

/**
 * @brief Adc reading converted to voltage unit
 */
double adc_to_voltage( uint16_t adc_unities )
{
	double voltage;

	voltage = (adc_unities * ADC_MAX_VOLTAGE) / ADC_RANGE;
	return voltage;
}

//==================================================================================
//== PRIVATE FUNCTIONS                                                            ==
//==================================================================================
