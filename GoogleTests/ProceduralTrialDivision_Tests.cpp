#include "pch.hpp"

namespace PrimalityTests
{
    TEST(ProceduralTrialDivisionTest, Zero)
    {
        bool result = Primality::IsPrime(0);

        EXPECT_EQ(false, result);
    }

    TEST(ProceduralTrialDivisionTest, Negative)
    {
        bool result = Primality::IsPrime(-2);

        EXPECT_EQ(false, result);
    }

    TEST(ProceduralTrialDivisionTest, RandomNegative)
    {
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<> distribution(-10000, -1);
        long randomNumber = distribution(generator);

        bool result = Primality::IsPrime(randomNumber);

        EXPECT_EQ(false, result);
    }

    TEST(ProceduralTrialDivisionTest, SomeEarlyPrimeNumbers)
    {
        std::vector<long> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 
            37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };

        for (auto& number : primes)
            EXPECT_EQ(true, Primality::IsPrime(number));
    }

    TEST(ProceduralTrialDivisionTest, SomeEarlyCompositeNumbers)
    {
        std::vector<long> primes = { 1, 4, 6, 8, 10, 12, 18, 20, 25, 30, 32,
            35, 42, 44, 45, 54, 58, 62, 69, 72, 75, 77, 81, 88, 99 };

        for (auto& number : primes)
            EXPECT_EQ(false, Primality::IsPrime(number));
    }
}