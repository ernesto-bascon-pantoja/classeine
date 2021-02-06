#include "classeine/core/string_tools.h"

#include "string_view"

void classeine::core::string_tools::hello_world()
{
    println("Hello world from Classeine.");
}

bool classeine::core::string_tools::starts_with(const std::string& str, const std::string& prefix)
{
    std::string_view sv = str;
    return sv.starts_with(prefix);
}

std::string_view
classeine::core::string_tools::to_safe_string_view(const char *str)
{
    return str == nullptr ? "" : str;
}