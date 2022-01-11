#include "LargeExponent/LargeExponent.h"

using namespace RocketLab;

LargeExponent::LargeExponent()
    : m_counter{0}
    , m_base{0}
    , m_power{0}
{}

bool LargeExponent::isDigit(std::string input)
{
    bool result = false;

    if (input.empty())
    {
        result =  false;
    }
    else
    {
        result = std::all_of(input.begin(), input.end(), [](char c)
        {
            return c >= '0' && c <= '9';
        });
    }
    return result;
}

std::string LargeExponent::reverse(std::string input)
{
    std::string result = input;

    std::reverse(result.begin(), result.end());

    return result;
}

bool LargeExponent::input(std::string input)
{
    bool result = false;

    if( isDigit(input))
    {
        int tempInput = std::stoi(input);

        if(tempInput > 0 && tempInput <= 99999)
        {   
            m_input = input;
            m_base = tempInput;
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
    int tempBase = m_base;

    for(int index = 0; tempBase != 0; index++)
    {
        m_buffer.push_back(tempBase % 10);
        tempBase = tempBase / 10;
    }

    m_counter = m_buffer.size();
}

void LargeExponent::finaliseBuffer()
{
    std::string streamResult;

    for (auto it = m_buffer.rbegin(); it != m_buffer.rend(); ++it)
    {
        streamResult.append(std::to_string(*it));
    }

    m_result = streamResult;
}

void LargeExponent::calculateBuffer()
{
    for(int counter = 2; counter <= m_power; counter++)
    {
        m_counter = multiply(m_base, m_buffer, m_counter);
    }
}

bool LargeExponent::calculate()
{
    bool result = false;

    if(m_base > 0)
    {
        initialiseBuffer();

        calculateBuffer();

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
    int carry = 0;

    std::vector<int> resultBuffer;

    for (int index = 0; index < size; index++)
    {
        int product = buffer[index] * base + carry;
    
        resultBuffer.push_back(product % 10);
    
        carry = product / 10;
    }
 
    while (carry)
    {
        resultBuffer.push_back(carry % 10);

        carry = carry / 10;

        size++;
    }

    buffer.assign(resultBuffer.begin(), resultBuffer.end());

    return size;
}
