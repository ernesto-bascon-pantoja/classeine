#pragma once

#include "log_level.h"
#include "unique_object.h"

#include <string>

namespace classeine::core
{
    struct log_console_output : public unique_object
    {
        void write(
                log_level level,
                const std::string& context,
                const std::string& msg);
    };
}