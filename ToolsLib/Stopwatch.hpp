#pragma once

#include "pch.hpp"
#include <chrono>

namespace Tools
{
    class Stopwatch
    {
    private:
        std::chrono::steady_clock::time_point _start, _end;
        std::chrono::duration<double> _elapsed_seconds = std::chrono::duration<double>::zero();
        long long _elapsed_milliseconds = 0, _elapsed_nanoseconds = 0;

    public:
        void start();
        void end();
        double get_elapsed_seconds() const;
        long long get_elapsed_milliseconds() const;
        long long get_elapsed_nanoseconds() const;
    };
}