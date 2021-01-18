#include "classeine/core/log_console_output.h"

#include "classeine/core/string_tools.h"

void
classeine::core::log_console_output::write(
        log_level level,
        const std::string& context,
        const std::string& msg)
{
    using namespace classeine::core::string_tools;

    println(build_string("[", to_string(level), "] (", context, ") ", msg));
}