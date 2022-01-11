#include <gtest/gtest.h>
#include "LargeExponent/LargeExponent.h"

namespace Test
{
    class TestLargeExponent : public ::testing::Test, public RocketLab::LargeExponent
    {
    protected:

        TestLargeExponent()
        {
        }

        ~TestLargeExponent() override
        {
        }

        void SetUp() override
        {
        }

        void TearDown() override
        {
        }

    };
}
