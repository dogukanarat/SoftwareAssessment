#include "Conversion/Conversion.h"

extern pressure_sensor_lut_st presure_lut_sta[];

int16_t search_lut(uint16_t adc_reading_u16)
{
    int16_t result = -1;

    uint16_t low = 0;
    uint16_t mid = 0;
    uint16_t high = LUT_SIZE - 1;

    if( (presure_lut_sta[high].adc_reading_u16 >= adc_reading_u16) &&
        (presure_lut_sta[low].adc_reading_u16 <= adc_reading_u16) )
    {
        while (low <= high)
        {
            mid = (low + high) / 2;

            if (presure_lut_sta[mid].adc_reading_u16 == adc_reading_u16)
            {
                return mid;
            }
            else if (presure_lut_sta[mid].adc_reading_u16 < adc_reading_u16)
            {
                low = mid + 1;
            } 
            else 
            {
                high = mid - 1;
            }
        }

        result = (int16_t)(low);

    }
    
    return result;
}

float normalize(uint16_t low, uint16_t high, uint16_t value)
{
    float result = 0;

    if(high - low > 0)
    {
        result = (float)(value - low) / (float)(high - low);
    }
    else {}

    return result;
}
int16_t get_pressure(uint16_t adc_reading_u16)
{
    int16_t result = -1;
    int16_t foundIndex = search_lut(adc_reading_u16);

    if( foundIndex >= 0)
    {
        if(presure_lut_sta[foundIndex].adc_reading_u16 == adc_reading_u16)
        {
            result = (int16_t)(presure_lut_sta[foundIndex].pressure_kpa_u16);
        }
        else
        {
            float normalized = normalize(
                presure_lut_sta[foundIndex - 1].adc_reading_u16,
                presure_lut_sta[foundIndex].adc_reading_u16,
                adc_reading_u16
                );
            
            result = (int16_t)((normalized) * (float)presure_lut_sta[foundIndex].pressure_kpa_u16)
                   + (int16_t)((1.0 - normalized) * (float)presure_lut_sta[foundIndex - 1].pressure_kpa_u16);

        }
    }
    else {}

    return result;
}