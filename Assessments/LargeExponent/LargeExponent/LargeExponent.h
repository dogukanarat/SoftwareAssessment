/**
 * @file LargeExponent.h
 * @author Dogukan Fikri Arat
 * @brief 
 * @version 0.1
 * @date 2022-01-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef INCLUDED_BIGEXPONENTIAL_H
#define INCLUDED_BIGEXPONENTIAL_H

#include <string>
#include <iostream>
#include <vector>
#include <ctype.h>

namespace RocketLab
{
    /**
     * @brief The BigExponential class
     * 
     */
    class LargeExponent
    {
    public:
        /**
         * @brief Construct a new Large Exponent object
         * 
         */
        LargeExponent();

        /**
         * @brief Destroy the Large Exponent object
         * 
         */
        virtual ~LargeExponent() = default;

        /**
         * @brief Check if the input is valid
         * 
         * @param input : input string
         * @return true if the input is valid otherwise false
         */
        bool input(std::string input);

        /**
         * @brief Set the output string with the answer
         * 
         * @return true if the output is ready otherwise false
         */
        bool output(std::string& output);

        /**
         * @brief Do the calculation
         * 
         * @return true if the calculation succeed otherwise false
         */
        bool calculate();

    protected:
        /**
         * @brief Initialise the buffer with the given input string
         * 
         */
        void initialiseBuffer();

        /**
         * @brief Finalise the buffer setting the output string
         * 
         */
        void finaliseBuffer();

        /**
         * @brief Finalise the buffer setting the output string
         * 
         */
        void calculateBuffer();

        /**
         * @brief Multiply the given base with the given buffer
         * 
         * @param base : base to multiply
         * @param buffer : buffer to multiply
         * @param size : counter of the buffer
         * @return int : counter of the buffer
         */
        int multiply(int base, std::vector<int>& buffer, int size);

        /**
         * @brief Check if the input parameter is all digits
         * 
         * @param input : input string
         * @return true if the input is all digit otherwise false
         */
        bool isDigit(std::string input);

        /**
         * @brief Reverse the given input parameter
         * 
         * @param input : input string
         * @return string : reversed input string
         */
        std::string reverse(std::string input);

        /**
         * @brief User input string
         * 
         */
        std::string m_input;

        /**
         * @brief Result of multiplication buffer
         * 
         */
        std::vector<int> m_buffer;

        /**
         * @brief Result string
         * 
         */
        std::string m_result;

        /**
         * @brief Counter of the buffer
         * 
         */
        int m_counter;

        /**
         * @brief Base of exponent
         * 
         */
        int m_base;

        /**
         * @brief power of exponent
         * 
         */
        int m_power;
    };
}

#endif // INCLUDED_BIGEXPONENTIAL_H