#include "UnitTestLargeExponent.h"
#include <iostream>

using namespace Test;

TEST_F(TestLargeExponent, CheckIsDigitMethod)
{
    EXPECT_TRUE(isDigit("123"));
    EXPECT_TRUE(isDigit("0"));
    EXPECT_TRUE(isDigit("9999"));
    EXPECT_FALSE(isDigit("a"));
    EXPECT_FALSE(isDigit(""));
    EXPECT_FALSE(isDigit("-1"));
    EXPECT_FALSE(isDigit("-123"));
    EXPECT_FALSE(isDigit("-0"));
    EXPECT_FALSE(isDigit("-9999"));
}

TEST_F(TestLargeExponent, CheckInputMethod)
{
    EXPECT_FALSE(input("0"));
    EXPECT_TRUE(input("1"));
    EXPECT_TRUE(input("99999"));
    EXPECT_FALSE(input("100000"));
}

TEST_F(TestLargeExponent, CheckReverseMethod)
{
    EXPECT_EQ("123", reverse("321"));
    EXPECT_EQ("0", reverse("0"));
    EXPECT_EQ("9999", reverse("9999"));
    EXPECT_EQ("abc", reverse("cba"));
}

TEST_F(TestLargeExponent, CheckInitialiseBufferMethod)
{
    std::vector<int> expectedVector = { 5, 4, 3, 2, 1};

    m_base = 12345;

    initialiseBuffer();

    EXPECT_EQ(expectedVector, m_buffer);
    EXPECT_EQ(5, m_counter);
}

TEST_F(TestLargeExponent, CheckFinaliseBufferMethod)
{
    m_buffer = { 1, 2, 3, 4, 5};

    finaliseBuffer();

    EXPECT_EQ("54321", m_result);
}

TEST_F(TestLargeExponent, CheckBufferTransition)
{
    m_base = 12345;

    initialiseBuffer();
    finaliseBuffer();

    EXPECT_EQ("12345", m_result);
}

TEST_F(TestLargeExponent, CheckMultiplyMethodDifferentSize)
{
    /**
     * @brief Actual value is 123
     * 
     */
    std::vector<int> initialBuffer = { 3, 2, 1};
    std::vector<int> expectedBuffer = { 7, 0, 1, 1 };
    int initialSize = initialBuffer.size();
    int expectedSize = expectedBuffer.size();
    int multiplier = 9;

    int actualSize = multiply( multiplier, initialBuffer, initialSize);

    EXPECT_EQ(expectedSize, actualSize);
    EXPECT_EQ(expectedBuffer, initialBuffer);
}

TEST_F(TestLargeExponent, CheckMultiplyMethodBasic)
{
    /**
     * @brief Actual value is 10
     * 
     */
    std::vector<int> initialBuffer = { 0, 1};
    std::vector<int> expectedBuffer = { 0, 2 };
    int initialSize = initialBuffer.size();

    int actualSize = multiply(2, initialBuffer, initialSize);

    EXPECT_EQ(actualSize, initialSize);
    EXPECT_EQ(expectedBuffer, initialBuffer);
}

TEST_F(TestLargeExponent, CheckCalculateBufferMethodSameSize)
{
    std::vector<int> initialBuffer = { 2, 1 };
    std::vector<int> expectedBuffer = { 4, 2 };

    m_buffer = initialBuffer;
    m_base = 2;
    m_power = 2;
    m_counter = 2;
    
    calculateBuffer();

    EXPECT_EQ(expectedBuffer, m_buffer);
}

TEST_F(TestLargeExponent, CheckCalculateBufferMethodDifferentSize)
{
    std::vector<int> initialBuffer = { 9, 9 };
    std::vector<int> expectedBuffer = { 0, 9, 9 };

    m_buffer = initialBuffer;
    m_base = 10;
    m_power = 2;
    m_counter = 2;
    
    calculateBuffer();

    EXPECT_EQ(expectedBuffer, m_buffer);
}

TEST_F(TestLargeExponent, CheckCalculationMethod1)
{
    m_base = 2;
    m_power = 2;

    EXPECT_TRUE(calculate());

    EXPECT_EQ("4", m_result);
}

TEST_F(TestLargeExponent, CheckCalculationMethod2)
{
    m_base = 10;
    m_power = 5;

    EXPECT_TRUE(calculate());

    EXPECT_EQ("100000", m_result);
}

TEST_F(TestLargeExponent, CheckCalculationMethod3)
{
    m_base = 123;
    m_power = 5;

    EXPECT_TRUE(calculate());

    EXPECT_EQ("28153056843", m_result);
}

TEST_F(TestLargeExponent, CheckClass)
{
    std::string outputString;

    EXPECT_TRUE(input("12"));
    EXPECT_TRUE(calculate());
    EXPECT_TRUE(output(outputString));

    EXPECT_EQ(outputString, "46005119909369701466112");
}

TEST_F(TestLargeExponent, CheckClassFinal)
{
    std::string outputString;

    EXPECT_TRUE(input("123"));
    EXPECT_TRUE(calculate());
    EXPECT_TRUE(output(outputString));

    EXPECT_EQ(outputString, "72367033806371673149109894141163778628811792657571658906010558390395870363798401744095280686155507736404921657070284961721828960592977909542637098897697223102622628566787654091327825453991595140205701412961364188732408936197890553699715836951569999800431957769217006743321026257517932764164662319487914962533302741368207211189494615326552790667720411285474162636765168907211924134973374304496019635376665858559941735703924836467756917247995469583487467791524582153744522107597865277798136080074161485280424274076931083994487111719562249702540362855712911132265966235754355353516703339043001506118520760359577737869472018617942120590873170710805078696371738906375721785723");
}
