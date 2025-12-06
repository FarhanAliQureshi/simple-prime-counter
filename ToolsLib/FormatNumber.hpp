#pragma once

#include <string>
#include <sstream>

namespace Tools
{
    template <typename T>
    std::string FormatNumberWithSeparator(T value)
    {
        std::stringstream ss;
        ss.imbue(std::locale(""));
        ss << std::fixed << value;
        return ss.str();
    }
}