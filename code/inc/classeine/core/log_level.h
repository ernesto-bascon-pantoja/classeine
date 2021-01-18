#pragma once

#include <string_view>

namespace classeine::core
{
    enum class log_level
    {
        error = 0,
        warning = 1,
        info = 2,
        debug = 3
    };

    std::string_view to_string(log_level level);
}