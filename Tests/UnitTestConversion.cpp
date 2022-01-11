#include "UnitTestConversion.h"

using namespace Test;

TEST_F(TestConversion, CheckSearchBoundaries)
{
    EXPECT_EQ(-1, search_lut(1695));
    EXPECT_NE(-1, search_lut(10000));
    EXPECT_EQ(-1, search_lut(14074));
}

TEST_F(TestConversion, CheckSearchResult)
{
    EXPECT_EQ(10, search_lut(3073 + 1));
    EXPECT_EQ(15, search_lut(3573 + 1));

    EXPECT_EQ(0, search_lut(1696 + 0));
    EXPECT_EQ(1, search_lut(1696 + 1));

    EXPECT_EQ(90, search_lut(14073 + 0));
    EXPECT_EQ(90, search_lut(14073 - 1));
}

TEST_F(TestConversion, CheckNormalize)
{
    EXPECT_FLOAT_EQ(0.5, normalize(0, 10, 5));
    EXPECT_FLOAT_EQ(0.25, normalize(0, 400, 100));
}

TEST_F(TestConversion, CheckGetPressure)
{
    EXPECT_NEAR(100, get_pressure(1696 + 5), 1);
    EXPECT_NEAR(430, get_pressure(5390 - 10), 2);
}