#ifndef INCLUDED_CONVERTION_H
#define INCLUDED_CONVERTION_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>

#define LUT_SIZE 91

typedef struct
{
    uint16_t pressure_kpa_u16;
    uint16_t adc_reading_u16;
} pressure_sensor_lut_st;

float normalize(uint16_t low, uint16_t high, uint16_t value);
int16_t search_lut(uint16_t adc_reading_u16);
int16_t get_pressure(uint16_t adc_reading_u16);

#ifdef __cplusplus
}
#endif

#endif // INCLUDED_CONVERTION_H