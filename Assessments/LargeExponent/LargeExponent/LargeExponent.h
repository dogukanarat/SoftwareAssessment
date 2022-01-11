#ifndef INCLUDED_BIGEXPONENTIAL_H
#define INCLUDED_BIGEXPONENTIAL_H

#include <string>
#include <iostream>
#include <vector>
#include <ctype.h>

#define MAX_DIGITS 9999

namespace RocketLab
{
    class LargeExponent
    {
    public:
        LargeExponent();
        virtual ~LargeExponent() = default;

        bool input(std::string input);
        bool output(std::string& output);
        bool calculate();

    protected:
        void initialiseBuffer();
        void finaliseBuffer();
        void calculateBuffer();
        int multiply(int base, std::vector<int>& buffer, int size);
        bool isDigit(std::string input);
        std::string reverse(std::string input);

        std::string m_input;
        std::vector<int> m_buffer;
        std::string m_result;
        int m_counter;
        int m_base;
        int m_power;
    };
}

#endif // INCLUDED_BIGEXPONENTIAL_H