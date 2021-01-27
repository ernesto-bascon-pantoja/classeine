#pragma once

#include "log_level.h"

#include <string>

namespace classeine::core
{
    template <typename T>
    concept CLogOutput = requires(T t, log_level level, std::string& context, std::string& msg)
    {
        { t.write(level, context, msg) } -> std::convertible_to<void>;
    };
}