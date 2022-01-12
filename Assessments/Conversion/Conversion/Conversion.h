#ifndef INCLUDED_CONVERTION_H
#define INCLUDED_CONVERTION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

#define LUT_SIZE 91

/**
 * Base type definition of Look-Up-Table (LUT)
 *
 */
typedef struct
{
    uint16_t pressure_kpa_u16; // Pressure in kPa
    uint16_t adc_reading_u16; // ADC reading
} pressure_sensor_lut_st;

// Look-Up-Table (LUT) of the pressure sensor defined in LookUpTable.c
extern const pressure_sensor_lut_st presure_lut_sta[LUT_SIZE];

/**
 * @brief Get percentage of value in the range of min and max
 * 
 * @param low minimum value
 * @param high maximum value
 * @param value actual value
 * @return float 
 */
float normalize(uint16_t low, uint16_t high, uint16_t value);

/**
 * @brief Find the index of the LUT that has the closest value to the given value
 * 
 * @param adc_reading_u16 
 * @return int16_t 
 */
int16_t search_lut(uint16_t adc_reading_u16);

/**
 * @brief Get the pressure which corresponds to the given ADC reading
 * 
 * @param adc_reading_u16 
 * @return int16_t 
 */
int16_t get_pressure(uint16_t adc_reading_u16);

#ifdef __cplusplus
}
#endif

#endif // INCLUDED_CONVERTION_H