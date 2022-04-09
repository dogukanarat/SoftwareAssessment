/**
 * @file LargeExponent.cpp
 * @author Dogukan Fikri Arat
 * @brief 
 * @version 0.1
 * @date 2022-01-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <algorithm>
#include "LargeExponent/LargeExponent.h"

using namespace RocketLab;

LargeExponent::LargeExponent()
    : m_counter{0}
    , m_base{0}
    , m_power{0}
{
    // Nothing to do here
}

bool LargeExponent::isDigit(std::string input)
{
    bool result = false;

    if (input.empty())
    {
        // if the input is empty, it is an error
        result =  false;
    }
    else
    {
        // if the each character of the input is a digit, the string is all digit
        result = std::all_of(input.begin(), input.end(), [](char c)
        {
            return c >= '0' && c <= '9';
        });
    }
    return result;
}

std::string LargeExponent::reverse(std::string input)
{
    // copy of the given input to the temporary string
    std::string result = input;

    // reverse the string
    std::reverse(result.begin(), result.end());

    return result;
}

bool LargeExponent::input(std::string input)
{
    bool result = false;

    if(isDigit(input))
    {
        // convert the input to integer
        int tempInput = std::stoi(input);

        // if the input is a positive integer and 
        // within the given range, which is given in 
        // the problem statement
        if(tempInput > 0 && tempInput <= 99999)
        {   
            // copy the input to the member variable
            m_input = input;

            // set the base
            m_base = tempInput;

            // set the power to reversed input
            m_power = std::stoi(reverse(input));

            result = true;
        }
        else
        {
            result = false;
        }
    }
    else
    {
        result = false;
    }

    return result;
}

void LargeExponent::initialiseBuffer()
{
    // copy the base to the temporary variable
    int tempBase = m_base;

    for(int index = 0; tempBase != 0; index++)
    {
        // push the each digit of the base to the buffer
        m_buffer.push_back(tempBase % 10);

        // find the rest of digit of the base
        tempBase = tempBase / 10;
    }

    // set the counter to the size of the buffer
    m_counter = m_buffer.size();
}

void LargeExponent::finaliseBuffer()
{
    std::string streamResult;

    for (auto it = m_buffer.rbegin(); it != m_buffer.rend(); ++it)
    {
        // append the each digit of the buffer to the result string
        streamResult.append(std::to_string(*it));
    }

    // copy the result string to the result member variable
    m_result = streamResult;
}

void LargeExponent::calculateBuffer()
{
    // @note : counter is started from 2 since the buffer is already initialised
    for(int counter = 2; counter <= m_power; counter++)
    {
        // multiply the buffer with the buffer itself time base
        m_counter = multiply(m_base, m_buffer, m_counter);
    }
}

bool LargeExponent::calculate()
{
    bool result = false;

    // if the base valid
    if(m_base > 0)
    {
        // initialise the buffer
        initialiseBuffer();

        // do the multiplication
        calculateBuffer();

        // set the output
        finaliseBuffer();

        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}

bool LargeExponent::output(std::string& output)
{
    bool result = false;

    if(m_buffer.size() > 0)
    {
        // copy the result to the output
        output = m_result;
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}

int LargeExponent::multiply(int base, std::vector<int>& buffer, int size)
{
    // note : this function is simply an implementation of paper and pencil method
    int carry = 0;

    std::vector<int> resultBuffer;

    for (int index = 0; index < size; index++)
    {
        // multiply the base with the digit of the buffer and add previous carry
        int product = buffer[index] * base + carry;
    
        // set the product of module 10 to the result buffer
        resultBuffer.push_back(product % 10);
    
        // find the carry for next iteration
        carry = product / 10;
    }
 
    // if the carry is still there
    while (carry)
    {
        // add the carry to the result buffer
        resultBuffer.push_back(carry % 10);

        // find the carry for next iteration
        carry = carry / 10;

        size++;
    }

    // set the result buffer to output buffer with assign method
    // since the result might have different size than the buffer
    buffer.assign(resultBuffer.begin(), resultBuffer.end());

    return size;
}
