#include "Conversion/Conversion.h"

int16_t search_lut(uint16_t adc_reading_u16)
{
    // this function performs binary search on the LUT with the given ADC reading

    int16_t result = -1;

    // initialise the temparary indexes
    uint16_t low = 0;
    uint16_t mid = 0;
    uint16_t high = LUT_SIZE - 1;

    // if the given ADC reading is not in the range of the LUT
    if( (presure_lut_sta[high].adc_reading_u16 >= adc_reading_u16) &&
        (presure_lut_sta[low].adc_reading_u16 <= adc_reading_u16) )
    {
        while (low <= high)
        {
            // find the middle index
            mid = (low + high) / 2;

            // if the ADC reading is in the middle index
            if (presure_lut_sta[mid].adc_reading_u16 == adc_reading_u16)
            {   
                // the value if found in the middle index
                // immediately return the index
                return mid;
            }
            // check if the value is in the right side of buffer
            else if (presure_lut_sta[mid].adc_reading_u16 < adc_reading_u16)
            {
                low = mid + 1;
            }
            // then the value is in the left side of the middle index
            else 
            {
                high = mid - 1;
            }
        }

        // the value is not found in the LUT
        // therefore return the closest index
        result = (int16_t)(low);

    }
    
    return result;
}

float normalize(uint16_t low, uint16_t high, uint16_t value)
{
    float result = 0;

    // if the divisor is zero
    if(high - low > 0)
    {
        // scale the value to the range of 0 to 1
        result = (float)(value - low) / (float)(high - low);
    }
    else {}

    return result;
}

int16_t get_pressure(uint16_t adc_reading_u16)
{
    int16_t result = -1;

    // find the index of the LUT that has the closest value to the given ADC reading
    int16_t foundIndex = search_lut(adc_reading_u16);

    // if the index is valid
    if( foundIndex >= 0)
    {
        // check if the value is actually on the LUT
        if(presure_lut_sta[foundIndex].adc_reading_u16 == adc_reading_u16)
        {
            result = (int16_t)(presure_lut_sta[foundIndex].pressure_kpa_u16);
        }
        // otherwise, the value is not on the LUT
        // perform basic linear interpolation
        else
        {
            // get the closest pressure values high and low which on the LUT
            // scale the ADC value to the range of 0 to 1 
            float normalized = normalize(
                presure_lut_sta[foundIndex - 1].adc_reading_u16,
                presure_lut_sta[foundIndex].adc_reading_u16,
                adc_reading_u16
                );
            
            // get the pressure value using weighted average
            result = (int16_t)((normalized) * (float)presure_lut_sta[foundIndex].pressure_kpa_u16)
                   + (int16_t)((1.0 - normalized) * (float)presure_lut_sta[foundIndex - 1].pressure_kpa_u16);

        }
    }
    else {}

    return result;
}