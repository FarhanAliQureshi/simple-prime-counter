#include "pch.hpp"
#include <chrono>

namespace Tools
{
    class Stopwatch
    {
    private:
        std::chrono::steady_clock::time_point _start, _end;
        std::chrono::duration<double> _elapsed_seconds;
        long long _elapsed_milliseconds, _elapsed_nanoseconds;
    public:
        void start();
        void end();
        double get_elapsed_seconds();
        long long get_elapsed_milliseconds();
        long long get_elapsed_nanoseconds();
    };
}