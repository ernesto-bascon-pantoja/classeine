#pragma once

#include "log_level.h"

#include <string>

namespace classeine::core
{
    struct log_console_output
    {
        log_console_output() = default;

        log_console_output(const log_console_output& ) = delete;
        log_console_output(log_console_output&& ) = delete;

        auto& operator=(const log_console_output& ) = delete;
        auto& operator=(log_console_output&& ) = delete;

        void write(
                log_level level,
                const std::string& context,
                const std::string& msg);
    };
}