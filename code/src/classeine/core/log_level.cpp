#include "classeine/core/log_level.h"

std::string_view
classeine::core::to_string(log_level level)
{
    switch (level)
    {
        case log_level::error:      return "ERROR  ";
        case log_level::warning:    return "WARNING";
        case log_level::info:       return "INFO   ";
        case log_level::debug:      return "DEBUG  ";
    }

    return "UNKNOWN";
}
