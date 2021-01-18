#pragma once

#include "log_level.h"

#include <string>

namespace classeine::core
{
    struct log_console_output
    {
        void write(
                log_level level,
                const std::string& context,
                const std::string& msg);
    };
}