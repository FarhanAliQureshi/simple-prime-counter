#include "pch.hpp"
#include "framework.hpp"
#include "Stopwatch.hpp"

namespace Tools
{
    void Stopwatch::start()
    {
        _end = std::chrono::steady_clock::time_point();
        _elapsed_seconds = std::chrono::duration<double>::zero();
        _elapsed_milliseconds = 0;
        _elapsed_nanoseconds = 0;
        _start = std::chrono::high_resolution_clock::now();
    }

    void Stopwatch::end()
    {
        _end = std::chrono::high_resolution_clock::now();
        _elapsed_seconds = _end - _start;
        _elapsed_milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(_end - _start).count();
        _elapsed_nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(_end - _start).count();
    }

    double Stopwatch::get_elapsed_seconds()
    {
        return _elapsed_seconds.count();
    }

    long long Stopwatch::get_elapsed_milliseconds()
    {
        return _elapsed_milliseconds;
    }

    long long Stopwatch::get_elapsed_nanoseconds()
    {
        return _elapsed_nanoseconds;
    }
}