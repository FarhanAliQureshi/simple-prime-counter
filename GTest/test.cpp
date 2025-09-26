#include "pch.hpp"

namespace InternalTests 
{
    // This test should never fail.
    TEST(InternalTest, GenericTest) 
    {
        // Testing the Google Test itself (compile and execute test).
        EXPECT_EQ(1, 1);
        EXPECT_TRUE(true);
    }
}
