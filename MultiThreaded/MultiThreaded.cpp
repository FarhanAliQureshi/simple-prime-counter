#ifndef __STDCPP_THREADS__
#error "C++ Multi-threading is not available. Compilation aborted."
#endif

#if defined(_WIN32) || defined(_WIN64)
#pragma message("Platform: Windows")
#else
#pragma message("Platform: Not Windows")
#endif

#ifdef __GNUC__
#pragma message("Compiler: GCC")
#else
#ifdef _MSC_VER
#pragma message("Compiler: Visual C++")
#endif
#endif

#include "pch.hpp"
#include <iostream>
#include <mutex>
#include "../PrimalityLib/TrialDivision.hpp"
#include "../ToolsLib/Stopwatch.hpp"
#include "../ToolsLib/FormatNumber.hpp"

long m_findPrimesUpto = 0;
long m_currentNumber = 0;
long m_primesFound = 0;
std::mutex m_resourceAccess;
std::mutex m_resultAccess;

void workerThread();

void workerThread()
{
    long nextPrimeNumberCheck = 0;
    Primality::TrialDivision trialDivision;

    while (true)
    {
        {
            std::lock_guard<std::mutex> lock(m_resourceAccess);
            if (m_currentNumber > m_findPrimesUpto) break;
            nextPrimeNumberCheck = ++m_currentNumber;
        }

        if (trialDivision.IsPrime(nextPrimeNumberCheck))
        {
            std::lock_guard<std::mutex> lock(m_resultAccess);
            m_primesFound++;
        }
    }
}

int main()
{
    std::cout << "Prime Counter - Multi Threaded" << std::endl;

#ifdef _DEBUG
    m_findPrimesUpto = 1000;
#else
    m_findPrimesUpto = 20000000;
#endif

    int threadCount = std::thread::hardware_concurrency();
    Tools::Stopwatch stopWatch;
    std::cout << "Finding primes up to " << Tools::FormatNumberWithSeparator(m_findPrimesUpto) << " with " << threadCount << " threads..." << std::endl;

    stopWatch.start();
    std::vector<std::thread> threadPool;
    for (int i = 0; i < threadCount; ++i) 
    {
        threadPool.emplace_back(workerThread);
    }

    for (auto& t : threadPool)
        if (t.joinable()) t.join();

    stopWatch.end();
    std::cout << "Found " << Tools::FormatNumberWithSeparator(m_primesFound) << " primes" << std::endl;
    std::cout << "Elapsed time: " << stopWatch.get_elapsed_seconds() << " seconds" << std::endl;

    return 0;
}
