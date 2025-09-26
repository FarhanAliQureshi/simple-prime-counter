#include "pch.hpp"
#include "TrialDivision.hpp"
#include <cmath>

namespace Primality
{
    bool TrialDivision::IsPrime(long number)
    {
        if (number < 2) return false;
        if (number % 2 == 0) return number == 2;

        long squareRoot = (long)std::sqrt(number);
        for (long i = 3; i <= squareRoot; i += 2)
            if (number % i == 0) return false;

        return true;
    }
}