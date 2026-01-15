#include "pch.hpp"
#include <iostream>
#include "../PrimalityLib/TrialDivision.hpp"
#include "../ToolsLib/Stopwatch.hpp"
#include "../ToolsLib/FormatNumber.hpp"

int main(void)
{
    std::cout << "Prime Counter - Single Threaded" << std::endl;

#ifdef _DEBUG
    long findPrimesUpto = 1000;
#else
    long findPrimesUpto = 20000000;
#endif

    long primesFound = 0;
    Tools::Stopwatch stopWatch;
    Primality::TrialDivision trialDivision;

    std::cout << "Finding primes up to " << Tools::FormatNumberWithSeparator(findPrimesUpto) << "..." << std::endl;
    stopWatch.start();
    
    for (long i = 0; i < findPrimesUpto; i++)
        if (trialDivision.IsPrime(i)) primesFound++;

    stopWatch.end();
    std::cout << "Found " << Tools::FormatNumberWithSeparator(primesFound) << " primes" << std::endl;
    std::cout << "Elapsed time: " << stopWatch.get_elapsed_seconds() << " seconds" << std::endl;

    return 0;
}