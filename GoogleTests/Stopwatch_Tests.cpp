#include "pch.hpp"

namespace ToolsTests
{
    TEST(StopwatchTest, InitializeToZero)
    {
        Tools::Stopwatch sw;

        auto seconds = sw.get_elapsed_seconds();
        auto milliseconds = sw.get_elapsed_milliseconds();
        auto nanoseconds = sw.get_elapsed_nanoseconds();

        EXPECT_EQ(0, seconds);
        EXPECT_EQ(0, milliseconds);
        EXPECT_EQ(0, nanoseconds);
    }

    TEST(StopwatchTest, EndWithoutStart)
    {
        Tools::Stopwatch sw;
        
        sw.end();
        auto seconds = sw.get_elapsed_seconds();
        auto milliseconds = sw.get_elapsed_milliseconds();
        auto nanoseconds = sw.get_elapsed_nanoseconds();

        EXPECT_EQ(0, seconds);
        EXPECT_EQ(0, milliseconds);
        EXPECT_EQ(0, nanoseconds);
    }

    TEST(StopwatchTest, ShortDurationTest)
    {
        Tools::Stopwatch sw;
        const int short_time = 1;

        sw.start();
        std::this_thread::sleep_for(std::chrono::milliseconds(short_time));
        sw.end();

        auto seconds = sw.get_elapsed_seconds();
        auto milliseconds = sw.get_elapsed_milliseconds();
        auto nanoseconds = sw.get_elapsed_nanoseconds();

        EXPECT_GE(seconds, short_time / 1000);
        EXPECT_GE(milliseconds, short_time);
        EXPECT_GE(nanoseconds, short_time * 1000000);
    }
}